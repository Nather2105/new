#include <iostream>
#include <math.h>
using namespace std;


THyperbola::THyperbola(int a1, int b1)
{
    a = a1;
    b = b1;
   
}

THyperbola::THyperbola()
{
    cout<<"Input a :  "<<endl;
    cin>>a;
    cout<<"Input b :  "<<endl;
    cin>>b;
    
}




void THyperbola::print()
{
   cout<< "(x^2 / " << a*a <<") - (y^2 / "<< b*b << ") = 1; " << endl; 

}

float THyperbola::get_answer(int x)
{
    float y;
    y =  ((x*x*b*b /(a*a)) - b*b); 
    y = pow(y,0.5);
    return y ;
   
}