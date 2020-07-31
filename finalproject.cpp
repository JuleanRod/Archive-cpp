#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

const int DEPT_SIZE = 100, MAX_EMPLOYEE = 100;
const int ID_SIZE = 100, NAME_SIZE = 100;

typedef struct Department
{
    //department structure
    char depID[DEPT_SIZE];
    char depName[NAME_SIZE];
    char depHeadName[NAME_SIZE];
    char depTotalSalary[];

} d;
typedef struct Employee
{
    //employee structure
    char employeeID[ID_SIZE];
    char employeeName[NAME_SIZE];
    double employeeSalary;
    int employeeAge;
    char employeeDepID[ID_SIZE];
} e;
void openFileDep(fstream &f)
{
    //Function to open file departments.dat
    f.open("departments.dat", ios::out|ios::in|ios::binary);
    if(f.fail())
    {
        //If file failed to open
        f.open("departments.dat", ios::out|ios::in | ios::binary| ios::trunc);
        if(f.fail())
        {
        //If file failed to open
        cout << "Error opening file....";
        exit(0);
        }
        else
        return;
    }
    else
        return;
}
void openFileEmp(fstream & a)
{
    //Function to open file employees.dat
    a.open("employees.dat", ios::out|ios::in|ios::binary);
    if(a.fail())
    {
        //If file failed to open
        a.open("employees.dat", ios::out|ios::in | ios::binary| ios::trunc);
        if(a.fail())
        {
        //If file failed to open
        cout << "Error opening file....";
        exit(0);
        }
        else
        return;
    }
    else
        return;
}
void add_newdep(fstream &f)

{
  //Function to add new record to file

  d dep, dep2;

  f.clear();  //To clear the state back to good

  f.seekg(0, ios::beg);  //To move file pointer to end to append

  cin.ignore();

  cout << "Enter the NEW Department Data:";

  cout << "\nDept ID: ";
  cin.getline(dep.depID, ID_SIZE);

  int n = 0;
  while (f.read((char *)&dep2, sizeof(dep2)))  //Read whole file for number of records
    n++;
  if (n != 0) {
    f.clear();
    f.seekg(0, ios::beg);
    bool flag = 0;
    while (f.read((char *)&dep2, sizeof(dep2))) {
      if (strcmp(dep.depID, dep2.depID) == 0) {
        flag = 1;
        break;
      }
    }
    while (flag) {
      cout << "Please enter a unique Deptartment ID: ";
      cin.getline(dep.depID, ID_SIZE);
      while (f.read((char *)&dep2, sizeof(dep2))) {
        if (strcmp(dep.depID, dep2.depID) == 0) {
          flag = 1;
          break;
        }
      }
      flag = 0;
    }
  }
  cout << "Dept Name: ";

  cin.getline(dep.depName, NAME_SIZE);

  cout << "Head of Dept Name: ";

  cin.getline(dep.depHeadName, NAME_SIZE);

  cout << "\n";

  f.clear();
  f.seekp(0, ios::end);                //To move file pointer to end to append
  f.write((char *)&dep, sizeof(dep));  //Write content of structure department to file
  f.close();
}
void add_newemp(fstream &f, fstream &a) {
  //Function to add new record to file

  d dep;
  e emp, emp2;

  a.clear();  //To clear the state back to good

  a.seekg(0, ios::beg);  //To move file pointer to end to append

  cin.ignore();

  cout << "Enter the NEW Employee Data:";

  cout << "\nEmployee ID: ";

  cin.getline(emp.employeeID, ID_SIZE);

  int n = 0;
  while (a.read((char *)&emp2, sizeof(emp2)))  //Read whole file for number of records
    n++;
  if (n != 0) {
    a.clear();
    a.seekg(0, ios::beg);
    bool flag = 0;
    while (a.read((char *)&emp2, sizeof(emp2))) {
      if (strcmp(emp.employeeID, emp2.employeeID) == 0) {
        flag = 1;
        break;
      }
    }
    while (flag) {
      cout << "Please enter a unique Employee ID: ";
      cin.getline(emp.employeeID, ID_SIZE);
      a.clear();
      a.seekg(0, ios::beg);
      while (a.read((char *)&emp2, sizeof(emp2))) {
        if (strcmp(emp.employeeID, emp2.employeeID) == 0) {
          flag = 1;
          break;
        }
      }
      flag = 0;
    }
  }

  cout << "Employee Name: ";

  cin.getline(emp.employeeName, NAME_SIZE);

  cout << "Employee Salary: $";

  cin >> emp.employeeSalary;

  cin.ignore();  //?

  cout << "Employee Age: ";

  cin >> emp.employeeAge;
  cin.ignore();
  cout < "Department ID: ";
  cin.getline(emp.employeeDepID, ID_SIZE);

  f.clear();
  f.seekg(0, ios::beg);

  n = 0;
  while (f.read((char *)&dep, sizeof(dep)))
    n++;
  if (n == 0) {
    cout << "No Department Exsist.\n";
    return;
  } else {
    f.clear();
    f.seekg(0, ios::beg);
    bool flag = 1;
    while (f.read((char *)&dep, sizeof(dep))) {
      if (strcmp(emp.employeeDepID, dep.depID) == 0) {
        flag = 0;
        break;
      }
    }
    while (flag) {
      cout << "Please enter an existing Deptartment ID: ";
      cin.getline(emp.employeeDepID, ID_SIZE);
      f.clear();
      f.seekg(0, ios::beg);
      while (f.read((char *)&dep, sizeof(dep))) {
        if (strcmp(emp.employeeDepID, dep.depID) == 0) {
          flag = 0;
          break;
        }
      }
    }
  }
  cout << "\n";
  a.clear();
  a.seekp(0, ios::end);                //To move file pointer to end to append
  a.write((char *)&emp, sizeof(emp));  //Write content of struct employee to file
  a.close();
  f.clear();
  f.close();
}

