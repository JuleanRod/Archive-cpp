#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

class Departments
{
 private:
 int DepartmentID;
 string Departmentname;
 string DepartmentHeadName;
 public:
 Departments(){}
 Departments(int DepNumID,string name,string headName)
{
 DepartmentID = DepNumID;
 Departmentname = name;
 DepartmentHeadName = headName;
}
 string getDepartmentHeadName() const
{
 return DepartmentHeadName;
}
 int getDepartmentID() const
{
 return DepartmentID;
}
 string getDepartmentname() const
{
 return Departmentname;
}
 void setDepartmentHeadName(string DepartmentHeadName)
{
 this->DepartmentHeadName = DepartmentHeadName;
}
 void setDepartmentID(int DepartmentID)
{
 this->DepartmentID = DepartmentID;
}
 void setDepartmentname(string Departmentname)
{
 this->Departmentname = Departmentname;
}
};
class Employee
{
 private:
 int employeeID;
 string emploeename;
 double employeesalary;
 double employeeage;
 int employeeDepartmentID;
 public:
 Employee(){}
 Employee(int id,string name,double salary,double age,int dId)
 {
  employeeID = id;
  emploeename = name;
  employeesalary = salary;
  employeeage = age;
  employeeDepartmentID = dId;
 }
 string getEmploeename() const
 {
  return emploeename;
 }
 int getEmployeeDepartmentID() const
 {
  return employeeDepartmentID;
 }
 int getEmployeeID() const
 {
  return employeeID;
 }
 double getEmployeeage() const
 {
  return employeeage;
 }
 double getEmployeesalary() const
 {
  return employeesalary;
 }
 void setEmploeename(string emploeename)
 {
  this->emploeename = emploeename;
 }
 void setEmployeeDepartmentID(int employeeDepartmentID)
 {
  this->employeeDepartmentID = employeeDepartmentID;
 }
 void setEmployeeID(int employeeID)
 {
  this->employeeID = employeeID;
 }
 void setEmployeeage(double employeeage)
 {
  this->employeeage = employeeage;
 }
 void setEmployeesalary(double employeesalary)
 {
  this->employeesalary = employeesalary;
 }
};

