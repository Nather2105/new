#include <iostream>
#include "MyClass.h"
#include "MyClass.cpp"
#include "Drib.h"
#include "Drib.cpp"

using namespace std;

int main()
{
    int n1, n2, p = 0, fl = 0, st;
    Drib drib3;
    cout << "input n for top of ob1:\n";
    cin >> n1;
    cout << "input n for bot of ob1:\n";
    cin >> n2;
    Drib drib1(n1, n2);
    cout << "\ninput n for top of ob2:\n";
    cin >> n1;
    cout << "input n for bot of ob2:\n";
    cin >> n2;
    Drib drib2(n1, n2);

    cout << endl;
    cout << "\n1choose your way:" << endl;
    cout << "1 - answer in point x for ob1" << endl;
    cout << "2 - pohidna for ob2" << endl;
    cout << "3 - check how copy func works" << endl;
    cout << "4 - ob1 + ob2" << endl;
    cout << "5 - ob1 - ob2" << endl;
    cout << "6 - ob1 * ob2" << endl;
    cout << "7 - ob1^x" << endl;
    while (p != 20){
        
        cin >> p;

        if(p == 1){
            float x;
            cout << "input x:" << endl;
            cin >> x;
            cout << "answer is " << drib1.get_the_answer(x);
        }
        else if(p == 2){
            drib2.pohidna();
            // drib2.print_drib();
            cout << drib2;
        }
        else if(p == 3){
            if (fl){
                cout << "you did it before" << endl;
                continue;
            }
            drib2.copy_for_drib(drib1);
            // drib2.print_drib();
            cout << drib2;
            fl = 1;
        }
        else if(p == 4){
            drib1.print_drib();
            cout << "\n\n\n";
            drib2.print_drib();
            (drib1 + drib2).print_drib();
        }
        else if(p == 5){
            drib1.print_drib();
            cout << "\n\n\n";
            drib2.print_drib();
            cout << "\n";
            (drib1 - drib2).print_drib();
        }
        else if(p == 6){
            drib1.print_drib();
            cout << "\n\n\n";
            drib2.print_drib();
            cout << "\n";
            (drib1 * drib2).print_drib();
        }
        else if(p == 7){
            cout << "input step for ob1:" << endl;
            cin >> st;
            drib1.pow_for_drib(st);
            cout << drib1;

        }
    }
}