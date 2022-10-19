// Варіант 12
// Раціональний (нескоротний) дріб задається парою цілих чисел (a, b), де a – чисельник, b – знаменник. 
//Реалізувати тип TRational для роботи з раціональними дробами. Обов’язково повинні бути реалізовані операції:
// додавання add(), (a, b) + (c, d);
// віднімання sub(), (a, b) – (c, d);
// множення mul(), (a, b) * (c, d);
// ділення div(), (a, b) / (c, d);
// порівняння equ(), bigger(), smaller().
// Повинна бути реалізована приватна функція скорочення дробу reduce(), яка обов’язково викликається при виконанні арифметичних операцій.

#include <iostream>
#include <cstdlib>
using namespace std;

struct rational
{
    int top, bot;
};

typedef struct rational rat;
typedef struct rational *pr;

void init(pr, pr);

void input(int, int, int, int, pr, pr);

void output(rat);

rat add(rat, rat);

rat sub(rat, rat);

rat mul(rat, rat);

rat div(rat, rat);

rat reduce(rat);

char* toPChar(rat);

int equ(rat, rat);

int bigger(rat, rat);

int smaller(rat, rat);


int main()
{
    rat a, b;
    init(&a, &b);
    output(a);

}

void init(pr a, pr b)
{
    int t1, t2, b1, b2;

    cout << "input top for number 1" << endl;
    cin >> t1;
    cout << "input bot for number 1" << endl;
    cin >> b1;
    
    cout << "input top for number 2" << endl;
    cin >> t2;
    cout << "input bot for number 2" << endl;
    cin >> b2;

    input(t1, b1, t2, b2, a, b);
}

void input(int t1, int b1, int t2, int b2, pr a, pr b)
{
    a->top = t1;
    a->bot = b1;
    b->top = t2;
    b->bot = b2;
}

char* toPChar(rat a)
{
    char* t;
    char* b;
    itoa(a.top, t, 10);
    itoa(a.bot, b, 10);
    return 'q'; 
}

void output(rat a)
{
    printf("%s", toPChar(a));
}

rat add(rat, rat);

rat sub(rat, rat);

rat mul(rat, rat);

rat div(rat, rat);

rat reduce(rat);

int equ(rat, rat);

int bigger(rat, rat);

int smaller(rat, rat);

