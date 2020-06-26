#include <iostream>
using namespace std;

int main() 
{
	const double YEN_PER_DOLLAR = 105.64;
	const double EURO_PER_DOLLAR = .80;
	double amount_YEN, amount_EURO, amount_DOLL;
	cout << "Currency Conversion Machine\n";
	cout << "Enter amount in US Dollars: $";
	cin >> amount_DOLL;

	amount_YEN = YEN_PER_DOLLAR * amount_DOLL;
	amount_EURO = EURO_PER_DOLLAR * amount_DOLL;

	cout << "Your amount in YEN: " << amount_YEN << endl;
	cout << "Your amount in EURO: " << amount_EURO << endl;
}
