#include <iostream>
using namespace std;

int main()
{
	string moviename;
	double adulttickets, childtickets, gross_profit, net_profit, distributor;
	const double adult_price = 6.00, child_price = 3.00;

	cout << "How many ADULT tickets sold: ";
	cin >> adulttickets;
	cout << "How many CHILD tickets sold: ";
	cin >> childtickets;
	cout << "Movie Name: ";
	cin >> moviename;

	gross_profit = (adulttickets * adult_price) + (childtickets * child_price);
	distributor = gross_profit * .8;
	net_profit = gross_profit - distributor;

	cout << "Adult Tickets Sold: " << adulttickets << endl;
	cout << "\n";
	cout << "Child Tickets Sold: " << childtickets << endl;
	cout << "\n";
	cout << "Gross Box Office Profit: $" << gross_profit << endl;
	cout << "\n";
	cout << "Amount Paid to Distributor: $" << distributor << endl;
	cout << "\n";
	cout << "Net Box Office Profit: $" << net_profit << endl;
	cout << "\n";

	return 0;
}
