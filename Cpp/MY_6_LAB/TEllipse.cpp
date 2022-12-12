#include <iostream>
#include <math.h>
using namespace std;


TEllipse::TEllipse(int a1, int b1)
{
    a = a1;
    b = b1;
   
}

TEllipse::TEllipse()
{
    cout<<"Input a :  "<<endl;
    cin>>a;
    cout<<"Input b :  "<<endl;
    cin>>b;
    
}




void TEllipse::print()
{
   cout<< "(x^2 / " << a*a <<") + (y^2 / "<< b*b << ") = 1; " << endl;
}

float TEllipse::get_answer(int x)
{
    float y;
    y = (b*b - (x*x*b*b /(a*a)));
    y = pow(y,0.5);
    return y;   
}