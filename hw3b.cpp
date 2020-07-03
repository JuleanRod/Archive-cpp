#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    float h1, h2, h3;                           //h = height
    string name, date1, date2, date3;

    cout << "Enter pole vaulters's name: ";
    cin >> name;
    cout << "Enter date MMDD: ";
    cin >> date1;
    cout << "Enter height in meters: ";
    cin >> h1;

    cout << "Enter next date MMDD: ";
    cin >> date2;
    cout << "Enter height in meters: ";
    cin >> h2;

    cout << "Enter next date MMDD: ";
    cin >> date3;
    cout << "Enter height in meters: ";
    cin >> h3;

    if ((h1 < 2.0) || (h1 > 5) || (h2 < 2.0) || (h2 > 5.0) || (h3 < 2.0) || (h3 > 5.0))
    {
        cout << "Name: " << name << endl;
        cout << "Please enter valid heights only, between 2.0 and 5.0" << endl;
    }

    else if ((h1 > h2) && (h1 > h3) && (h2 > h3))
    {
        cout << "Name: " << name << endl;
        cout << "First Place  : " << setw(4) << fixed << setprecision(2) << h1 << "   " << "date: " << date1 << endl;
        cout << "Second Place : " << setw(4) << fixed << setprecision(2) << h2 << "   " << "date: " << date2 << endl;
        cout << "Third Place  : " << setw(4) << fixed << setprecision(2) << h3 << "   " << "date: " << date3;
    }
    
    else if ((h1 > h2) && (h1 > h3) && (h3 > h2))
    {
        cout << "Name: " << name << endl;
        cout << "First Place  : " << setw(4) << fixed << setprecision(2) << h1 << "   " << "date: " << date1 << endl;
        cout << "Second Place : " << setw(4) << fixed << setprecision(2) << h3 << "   " << "date: " << date3 << endl;
        cout << "Third Place  : " << setw(4) << fixed << setprecision(2) << h2 << "   " << "date: " << date2;
    }
        
    else if ((h2 > h1) && (h2 > h3) && (h1 > h3))
    {
        cout << "Name: " << name << endl;
        cout << "First Place  : " << setw(4) << fixed << setprecision(2) << h2 << "   " << "date: " << date2 << endl;
        cout << "Second Place : " << setw(4) << fixed << setprecision(2) << h1 << "   " << "date: " << date1 << endl;
        cout << "Third Place  : " << setw(4) << fixed << setprecision(2) << h3 << "   " << "date: " << date3;
    }    
    
    else if ((h2 > h3) && (h2 > h1) && (h3 > h1))
    {
        cout << "Name: " << name << endl;
        cout << "First Place  : " << setw(4) << fixed << setprecision(2) << h2 << "   " << "date: " << date2 << endl;
        cout << "Second Place : " << setw(4) << fixed << setprecision(2) << h3 << "   " << "date: " << date3 << endl;
        cout << "Third Place  : " << setw(4) << fixed << setprecision(2) << h1 << "   " << "date: " << date1;
    }
    
    else if ((h3 > h1) && (h3 > h2) && (h1 > h2))
    {
        cout << "Name: " << name << endl;
        cout << "First Place  : " << setw(4) << fixed << setprecision(2) << h3 << "   " << "date: " << date3 << endl;
        cout << "Second Place : " << setw(4) << fixed << setprecision(2) << h1 << "   " << "date: " << date1 << endl;
        cout << "Third Place  : " << setw(4) << fixed << setprecision(2) << h2 << "   " << "date: " << date2;
    }
   
    else if ((h3 > h1) && (h3 > h2) && (h2 > h1))
    {
        cout << "Name: " << name << endl;
        cout << "First Place  : " << setw(4) << fixed << setprecision(2) << h3 << "   " << "date: " << date3 << endl;
        cout << "Second Place : " << setw(4) << fixed << setprecision(2) << h2 << "   " << "date: " << date2 << endl;
        cout << "Third Place  : " << setw(4) << fixed << setprecision(2) << h1 << "   " << "date: " << date1;
    }
   
    return 0;
}

