#include <iostream>
using namespace std;
int main()
{
    double start , 
    tD = 0 ,           //tD = totalDeposits
    tW = 0 ,           //tW = totalWithdraws
    tI = 0 ;           //tI = totalInterest
int dA;                //dA = depositAmount
int wA;                //wA = withdrawAmount
int sB;                //sB = startBalance
double fB;             //fB = finalBalance
double tB;             //tB = totalBalance
double annIR;          //annIR = annInterestRate
double mIR;            //mIR = monthInterestRate
double mIA;            //mIA = monthInterestAmount
double mAB;            //mAB = monthAverageBalance
double mAA;            //mAA = monthAverageAmount
int count;
cout << "What is your starting balance? "<<endl;
cin >> tB;
start = tB ;
cout << "What is your annual rate? "<<endl; 
cin >> annIR;
for (count = 1; count <= 3; count++)
{
 cout << "Enter total amount deposited for the month #"<< count << endl;
 cin >> dA;
 while (dA < 0)
 {
 cout << "Error, no negative amounts, please try again." << endl;
 cin >> dA;
 }
 tD = tD + dA ;
 cout << "Enter total amount withdrawn for the month #"<< count << endl;
 cin >> wA;
 while (wA < 0 || wA > (tB+dA))
 {
 cout << "Error, no negative amounts or withdrawals greater than your balance. Please try again" << endl;
 cin >> wA;
 }
 tW = tW + wA ;
 sB = tB + dA;
 fB = sB - wA;
 tB = fB;
 mIR = annIR / 12/100;
 mAB = (sB + fB) / 2;
 mIA = mAB * mIR;
 tI = tI + mIA ;
 tB = mIA + tB;
}
cout << "Your starting balance at the beginning of three months " << start << endl;
cout << "Total deposits over three months " << tD << endl;
cout << "Total withdrawals over three months " << tW << endl;
cout << "Total interest posted to account over three months " << tI << endl;
cout << "Final Balance: $" << tB ;
return 0;
}


