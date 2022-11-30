#include <iostream>
using namespace std;

TTriad::TTriad(int f, int s, int t)
{
    first = f;
    second = s;
    third = t;
}

TTriad::TTriad()
{
    first = 0;
    second = 0;
    third = 0;
}
void TTriad::increase_first()
{
    first += 1;
}

void TTriad::increase_second()
{
    second += 1;
}

void TTriad::increase_third()
{
    third += 1;
}

void TTriad::triple_print()
{
    cout << "first is: " << first << endl;
    cout << "second is: " << second << endl;
    cout << "third is: " << third << endl;
}