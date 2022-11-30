#include <iostream>
using namespace std;

TTime::TTime(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}

TTime::TTime()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}
void TTime::increase_first()
{
    hours += 1;
    if(hours == 24){
        hours = 0;
    }
}

void TTime::increase_second()
{
    minutes += 1;
    if(minutes == 60){
        minutes = 0;
        increase_first();
    }
}

void TTime::increase_third()
{
    seconds += 1;
    if(seconds == 60){
        seconds = 0;
        increase_second();
    }
}

void TTime::triple_print()
{
    cout << "Time is: " << hours << ":" << minutes << ":" << seconds << endl;
}