//main starts here!
int main()
{
 Employee employees[5];
 Departments departments[3];
 int numOfDepartment = 0;
 int numOfEmployees = 0;
 int choice = 0;
 while(choice != 6)
    {
     cout<<"1. Create Department"
     "\n2. Create Employee"
     "\n3. Write Out Data File"
     "\n4. Read In Data File"
     "\n5. Display Salary Report"
     "\n6. -- Quit -- "
     "\nPlease make a selection : ";
     cin>>choice;
     if(choice == 1)
     {
      if(numOfDepartment == 3)
      {
       cout<<"\nThe array is full, you can not add any more Departments."<<endl;
       continue;
      }
      int dId;
      string dName;
      string dHeadName;
      cout<<"Please Enter Department Details:"<<endl;
      cout<<"Department ID : ";
      cin>>dId;
      bool validId = true;
      for(int i=0;i<numOfDepartment;i++)
      {
       if(departments[i].getDepartmentID()==dId)
       {
        cout<<"Value must be unique!"<<endl;
        validId=false;
       }
      }
      if(!validId)
      {
       continue;
      }
      cout<<"Department Name : ";
      cin>>dName;
      cout<<"Head of Department : ";
      cin>>dHeadName;
      Departments d(dId,dName,dHeadName);
      departments[numOfDepartment] = d;
      numOfDepartment++;
     }else if(choice == 2)
      {
       if(numOfEmployees == 5)
       {
        cout<<"The array is full, you can not add any more Employees."<<endl;
        continue;
       }
       int empID;
       string empName;
       double empSalary;
       double empAge;
       int eDepartmentid;
       cout<<"Please Enter Employee Details:"<<endl;
       cout<<"Employee ID : ";
       cin>>empID;
       bool validId=true;
       for(int i=0;i<numOfEmployees;i++)
       {
        if(employees[i].getEmployeeID()==empID)
        {
         cout<<"Value must be unique!"<<endl;
         validId=false;
        }
       }
       if(!validId)
       {
        continue;
       }
       cout<<"Employee Name :";
       cin>>empName;
       cout<<"Salary: $";
       cin>>empSalary;
       cout<<"Age : ";
       cin>>empAge;
       cout<<"Department ID : ";
       cin>>eDepartmentid;
      bool foundId = false;
       while(!foundId)
       {
        for(int i=0;i<numOfDepartment;i++)
        {
         if(departments[i].getDepartmentID()==eDepartmentid)
         {
          foundId = true;
          break;
         }
        }
         if(!foundId)
         {
          cout<<"Please enter a valid department ID: ";
          cin>>eDepartmentid;
         }
       }
       Employee e(empID,empName,empSalary,empAge,eDepartmentid);
       employees[numOfEmployees] = e;
       numOfEmployees++;
      }else if(choice == 3)
      {
       ofstream myfile1 ("departments.txt");
       ofstream myfile2 ("employees.txt");
       for(int i=0;i<numOfDepartment;i++)
       {
        myfile1<<departments[i].getDepartmentID()<<" "<<departments[i].getDepartmentname()<<" "<<departments[i].getDepartmentHeadName()<<endl;
       }
       for(int i=0;i<numOfEmployees;i++)
       {
        myfile2<<employees[i].getEmployeeID()<<" "<<employees[i].getEmploeename()<<" "<<employees[i].getEmployeesalary()<<
        " "<<employees[i].getEmployeeage()<<" "<<employees[i].getEmployeeDepartmentID()<<endl;
       }
       myfile1.close();
       myfile2.close();
      }else if(choice == 4)
      {//read departments
       ifstream infile;
       string line;//for read line
       int dId;
       string dName;
       string dHeadName;
       numOfDepartment = 0;
       infile.open ("departments.txt");     //name of file here. pls mention Complete \\path if file is not at root
       if (infile.is_open())                //if file opened
       {
        while( getline(infile, line,'\n') ) //get row from text file
        {
         stringstream ss(line);
         ss>>dId>>dName>>dHeadName;
         Departments d(dId,dName,dHeadName);
         departments[numOfDepartment] = d;
         numOfDepartment++;
        }
        infile.close();         //close file
       }
       else     //if file not found show the below message
       {
         cout << "Sorry, we could not find the equation file." << endl;
       }
       //read employees
       ifstream infile2;
       int empID;
       string empName;
       double empSalary;
       double empAge;
       int eDepartmentid;
       numOfEmployees = 0;
       infile2.open ("employees.txt");      //name of file here. pls mention complete \\path if file is not at root
       if (infile2.is_open())       //if file opened
       {
        while( getline(infile2, line,'\n') ) //get row from text file
        {
         stringstream ss(line);
         ss>>empID>>empName>>empSalary>>empAge>>eDepartmentid;
         Employee e(empID,empName,empSalary,empAge,eDepartmentid);
         employees[numOfEmployees] = e;
         numOfEmployees++;
        }
        infile2.close();     //close file
       }
       else        //if file not found show the below message
       {
       cout << "Sorry, we could not find the equation file." << endl;
       }
      }
      else if(choice == 5)
      {
       cout<<"\nSalary Report By Department \n";
       string name = "";
       double salary = 0;
       for(int i=0;i<numOfDepartment;i++)
       {
        salary = 0;
        name = departments[i].getDepartmentname();
        for(int j=0;j<numOfEmployees;j++)
        {
         if(departments[i].getDepartmentID() == employees[j].getEmployeeDepartmentID() )
         {
          salary += employees[j].getEmployeesalary();
         }
        }
        cout<<"\nDept         : "<<name<<endl;
        cout<<"Total Salary : $"<<salary <<endl;
       }
      }else if(choice != 6)
      {
       cout<<"Please enter a valid choice (1 - 6): ";
       cin>>choice;
      }
    }
 cout<<"Thank you, goodbye.";
 return 0;
}
 
