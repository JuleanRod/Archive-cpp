#include <iostream>
using namespace std;

int main()
{
    double candybars, organization, total;

    cout << "Please enter the number of candy bars sold :" <<endl;
    cin >> candybars;

    cout << "what is the amount the organization earns for each candy bar sold? :" <<endl;
    cin >> organization;

    total = (candybars * organization);
    cout << "The total amount earned " << total;

    return 0;
}
