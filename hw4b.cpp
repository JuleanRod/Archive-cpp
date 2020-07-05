#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	int i = 0;
	double sum = 0, average, amount;
	string startM, endM;                            // M = month
	ifstream inputFile;
	inputFile.open("Rainfall.txt");

	inputFile >> startM;
	inputFile >> endM;
	inputFile >> amount;

	while (inputFile) 
	{
		sum += amount;
		i++;
		inputFile >> amount;
	}
	
	average = sum / i;

	cout << fixed << setprecision(2) << "During the months of " << startM << "-" << endM << " the total rainfall was " << sum << " inches and the average monthly rainfall was " << average << " inches.\n";
	cout << endl;
	inputFile.close();


	return 0;
}

