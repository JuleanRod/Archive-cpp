#include <iostream>
#include <iomanip>
using namespace std;

struct CorpData
{
CorpData(const char *n, double fi, double se, double th, double fo)
:name(n),first(fi),second(se),third(th),fourth(fo){}
const char *name;
double first;
double second;
double third;
double fourth;
};

void function(const struct CorpData &item)
{
double total;
double avg;
total=item.first+item.second+item.third+item.fourth;
avg=total/4;
cout << "Division name:" << right << setw(12) << item.name << endl;
cout << "Annual Total:" << right << setw(12) << "$" << total << endl;
cout << "Annual Quarterly:" << right << setw(8) << "$" << avg << endl;

}
//main starts here
int main()
{
    struct CorpData West("West",10000, 20000, 30000, 40000);
    struct CorpData East("East",90000, 100000, 110000,0);
    struct CorpData North("North",50000, 60000, 70000, 80000);
    struct CorpData South("South", 120000, 130000, 140000, 150000);

function(West);
function(East);
function(North);
function(South);

return 0;
}

