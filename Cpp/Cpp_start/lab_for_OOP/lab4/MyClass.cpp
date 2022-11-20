#include <iostream>
using namespace std;
#include <math.h>

float *input(int n)
{
    int i;
    float *arr1;
    arr1 = (float *)malloc(sizeof(float) * n + 1);
    for (i = 0; i <= n; i++)
    {
        cout << "input kef for x**" << i << endl;
        cin >> arr1[i];
    }
    return arr1;
};

MyClass::MyClass(int n1)
{
    n = n1;
    arr = input(n);
    print_xs();
};
MyClass::MyClass(){};

MyClass::~MyClass()
{
    delete[] arr;
};

void MyClass::print_xs()
{

    cout << "\nn equal to " << n << endl;
    cout << arr[0] << "x(" << 0 << ")";
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= 0)
        {
            cout << "+" << arr[i] << "x(" << i << ")";
        }
        else
        {
            cout << arr[i] << "x(" << i << ")";
        }
    }
}

void MyClass::get_the_answer()
{
    float x, sum;
    int i;
    cout << "input x:" << endl;
    cin >> x;
    sum = 0;
    for (i = n; i >= 0; i--)
    {
        sum += (arr[i]) * pow(x, i);
    }
    cout << "answer is " << sum << endl;
}
void MyClass::pohidna()
{
    float x, sum, step;
    int i;
    cout << "input x:" << endl;
    cin >> x;
    sum = 0;
    for (i = 1; i <= n; i++)
    {
        step = i * arr[i] * pow(x, i - 1);
        sum += step;
    }
    cout << "pohidna is " << sum << endl;
}

void MyClass::pqx()
{
    // q(x)= x(1/2)
    int i;
    float x, sum;
    cout << "input for p(q(x)) q(x) = x(1/2) :" << endl;
    cin >> x;

    if (x < 0)
    {
        cout << "error! x must be more than 0" << endl;
        return;
    }

    x = pow(x, 0.5);

    sum = 0;
    for (i = 0; i <= n; i++)
    {
        sum += (arr[i]) * pow(x, i);
    }
    cout << "answer is " << sum << endl;
}

void MyClass::xbpx()
{
    int i;
    float x, b, sum;
    cout << "input x for (x-b)*p(x):" << endl;
    cin >> x;
    cout << "input b for (x-b)*p(x):" << endl;
    cin >> b;

    sum = 0;
    for (i = 0; i <= n; i++)
    {
        sum += (arr[i]) * pow(x, i);
    }
    sum *= x - b;
    cout << "answer is " << sum << endl;
}

void MyClass::pxb()
{
    int i;
    float x, b, sum;
    cout << "input x for p(x+b):" << endl;
    cin >> x;
    cout << "input b for p(x+b):" << endl;
    cin >> b;

    x += b;
    sum = 0;
    for (i = 0; i <= n; i++)
    {
        sum += (arr[i]) * pow(x, i);
    }
    cout << "answer is " << sum << endl;
}

MyClass copy(MyClass *a, MyClass b)
{
    int i;
    a->n = b.n;
    (a->arr) = (float *)malloc(sizeof(float) * (b.n + 1));

    for (i = 0; i <= b.n; i++)
    {
        a->arr[i] = b.arr[i];
    }
    return *a;
}

MyClass operator+(MyClass a, MyClass b)
{
    MyClass c;
    int i, min1;
    c.n = a.n >= b.n ? a.n : b.n;
    min1 = a.n <= b.n ? a.n : b.n;
    c.arr = (float *)malloc(sizeof(float) * (c.n + 1));
    for (i = 0; i <= min1; i++)
    {
        cout << a.arr[i] << endl;
        cout << b.arr[i] << endl;
        c.arr[i] = a.arr[i] + b.arr[i];
        cout << c.arr[i] << endl;
    }

    if (a.n > b.n)
    {
        for (i = min1 + 1; i <= c.n; i++)
        {
            c.arr[i] = a.arr[i];
        }
    }
    else if (b.n > a.n)
    {
        for (i = min1 + 1; i <= c.n; i++)
        {
            c.arr[i] = b.arr[i];
        }
    }
    return c;
}

MyClass operator-(MyClass a, MyClass b)
{
    MyClass c;
    int i, min1;
    c.n = a.n >= b.n ? a.n : b.n;
    min1 = a.n <= b.n ? a.n : b.n;
    c.arr = (float *)malloc(sizeof(float) * (c.n + 1));
    for (i = 0; i <= min1; i++)
    {
        c.arr[i] = a.arr[i] - b.arr[i];
    }

    if (a.n > b.n)
    {
        for (i = min1 + 1; i <= c.n; i++)
        {
            c.arr[i] = a.arr[i];
        }
    }
    else if (b.n > a.n)
    {
        for (i = min1 + 1; i <= c.n; i++)
        {
            c.arr[i] = b.arr[i];
        }
    }
    return c;
}

MyClass operator*(MyClass a, MyClass b)
{
    int max_index, i, j;
    float point;
    MyClass c;
    max_index = a.n + b.n;
    c.n = max_index;
    c.arr = (float *)malloc(sizeof(float) * (max_index + 1));

    for (i = 0; i <= max_index; i++)
    {
        c.arr[i] = 0;
    }

    for (i = 0; i <= a.n; i++)
    {
        for (j = 0; j <= b.n; j++)
        {
            cout << a.arr[i] * b.arr[j] << endl;
            point = a.arr[i] * b.arr[j];
            c.arr[i + j] += point;
            cout << c.arr[i + j];
        }
    }

    return c;
}

MyClass div_mnogo(MyClass a, MyClass b)
{
    MyClass c;
    int i, j, z, step, k;
    float kef;

    if (a.n < b.n)
    {
        cout << "error" << endl;
        return NULL;
    }

    // c = (MyClass* )malloc(sizeof(MyClass) * 2);

    c.n = a.n;
    c.arr = (float *)malloc(sizeof(float) * (c.n + 1)); // частка
    // d.arr = (float *)malloc(sizeof(float) * (c.n + 1)); // остача

    for (i = 0; i <= c.n; i++)
    {
        c.arr[i] = 0;
    }

    for (i = 0, j = a.n, k = b.n; i <= a.n - b.n; i++, j--)
    {
        if(a.arr[j] == 0){
            continue;
        }
        kef = a.arr[j] / b.arr[k];
        cout << a.arr[j] << endl;
        cout << b.arr[k] << endl;
        step = j - k;
        cout << kef << endl;
        cout << step << endl;
        c.arr[step] = kef;
        for (z = b.n; z >= 0; z--)
        {
            a.arr[z + step] -=   b.arr[z] * kef;
        }
    }
        c.print_xs(); 
        a.print_xs(); 
    return c;
}