#include <iostream>
#include "TFunction.h"
#include "TFunction.cpp"
#include "THyperbola.h"
#include "THyperbola.cpp"
#include "TEllipse.h"
#include "TEllipse.cpp"


using namespace std;

int main()
{
   TEllipse el(1,2);
   el.print();
   cout<<"Y(1) = "<< el.get_answer(1) << endl;

   
}