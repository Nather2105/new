// Група:           Прізвище:                                 Варіант 11
// Створити клас параметри руху (час (хв), швидкість руху (м/хв)). Створити конструктори і деструктор. Для виведення інформації про об'єкт визначити дружній оператор <<,
//  а для введення – член-функцію input().
// Визначити оператори:
// •  «<=» - порівняння двох пройдених відстаней (дружній оператор);
// •  «/» - зменшення швидкості на половину (оператор-член класу).
// Визначити функції:
// •  збільшення відстані на задане число, для цього змінити час руху (дружня функція);
// •  обчислення пройденої відстані в метрах (функція-член класу).
// Написати функцію main(), в якій створити об'єкти класу і викликати всі створені оператори та функції. Тіла функцій розміщати за межами інтерфейсної частини класу.

// Код програми
#include <iostream>
using namespace std;
class Movement
{
    private:
// приватні члени дані класу
        float time;
        float speed;
    public:
        // конструктори(тільки заголовки)
        Movement(float, float);
        Movement();
        // деструктор
        ~Movement();

        // прототипи членів класу: функції та оператори
        // input() - введення об'єкта
        void input(); //done
        //  «/» - зменшення швидкості на половину 
        float speeddiv(); //done
        //  обчислення пройденої відстані в метрах 
        float range(); //done
        // прототипи дружніх операторів і функцій
        // оператор <<
        friend void operator<<(ostream&, Movement&); //done
        //  «<=» - порівняння двох пройдених відстаней 
        friend int operator<=(Movement&, Movement&);
        //  збільшення відстані на задане число, для цього змінити час руху 
        friend float increase(float, Movement&);





};

// тіла конструкторів і деструктора
Movement::Movement(float a, float b)
{
    time = a;
    speed = b;
}
Movement::Movement()
    {
        time = 0;
        speed = 0;
    }
// деструктор
Movement::~Movement() {}

// прототипи членів класу: функції та оператори
// input() - введення об'єкта
void Movement::input()
{
    cout << "input time: " << endl;
    cin >> time;
    cout << "input speed: " << endl;
    cin >> speed;
}
//  «/» - зменшення швидкості на половину 
float Movement::speeddiv()
{
    return speed /= 2;
}
//  обчислення пройденої відстані в метрах 
float Movement::range()
{
    return speed * time;
}
// прототипи дружніх операторів і функцій
// оператор <<
void operator<<(ostream& os, Movement& a)
{
    cout << "speed is " << a.speed << endl;
    cout << "time is " << a.time << endl;
    cout << "range is " << a.range() << endl;    
}
//  «<=» - порівняння двох пройдених відстаней 
int operator<=(Movement& a, Movement& b)
{
    if(a.range() <= b.range()){
        return 1;
    }
    else{
        return 0;
    }
}
//  збільшення відстані на задане число, для цього змінити час руху 
float increase(float a, Movement& b)
{
    b.time = (b.range() + a) / b.speed;
    return b.time;
}

int main(){

    float a;
    float b;

    cout << "input time for ob1:" << endl;
    cin >> a;
    cout << "input speed for ob1:" << endl;
    cin >> b;
    Movement ob1(a, b);
    Movement ob2;

    ob2.input();
    ob1.speeddiv();
    cout << ob1;
    cout << endl;
    cout << ob2;
    
    if(ob1 <= ob2){
        cout << "ob2 >= ob1" << endl;
    }
    else{
        cout << "ob1 >= ob2" << endl;
    }
    cout << endl;
    increase(5, ob2);
    cout << "how increase works:" << endl;
    cout << ob2;

    return 0;
    
}