void displaymodifyDep(fstream & f)
{
    //Function to display selected record and modify option
    d dep;
    f.clear();//To clear the state back to good
    f.seekg(0,ios::beg);//To move file pointer to beginning
    fstream o("temp.dat", ios::binary | ios::out);//Used to store modified records
    int n = 0;
    while(f.read((char *)&dep, sizeof(dep)))//Read whole file for number of records
        n++;
    if(n == 0)
    {
        //File is empty
        cout<<"\nNo record found. File empty";
        return;
    }
    else
    {
        //File is not empty
        cout<<"Which record to EDIT:";
        cout<<"\nPlease choose one of the following... 1 to "<<n<<" : ";
        cin>>n;//Now n is used to store record number to display
        f.clear();//To clear the state back to good
        f.seekg(0,ios::beg);//To move file pointer to beginning
        int i = 0;
        while(f.read((char *)&dep, sizeof(dep)))
        {
            //Read each record and check if i == n
            i++;
            if(i == n)
            {
                //If i == n then print that record and return
                cout<<"\nDisplay Department Details:";
                cout<<"\nDept ID     : "<<dep.depID;                     // need to SET SPACES
                cout<<"\nDept Name   : "<<dep.depName;
                cout<<"\nDept Head   : "<<dep.depHeadName<<endl;
                cin.ignore();
                cout<<"\nEDIT the Department Data:"<<endl;
                cout<<"Dept Name: ";
                cin.getline(dep.depName, NAME_SIZE);
                cout<<"Head of Dept Name: ";
                cin.getline(dep.depHeadName, NAME_SIZE);
                cout<<"\n";
            }o.write((char *)&dep, sizeof(dep));//Write to temp.dat

        }
    }//Close both files
    f.close();
    o.close();
    remove("departments.dat");//Remove inventory.data
    rename("temp.dat", "departments.dat");//temp.data contain modified record and now has been renamed to departments.dat
}
void displaymodifyEmp(fstream & a)
{
    //Function to display selected record and modify option
    e emp;
    a.clear();//To clear the state back to good
    a.seekg(0,ios::beg);//To move file pointer to beginning
    fstream o("temp.dat", ios::binary | ios::out);//Used to store modified records
    int n = 0;
    while(a.read((char *)&emp, sizeof(emp)))//Read whole file for number of records
        n++;
    if(n == 0)
    {
        //File is empty
        cout<<"\nNo record found. File empty";
        return;
    }
    else
    {
        //File is not empty
        cout<<"Which record to EDIT:";
        cout<<"\nPlease choose one of the following... 1 to "<<n<<" : ";
        cin>>n;//Now n is used to store record number to display
        a.clear();//To clear the state back to good
        a.seekg(0,ios::beg);//To move file pointer to beginning
        int i = 0;
        while(a.read((char *)&emp, sizeof(emp)))
        {
            //Read each record and check if i == n
            i++;
            if(i == n)
           {
                //If i == n then print that record and return
                cout<<"\nDisplay Employee Details:";
                cout<<"\nID     : "<<emp.employeeID;
                cout<<"\nName   : "<<emp.employeeName;
                cout<<"\nSalary : $"<<emp.employeeSalary;
                cout<<"\nAge    : "<<emp.employeeAge;
                cout<<"\nDept   : "<<emp.employeeDepID<<endl;
                cin.ignore();
                cout<<"\nEdit the Employee Data:"<<endl;
                cout<<"Employee Name: ";
                cin.getline(emp.employeeName, NAME_SIZE);
                cout<<"Employee Salary: $";
                cin>>emp.employeeSalary;
                cin.ignore();
                cout<<"Employee Age: ";
                cin>>emp.employeeAge;
                cout<<"Department ID: ";
                cin>>emp.employeeDepID;
                cout<<"\n";
            }o.write((char *)&emp, sizeof(emp));//Write to temp.dat

        }
    }//Close both files
    a.close();
    o.close();
    remove("employees.dat");//Remove inventory.data
    rename("temp.dat", "employees.dat");//temp.data contain modified record and now has been renamed to employees.dat
}

