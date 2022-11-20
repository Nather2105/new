#include <iostream>
#include "MyClass.h"
#include "MyClass.cpp"

using namespace std;
int main()
{
    int n, p = 0, fl = 0;;
    cout << "input n for ob1:\n";
    cin >> n;
    MyClass me(n), me1, me2;
    cout << "input n for ob2:\n";
    cin >> n;
    MyClass iam(n);
    while (p != 20){
        cout << endl;
        cout << "choose your way:" << endl;
        cout << "1 - answer in point x" << endl;
        cout << "2 - pohidna in point x" << endl;
        cout << "3 - answer in point q(x)" << endl;
        cout << "4 - answer in func (x-b)*p(x)" << endl;
        cout << "5 - answer in func p(x+b)" << endl;
        cout << "6 - check how copy func works" << endl;
        cout << "7 - ob1 + ob2" << endl;
        cout << "8 - ob1 - ob2" << endl;
        cout << "9 - ob1 * ob2" << endl;
        cout << "10 - ob1 / ob2" << endl;
        
        cin >> p;

        if(p == 1){
            me.get_the_answer();
        }
        else if(p == 2){
            me.pohidna();
        }
        else if(p == 3){
            me.pqx();
        }
        else if(p == 4){
            me.xbpx();
        }
        else if(p == 5){
            me.pxb();
        }
        else if(p == 6){
            if (fl){
                cout << "you did it before" << endl;
                continue;
            }
            copy(&me1, me);
            me1.print_xs();
            fl = 1;
        }
        else if(p == 7){
            (me + iam).print_xs();
        }
        else if(p == 8){
            (me - iam).print_xs();
        }
        else if(p == 9){
            (me * iam).print_xs();
        }
        else if(p == 10){
            div_mnogo(me, iam);  
        }
    }
}