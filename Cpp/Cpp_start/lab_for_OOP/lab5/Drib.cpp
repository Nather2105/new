#include <iostream>
using namespace std;
#include <math.h>


void Drib::print_drib()
{
    top->print_xs();
    cout << endl;
    cout << endl;
    bot->print_xs();
}
void operator<<(ostream& os, Drib& a)
{
    a.top->print_xs();
    cout << endl;
    cout << endl;
    a.bot->print_xs();
}
Drib::Drib(int n1, int n2)
{
    top = (MyClass*)malloc(sizeof(MyClass));
    bot = (MyClass*)malloc(sizeof(MyClass));
    int i;
    top->set_n(n1);
    // top->set_arr();
    bot->set_n(n2);
    // bot->set_arr();

    top->input(n1);
    bot->input(n2);
    print_drib();

}

Drib::Drib() {}

Drib::~Drib()
{
    delete[] top;
    delete[] bot;
}

float Drib::get_the_answer(float x)
{
    float sum_of_top;
    float sum_of_bot;
    sum_of_top = top->get_the_answer(x);
    sum_of_bot = bot->get_the_answer(x);

    return sum_of_top / sum_of_bot;
}

Drib& Drib::pohidna()
{
    top->pohidna();
    bot->pohidna();

    return *this;
} 
void Drib::copy_for_drib(Drib& drib2)
{
    int i;
    top->set_n(drib2.top->get_n());
    top->set_arr();
    
    cout << top->get_n() << endl;
    for(i = 0; i <= top->get_n(); i++){
        top->set_part_of_arr(drib2.top->get_part_of_arr(i), i);
        cout << top->get_part_of_arr(i) << endl;
    }
    
    bot->set_n(drib2.bot->get_n());
    bot->set_arr();
    
    cout << top->get_n() << endl;
    for(i = 0; i <= bot->get_n(); i++){
        bot->set_part_of_arr(drib2.bot->get_part_of_arr(i), i);
        cout << bot->get_part_of_arr(i) << endl;
    }
}
void Drib::pow_for_drib(int st)
{
    // int max_inde
    // max_index = st * n;
    int i;
    
    for(i = 1; i < st; i++){
        (*top) * (*top);
        (*bot) * (*bot);
        
    }
        // top->print_xs();
        // cout << endl;
        // bot->print_xs();

    return;
}

Drib& Drib::operator+(Drib& a)
{
    (*top) * (*a.bot);
    (*a.top) * (*bot);
    (*bot) * (*a.bot);
    (*top) + (*a.top);

    return *this;

}

Drib& Drib::operator-(Drib& a)
{
    (*top) * (*a.bot);
    (*a.top) * (*bot);
    (*bot) * (*a.bot);
    (*top) - (*a.top);

    return *this;
}

Drib& Drib::operator*(Drib& a)
{
    (*top) * (*a.top);
    (*bot) * (*a.bot);

    return *this;
}
