#include <iostream>
#include <iomanip>
using namespace std;

class Inventory
{
private:
    int iN,                          //iN=itemNumber
        quantity;
    double cost;
public:

    Inventory()
    {
        iN = 0;
        quantity = 0;
        cost = 0;
    }

    Inventory(int i, int q, double c)
    {
        setiN(i);
        setQuantity(q);
        setCost(c);
    }

    void setiN(int i)
    {
        iN = i;
    }


    void setQuantity(int q)
    {
        quantity = q;
    }

    void setCost(double c)
    {
        cost = c;
    }

    int getiN()
    {
        return iN;
    }
    int getQuantity()
    {
        return quantity;
    }


    double getCost()
    {
        return cost;
    }

    double getTotalCost()
    {
        return quantity * cost;
    }
};

// main starts here
int main()
{

    int    item,
        quantity;
    double cost;

    cout << "Enter data for the new item" << endl;
    cout << "Item number: ";
    cin >> item;

    while (item < 0)
    {
        cout << "Error item number must be greater than zero: " << endl;
        cout << "Item number: ";
        cin >> item;
    };

    cout << "Quantity: ";
    cin >> quantity;

    while (quantity < 0)
    {
        cout << "Value must be greater than zero: ";
        cin >> quantity;

    };

    cout << "Price: ";
    cin >> cost;
    while (cost < 0)
    {
        cout << "Value must be greater than zero: ";
        cin >> cost;
    };

    Inventory part1;
    int i = 1234;
    int q = 10;
    double p = 2.5;
    Inventory part2(i, q, p);
    Inventory inv1(item, quantity, cost);


    cout << "Part Number : " << part1.getiN() << endl;
    cout << "Units On Hand : " << part1.getQuantity() << endl;
    cout << "Price : $" << fixed << setprecision(2) << part1.getCost() << endl;
    cout << "Total Cost : $" << part1.getTotalCost() << endl << endl;

    cout << "Part Number : " << part2.getiN() << endl;
    cout << "Units On Hand : " << part2.getQuantity() << endl;
    cout << "Price : $" << part2.getCost() << endl;
    cout << "Total Cost : $" << part2.getTotalCost() << endl << endl;

    cout << "Part Number : " << inv1.getiN() << endl;
    cout << "Units On Hand : " << inv1.getQuantity() << endl;
    cout << "Price : $" << inv1.getCost() << endl;
    cout << "Total Cost : $" << inv1.getTotalCost() << endl;

return 0;
}