void displayreport(fstream & f, fstream & a)
{
    int n=0;
    d dep;
    e emp;
    f.clear();
    f.seekg(0,ios::beg);
    cout<<"\nSalary Report By Department\n\n";
    while(f.read((char *)&dep, sizeof(dep)))
        n++;
    if(n == 0)
    {
        //File is empty
        cout<<"\nNo record found. File empty\n";
        return;
    } else {
        f.clear();//To clear the state back to good
        f.seekg(0,ios::beg);//To move file pointer to beginning
        int i = 0;
        while(f.read((char *)&dep, sizeof(dep))){
            if(f.eof()){//if reaches end of file, break
                break;
            }
            double totaldepsalary = 0.0;
            a.clear();
            a.seekg(0,ios::beg);
            n=0;
            while(a.read((char *)&emp, sizeof(emp)))
                n++;

            if( n == 0 )
            {
                //File is empty
                cout<<"\nNo record found. File empty \n";
                return;
            } else {
                a.clear();
                a.seekg(0,ios::beg);
                while(a.read((char *)&emp, sizeof(emp))){
                    if(a.eof()){
                        break;
                    }
                    if(strcmp(dep.depID, emp.employeeDepID)==0){
                        totaldepsalary += emp.employeeSalary;
                    }
                }
                cout<<"Dept         : " <<dep.depName;
                cout<<"\nTotal Salary : $"<<totaldepsalary<<"\n\n";
            }
        }
    }

}

//main starts here!
int main()
{
    //Driver function
    fstream f, a;

    openFileDep(f);//Function to open file
    openFileEmp(a);
    int option;
    do
    {
        cout<<"Human Resources Menu";
        cout<<"\n1. Create Department";
        cout<<"\n2. Create Employee";
        cout<<"\n3. Edit Department";
        cout<<"\n4. Edit Employee";
        cout<<"\n5. Display Salary Report";
        cout<<"\n6. -- Quit -- ";
        cout<<"\nPlease make a selection : ";
        cin>>option;
        switch(option)
        {
            case 1: add_newdep(f); f.close(); openFileDep(f); break;
            case 2: add_newemp(f, a); f.close(); a.close(); openFileDep(f); openFileEmp(a); break;
            case 3://display records && Modify file records
            displaymodifyDep(f);
            //close file
            f.close();
            openFileDep(f);//Open file again
            break;
            case 4://display records && Modify file records
            displaymodifyEmp(a);
            //close file
            a.close();
            openFileEmp(a);//Open file again
            break;
            case 5: displayreport(f, a); break;
            case 6: break;
            default: cout<<"Please enter a valid choice (1 - 6): ";
            cin>>option;
        }
    }while(option != 6);
    remove("employees.dat");
    remove("departments.dat");
    cout<<"\nThank you, goodbye.";
    f.close();
    return 0;
}
