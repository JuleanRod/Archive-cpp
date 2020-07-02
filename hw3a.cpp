#include <iostream>
using namespace std;

int main()
{
    string name1, name2, name3;
    int time1 = 0;
    int time2 = 0;
    int time3 = 0;

    cout << "Enter runner's name: ";
    cin >> name1;
    cout << "Enter runner's time: ";
    cin >> time1;

    cout << "Enter next runner's name: ";
    cin >> name2;
    cout << "Enter next runner's time: ";
    cin >> time2;

    cout << "Enter next runner's name: ";
    cin >> name3;
    cout << "Enter next runner's time: ";
    cin >> time3;

    if ((time1 < 0) || (time2 < 0) || (time3 < 0))
    {
        cout << "Please only enter positive numbers for runner's time." << endl;
        cout << "Please restart program" << endl;
    }

    else if ((time1 < time2) && (time1 < time3))
    {
       cout << "First Place  : " << name1 << " " << time1 << endl;
        if(time2 < time3)
        {
            cout << "Second Place : " << name2 << " " << time2 << endl;
            cout << "Third Place  : " << name3 << " " << time3 << endl;
        }

        else if(time3 < time2)
        {
            cout << "Second Place : " << name3 << " " << time3 << endl;
            cout << "Third Place  : " << name2 << " " << time2 << endl;
        }
    }

    else if ((time2 < time1) && (time2 < time3))
    {
        cout << "First Place  : " << name2 << " " << time2 << endl;
        if (time1 < time3)
        {
            cout << "Second Place : " << name1 << " " << time1 << endl;
            cout << "Third Place  : " << name3 << " " << time3 << endl;
        }

        else if (time3 < time1)
        {
            cout << "Second Place : " << name3 << " " << time3 << endl;
            cout << "Third Place  : " << name1 << " " << time1 << endl;
        }

    }

    else if ((time3 < time1) && (time3 < time2))
    {
        cout << "First Place  : " << name3 << " " << time3 << endl;
        if (time1 < time2)
        {
            cout << "Second Place : " << name1 << " " << time1 << endl;
            cout << "Third Place  : " << name2 << " " << time2 << endl;
        }
        else if (time2 < time1)
        {
            cout << "Second Place : " << name2 << " " << time2 << endl;
            cout << "Third Place  : " << name1 << " " << time1 << endl;
        }
    }

    return 0;
}
