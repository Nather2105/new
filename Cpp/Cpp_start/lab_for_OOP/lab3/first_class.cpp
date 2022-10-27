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
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct rational
{
    int top, bot;
};

typedef struct rational rat;
typedef struct rational *pr;

//отримання даних для структури
void init(pr);

//вписування даних в структуру
void input(int, int, pr);

//вивід структури
void output(rat);

//додавання двох дробів
rat add(rat, rat);

//віднімання двох дробів
rat sub(rat, rat);

//множення
rat mul(rat, rat);

//ділення
rat div(rat, rat);

//скорочення
rat reduce(pr);

//підготовка для виводу
char *toPChar(rat);

//чи перший елемент дорівнює другому
int equ(rat, rat);

//чи перший елемент більший за другий
int bigger(rat, rat);

//чи перший елемент менший за другий
int smaller(rat, rat);

int main()
{
    rat a, b;
    char check = 's';
    init(&a);
    init(&b);
    while(check != 'x'){ //меню
        cout << "a + b  - type 1\n";
        cout << "a - b - type 2\n";
        cout << "a * b - type 3\n";
        cout << "a / b - type 4\n";
        cout << "a eql b? - type 5\n";
        cout << "a > b? - type 6\n";
        cout << "a < b? - type 7\n";
        cout << "to print a - type 8\n";
        cout << "to print b - type 9\n";
        // scanf("%c", &check);
        cin >> check;
        if(check =='1'){
            output(add(a,b));
        }
        else if(check =='2'){
            output(sub(a,b));
        }
        else if(check =='3'){
            output(mul(a,b));
        }
        else if(check =='4'){
            output(div(a,b));
        }
        else if(check =='5'){
            equ(a,b);
        }
        else if(check =='6'){
            bigger(a,b);
        }
        else if(check =='7'){
            smaller(a,b);
        }
        else if(check =='8'){
            output(a);
        }
        else if(check =='9'){
            output(b);
        }
    }
}


rat reduce(rat c)
{
    int min, i, ctop;
    rat d;
    ctop = abs(c.top);

    if (c.bot > ctop)
    {
        min = ctop;
    }
    else if (c.bot < ctop)
    {
        min = c.bot;
    }
    else
    {
        d.bot = 1;
        d.top = 1;
        return d;
    }
    for (i = min; i > 1; i--)
    {
        if (c.bot % i == 0 && ctop % i == 0)
        {
            d.bot = c.bot / i;
            d.top = c.top / i;
            return d;
        }
    }
    d.bot = c.bot;
    d.top = c.top;
    return d;
}

void init(pr a)
{
    int t, b;

    cout << "input top for number" << endl;
    cin >> t;
    cout << "input bot for number" << endl;
    cin >> b;

    input(t, b, a);
    cout << a->top;
}

void input(int t, int b, pr a)
{
    a->top = t;
    a->bot = b;
}

char* toPChar(rat a)
{
    char *str = (char*)malloc(10);
    sprintf(str, "%d\n--\n%d", a.top, a.bot);
    return str;
}

void output(rat a)
{
    cout << toPChar(a) << endl;
}

rat add(rat a, rat b)
{
    rat c;
    if (a.bot == b.bot)
    {
        c.bot = a.bot;
        c.top = a.top + b.top;
    }
    else
    {
        c.top = a.top * b.bot + b.top * a.bot;
        c.bot = a.bot * b.bot;
    }
    c = reduce(c);
    return c;
}

rat sub(rat a, rat b)
{
    rat c;
    if (a.bot == b.bot)
    {
        c.bot = a.bot;
        c.top = a.top - b.top;
    }
    else
    {
        c.top = a.top * b.bot - b.top * a.bot;
        c.bot = a.bot * b.bot;
    }
    c = reduce(c);
    return c;
}

rat mul(rat a, rat b)
{
    rat c;
    c.top = a.top * b.top;
    c.bot = a.bot * b.bot;

    c = reduce(c);
    return c;
}

rat div(rat a, rat b)
{
    rat c;
    c.top = a.top * b.bot;
    c.bot = a.bot * b.top;

    c = reduce(c);
    return c;
}

int equ(rat a, rat b)
{
    if (a.bot == b.bot && a.top == b.top)
    {
        cout << "yeah\n";
        return 1;
    }
    else
    {
        cout << "nope\n";
        return 0;
    }
}

int bigger(rat a, rat b)
{
    rat c = sub(a, b);
    if (c.top < 0)
    {
        cout << "nope\n";
        return 0;
    }
    else
    {
        cout << "yeah\n";
        return 1;
    }
}

int smaller(rat a, rat b)
{
    rat c = sub(a, b);
    if (c.top < 0)
    {
        cout << "yeah\n";
        return 1;
    }
    else
    {
        cout << "nope\n";
        return 0;
    }
}
