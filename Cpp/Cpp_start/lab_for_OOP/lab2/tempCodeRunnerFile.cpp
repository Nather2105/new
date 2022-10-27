// Варіант 1
//  Створити функцію, яка на вхід одержує текст (тип char*) і перетворює його:
//  відкидає повторні пробіли. Функція повинна повертати кількість відкинутих пробілів. 
//  Текст передавати у функцію по посиланню. Перезавантажити операцію "<<" виведення перетвореного рядка,
//  в якій викликати створену функцію.


#include <iostream>
#include <cstring>

using namespace std;

struct str_counter
{
    char str1[100];
    int counter;
};
typedef struct str_counter sc;
ostream& operator <<(ostream& cout, sc& s);

int fix(char* s);

int main()
{
    sc s;
    cout << "input a string" << endl;
    fgets(s.str1, 100, stdin);
    cout<<(s);
    
}

int fix(char* s)
{
    int i, n, counter = 0;
    
    n = strlen(s);
    for (i = 0; i < n; i++) {
        if (s[i] == ' ' && s[i + 1] == ' '){
            counter++;
            continue;
        }
        // printf("%c", s[i]);
        cout << s[i];
    }
    return counter;
}
ostream& operator <<(ostream& cout, sc& s)
{

    s.counter = fix(s.str1);
    cout << "count of useless spaces is " << s.counter;
    return cout;
}