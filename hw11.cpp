#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

typedef struct inventory
{
    //Inventory structure
    char desc[50], date[10];
    int qty;
    float wCost, rCost;
} I;

void openFile(fstream &f)
{
    //Function to open file inventory.dat
    f.open("inventory.dat", ios::out|ios::in|ios::binary);
    if(f.fail())
    {
        //If file failed to open
        f.open("inventory.dat", ios::out|ios::in | ios::binary| ios::trunc);
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

void add(fstream &f)
{
    //Function to add new record to file
    I item;
    f.clear();//To clear the state back to good
    f.seekp(0,ios::end);//To move file pointer to end to append
    cin.ignore();
    cout<<"Enter the NEW Record Data:";
    cout<<"\nDesciption: ";
    cin.getline(item.desc, 50);
    cout<<"Quantity: ";
    cin>>item.qty;
    cout<<"Wholesale Price: $";
    cin>>item.wCost;
    cout<<"Retail Price: $";
    cin>>item.rCost;
    cin.ignore();
    cout<<"Date Added: ";
    cin.getline(item.date, 10);
    cout<<"\n";
    f.write((char *)&item, sizeof(item));//Write content of struct inventory to file
}

void display(fstream & f)
{
    //Function to display selected record
    I item;
    f.clear();//To clear the state back to good
    f.seekg(0,ios::beg);//To move file pointer to beginning
    int n = 0;
    while(f.read((char *)&item, sizeof(item)))//Read whole file for number of records
        n++;
    if(n == 0)
    {
        //Empty file
        cout<<"\nNo record found. File empty";
        return;
    }
    else
    {
        //File is not empty
        cout<<"Which Record to DISPLAY:";
        cout<<"\nPlease choose one of the following... 1 to "<<n<<" : ";
        cin>>n;//Now n is used to store record number to display
        f.clear();//To clear the state back to good
        f.seekg(0,ios::beg);//To move file pointer to beginning
        int i = 0;
        while(f.read((char *)&item, sizeof(item)))
        {
            //Read each record and check if i == n
            i++;
            if(i == n)
            {
                //If i == n then print that record and return

                cout<<"Description: "<<item.desc;
                cout<<"\nQuantity: "<<item.qty;
                cout<<fixed<<setprecision(2);
                cout<<"\nWholesale Price: $"<<item.wCost;
                cout<<"\nRetail Price: $"<<item.rCost;
                cout<<"\nDate: "<<item.date;
                cout<<"\n"<<endl;
                return;
            }

        }
    }
}

void displaymodify(fstream & f)
{
    //Function to display selected record and modify option
    I item;
    f.clear();//To clear the state back to good
    f.seekg(0,ios::beg);//To move file pointer to beginning
    fstream o("temp.dat", ios::binary | ios::out);//Used to store modified records
    int n = 0;
    while(f.read((char *)&item, sizeof(item)))//Read whole file for number of records
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
        cout<<"Which record to MODIFY:";
        cout<<"\nPlease choose one of the following... 1 to "<<n<<" : ";
        cin>>n;//Now n is used to store record number to display
        f.clear();//To clear the state back to good
        f.seekg(0,ios::beg);//To move file pointer to beginning
        int i = 0;
        while(f.read((char *)&item, sizeof(item)))
        {
            //Read each record and check if i == n
            i++;
            if(i == n)
            {
                //If i == n then print that record and return
                cout<<"Description: "<<item.desc;
                cout<<"\nQuantity: "<<item.qty;
                cout<<"\nWholesale Price: $"<<item.wCost;
                cout<<"\nRetail Price: $"<<item.rCost;
                cout<<"\nDate: "<<item.date;
                cin.ignore();
               cout<<"\nEnter MODIFY Data:"<<endl;
                cout<<"Desciption: ";
                cin.getline(item.desc, 50);
                cout<<"Quantity: ";
                cin>>item.qty;
                cout<<fixed<<setprecision(2);
                cout<<"Wholesale Price: $";
                cin>>item.wCost;
                cout<<"Retail Price: $";
                cin>>item.rCost;
                cin.ignore();
                cout<<"Date Added: ";
                cin.getline(item.date, 10);
                cout<<"\n";
            }o.write((char *)&item, sizeof(item));//Write to temp.dat

        }
    }//Close both files
    f.close();
    o.close();
    remove("inventory.dat");//Remove inventory.data
    rename("temp.dat", "inventory.dat");//temp.data contain modified record and now has been renamed to inventory.dat
}
//main starts here
int main()
{
    //Driver function
    fstream f;
    openFile(f);//Function to open file
    int option;
    do
    {
        cout<<"Inventory Program Menu";
        cout<<"\n  1. ADD NEW Record";
        cout<<"\n  2. DISPLAY Record";
        cout<<"\n  3. MODIFY Record";
        cout<<"\n  4. EXIT Program";
        cout<<"\nplease enter selection (1 - 4) : ";
        cin>>option;
        switch(option)
        {
            case 1: add(f);break;
            case 2: display(f);break;
            case 3://display records && Modify file records
            displaymodify(f);
            //close file
            f.close();
            openFile(f);//Open file again
            break;
            case 4: break;
            default: cout<<"Please enter a valid choice (1 - 4): ";
            cin>>option;
        }
    }while(option != 4);
    cout<<"Thank you!";
    f.close();
    return 0;
}
 
