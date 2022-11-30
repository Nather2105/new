#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

TDate::TDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

TDate::TDate()
{
    day = 1;
    month = 1;
    year = 1;
}
void TDate::increase_first()
{
    day += 1;
    if(day == 31){
        day = 1;
        increase_second();
    }
}

void TDate::increase_second()
{
    month += 1;
    if(month == 13){
        month = 1;
        increase_third();
    }
}

void TDate::increase_third()
{
    year += 1;
}

void TDate::triple_print()
{
    cout << "Date is: " << day << "." << month << "." << year << endl;
}