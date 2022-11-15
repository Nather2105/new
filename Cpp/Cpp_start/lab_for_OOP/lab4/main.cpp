#include <iostream>
#include "MyClass.h"
#include "MyClass.cpp"

using namespace std;
int main()
{

    MyClass me;
    me.i = 5;
    me.print_int();
}