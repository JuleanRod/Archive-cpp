#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Payroll
{
private:
	double hrs;                               //hrs= hours
	double pr;                                //pr=payrate
	double gp;                                //gp=grosspay

public:
	Payroll()
	{
		hrs = 0.0;
		pr = 0.0;
		gp = 0.0;

	}

	Payroll(double h, double p)
	{
		hrs = h;
		pr = p;
		gp = hrs * pr;
	}

	void sethrs(double h)
	{
		hrs = h;
	}

	void setpr(double p)
	{
		pr = p;
	}

	double gethrs()
	{
		return hrs;
	}

	double getpr()
	{
		return pr;
	}

	double getgp()
	{
		return gp;
	}

};

const int employees = 7;

int main()
{

	int index;

	ifstream datafile("payroll.dat");

	if (!datafile.is_open()) {
		cout << "Error opening data file \n";
		return 0;
	}

	for (index = 0; index < 7; index++)
	{
		double hrs;
		double pr;

		datafile >> hrs;
		datafile >> pr;

		Payroll payrolls(hrs, pr);

		cout << endl;
		cout << fixed << setprecision(2);
		cout << "Employee" << setw(2) << (index + 1) << ": "
			<< payrolls.getgp() << endl;
	}


	datafile.close();


	return 0;
}

