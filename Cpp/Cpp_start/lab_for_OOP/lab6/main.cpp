#include <iostream>
#include "TTriad.h"
#include "TTriad.cpp"
#include "TTime.h"
#include "TTime.cpp"
#include "TDate.h"
#include "TDate.cpp"

using namespace std;

int main()
{
    TTriad t(1,2,3);
    t.increase_first();
    t.increase_first();
    t.increase_first();
    t.increase_second();
    t.increase_second();
    t.increase_third();

    t.triple_print();

    TTime time(23, 59, 59);
    time.increase_third();
    time.triple_print();
    time.increase_first();
    time.increase_second();
    time.triple_print();
    time.triple_print();

    TDate date(28, 11, 2022);
    date.increase_first();
    date.triple_print();
    date.increase_second();
    date.triple_print();
    date.increase_first();
    date.increase_first();
    date.triple_print();
}