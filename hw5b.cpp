#include <iostream>
#include <iomanip>
using namespace std;

double tCharges(int, double, double, double);        //tcharges = totalCharges
double tCharges(double, double);
void validateInput(double &);
void validateInput(int &);

int main()
{
  //variables
  char patient;
  int days;
  double rate,
         services,
         medication,
         total;


  cout << "Do you want to calculate the total hospital bill for " << endl;
  cout << "(I) an In-Patient, or " << endl;
  cout << "(O) an Out-Patient?";
  cin >> patient;
  while (patient != 'I' && patient != 'O')
  {
    cout << " Enter I or O: " << endl;
    cin >> patient;
  }
  
  

  //Switch statement that receives and validates input
  switch(patient)
  {
    case 'I': cout << "How many days were spent in the hospital? ";
            cin >> days;
            validateInput(days);
            cout << "What is the hospital daily rate? $";
            cin >> rate;
            validateInput(rate);
            cout << "What were the charges for hospital services (lab tests, etc.)? $";
            cin >> services;
            validateInput(services);
            cout << "What were the hospital medication charges? $" << endl;
            cin >> medication;
            validateInput(medication);
            total = tCharges(days, rate, services, medication);
            break;
    case 'O': cout << "What were the charges for hospital services (lab tests, etc.)? $";
            cin >> services;
            validateInput(services);
            cout << "What were the hospital medication charges? $" << endl;
            cin >> medication;
            validateInput(medication);
            total = tCharges(services, medication);
            break;
  }

 

  //Switch statement which displays results 
  switch(patient)
  {
    case 'I': cout << "Total Hospital Charges: $" << fixed << setprecision(2) << total;
            break;
    
    case 'O': cout << "Total Hospital Charges: $" << fixed << setprecision(2) << total;
            break;
  }
}

double tCharges(int days, double dailyRate, double services, double meds)
{
  return (days * dailyRate) + services + meds;
}

double tCharges(double services, double meds)
{
  return services + meds;
}

void validateInput(double &value)
{
  while(value < 0)
  {
    cout << "Number must be a positive number : ";
    cin >> value;
  }
}

void validateInput(int &value)
{
  while(value < 0)
  {
    cout << "Number must be a positive number : ";
    cin >> value;
  }
}
