// Варіант 12
// Раціональний (нескоротний) дріб задається парою цілих чисел (a, b), де a – чисельник, b – знаменник.
//Реалізувати тип TRational для роботи з раціональними дробами. Обов’язково повинні бути реалізовані операції:
// додавання add(), (a, b) + (c, d);
// віднімання sub(), (a, b) – (c, d);
// множення mul(), (a, b) * (c, d);
// ділення div(), (a, b) / (c, d);
// порівняння equ(), bigger(), smaller().
// Повинна бути реалізована приватна функція скорочення дробу reduce(), яка обов’язково викликається при виконанні арифметичних операцій.
// тип даних задається класом. Член-даних класу – одна приватна змінна структурного типу, який описаний у п.1, 
// члени-функції класу – відкриті неоператорні функції init(), input(), output(), toPChar() і функції доступу до
// приватної змінної setStruct(), getStruct() або до окремих полів  приватної змінної setVar(), getVar().
// Функції, зазначені в конкретному варіанті, визначити як звичайні сторонні функції (доступ для до приватної
// частини класу в цих функціях відбувається за допомогою функцій доступу).
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// typedef struct rational rat;
// typedef struct rational *pr;

class TRational
{
    private:
        struct rational
        {
            int top, bot;
        }drib;

    public:
        void init(int t, int b)
        {
            drib.top = t;
            drib.bot = b;
        }
        void input()
        {
            int t, b;

            cout << "input top for number" << endl;
            cin >> t;
            cout << "input bot for number" << endl;
            cin >> b;

            init(t, b);
        }
        char* toPChar()
        {
            char *str = (char*)malloc(10);
            sprintf(str, "%d\n--\n%d", drib.top, drib.bot);
            return str;
        }
        void output()
        {
            printf("%s\n", toPChar());
        }
        rational getStruct()
        {
            return drib;
        }
        void setTop(int a)
        {
            drib.top = a;
        }
        int getTop()
        {
            return drib.top;
        }
        void setBot(int a)
        {
            drib.bot = a;
        }
        int getBot()
        {
            return drib.bot;
        }
};

//додавання двох дробів
void add(TRational, TRational);

//віднімання двох дробів
TRational sub(TRational, TRational);

//множення
void mul(TRational, TRational);

//ділення
void div(TRational, TRational);

//скорочення
void reduce(TRational*);

//чи перший елемент дорівнює другому
void equ(TRational, TRational);

//чи перший елемент більший за другий
void bigger(TRational, TRational);

//чи перший елемент менший за другий
void smaller(TRational, TRational);

int main()
{
    // rat a, b;
    TRational a, b;
    char check = 's';

    a.input();
    b.input();

    while(check != 'x'){ //меню
        printf("a + b  - type 1\n");
        printf("a - b - type 2\n");
        printf("a * b - type 3\n");
        printf("a / b - type 4\n");
        printf("a eql b? - type 5\n");
        printf("a > b? - type 6\n");
        printf("a < b? - type 7\n");
        printf("to print a - type 8\n");
        printf("to print b - type 9\n");
        scanf("%c", &check);
        if(check =='1'){
            add(a, b);
        }
        else if(check =='2'){
            sub(a, b);
        }
        else if(check =='3'){
            mul(a, b);
        }
        else if(check =='4'){
            div(a, b);
        }
        else if(check =='5'){
            equ(a, b);
        }
        else if(check =='6'){
            bigger(a, b);
        }
        else if(check =='7'){
            smaller(a, b);
        }
        else if(check =='8'){
            a.output();
        }
        else if(check =='9'){
            b.output();
        }
    }
}


void reduce(TRational* c)
{
    int min, i, ctop;
    ctop = abs(c->getTop());
    
    if (c->getStruct().bot > ctop)
    {
        min = ctop;
    }
    else if (c->getStruct().bot < ctop)
    {
        min = c->getBot();
    }
    else
    {
        c->setBot(1);
        c->setTop(1);
        return;
    }
    for (i = min; i > 0; i--)
    {
        if (c->getBot() % i == 0 && ctop % i == 0)
        {
            c->setBot(c->getBot() / i);
            c->setTop(c->getTop() / i);
            return;
        }
    }
}

void add(TRational a, TRational b)
{
    TRational c;
    if (a.getBot() == b.getBot())
    {
        c.setBot(a.getBot());
        c.setTop(a.getTop() + b.getTop());
    }
    else
    {
        c.setTop(a.getTop() * b.getBot() + b.getTop() * a.getBot());
        c.setBot(a.getBot() * b.getBot());
    }
    reduce(&c);
    c.output();
}

TRational sub(TRational a, TRational b)
{
    TRational c;
    if (a.getBot() == b.getBot())
    {
        c.setBot(a.getBot());
        c.setTop(a.getTop() - b.getTop());
    }
    else
    {
        c.setTop(a.getTop() * b.getBot() - b.getTop() * a.getBot());
        c.setBot(a.getBot() * b.getBot());
    }
    reduce(&c);
    c.output();
    return c;
}

void mul(TRational a, TRational b)
{
    TRational c;
    c.setTop(a.getTop() * b.getTop());
    c.setBot(a.getBot() * b.getBot());

    reduce(&c);
    c.output();
}

void div(TRational a, TRational b)
{
    TRational c;
    c.setTop(a.getTop() * b.getBot());
    c.setBot(a.getBot() * b.getTop());

    reduce(&c);
    c.output();
}

void equ(TRational a, TRational b)
{
    if (a.getBot() == b.getBot() && a.getTop() == b.getTop())
    {
        printf("yeah\n");
        return;
    }
    else
    {
        printf("nope\n");
        return;
    }
}

void bigger(TRational a,TRational b)
{
    TRational c = sub(a, b);
    if (c.getTop() < 0)
    {
        printf("nope\n");
        return;
    }
    else
    {
        printf("yeah\n");
        return;
    }
}

void smaller(TRational a, TRational b)
{
    TRational c = sub(a, b);
    if (c.getTop() < 0)
    {
        printf("yeah\n");
        return;
    }
    else
    {
        printf("nope\n");
        return;
    }
}
