// 25 варіант
// Число з околом задається полями  first і second (дійсні числа, які визначають відповідно число та його окіл).
// Реалізувати методи isDiapazon(ob1,ob2), якій перевіряє, чи попадає одне число з околом в окіл іншого числа з околом,
// distanceTwo(ob1,ob2) – мінімальну відстань між двома об’єктами (їх границями).
#include <stdio.h>
#include <stdlib.h>

// структура із двох дійсніх чисел(число і його окіл)
struct point_and_field
{
    float first, second;
};

// тайпдеф для зручності(вказівник на структуру)
typedef struct point_and_field *ppaf;

// тайпдеф для скорочення назви структури
typedef struct point_and_field paf;

//заповнення структури
void input(ppaf, int);

//вивід структури
void output(paf, paf);

int check(ppaf);

// виконання умови "Реалізувати метод isDiapazon(ob1,ob2), який перевіряє,
// чи попадає одне число з околом в окіл іншого числа з околом"
int isDiapazon(paf, paf);

//виконання умови "distanceTwo(ob1,ob2) – мінімальна відстань між двома об’єктами (їх границями)"
float distanceTwo(paf, paf);

int main()
{
    paf ob1, ob2;   //оголошення через тайпдеф
    input(&ob1, 1); //заповнення об1
    input(&ob2, 2); //заповнення об2

    //вивід двох об'єктів
    output(ob1, ob2);

}

void input(ppaf ob, int i)
{
    while (1)
    {
        printf("put a number of ob%d:", i);
        scanf("%f", &ob->first);
        printf("put a field of number ob%d:", i);
        scanf("%f", &ob->second);
        if (check(ob) == 0)
        {
            printf("field must be more than 0\n");
            continue;
        }
        return;
    }
}

void output(paf ob1, paf ob2)
{

    printf("info abount ob1:\n");
    printf("first = %.2f \nsecond = %.2f\n", ob1.first, ob1.second);
    printf("lower limit is %.2f\n", ob1.first - ob1.second);
    printf("higher limit is %.2f\n", ob1.first + ob1.second);

    printf("info abount ob2:\n");
    printf("first = %.2f \nsecond = %.2f\n", ob2.first, ob2.second);
    printf("lower limit is %.2f\n", ob2.first - ob2.second);
    printf("higher limit is %.2f\n", ob2.first + ob2.second);

    // головна ідея задачі: якщо існує спільна ділянка для двох наших об'єктів, то це означає що
    // відстані між нашими полями немає, так як вони пересікаються, або також можна сказати, що вони з'єднані
    // якщо відповідь до першого методу "так", друга функція не виконується, а точніше, її відповідь = 0
    if (isDiapazon(ob1, ob2))
    {
        printf("yeah, ob1 and ob2 have a common field\n");
        printf("distance between them is 0, because they have the common field");
    }
    else // якщо ж два наші об'єкти немають спільного околу, це означає що вони не є з'єднаними, отже, між ними є дистанція
    {
        printf("ob1 and ob2 dont have a common field.\n");
        printf("distance between ob1 and ob2 is %.2f\n", distanceTwo(ob1, ob2));
    }
}

int check(ppaf ob)
{
    if (ob->second <= 0)
    {
        return 0;
    }
    return 1;
}
// головна схема завдання: порівнюємо точки і віднімаємо від нижньої межі більшого об'єкту верхню межу меншого
// якщо відповідь <= 0, то точки мають спільне поле
// якщо відповідь > 0, то точки мають між собою певну дистанцію
int isDiapazon(paf ob1, paf ob2)
{
    float lower_limit_of_higher_ob, higher_limit_of_lower_ob;
    paf lower, higher;
    if (ob1.first > ob2.first)
    {
        higher = ob1;
        lower = ob2;
    }
    else if (ob1.first < ob2.first)
    {
        higher = ob2;
        lower = ob1;
    }
    else
    {
        return 1;
    }

    lower_limit_of_higher_ob = higher.first - higher.second;
    higher_limit_of_lower_ob = lower.first + lower.second;
    if (lower_limit_of_higher_ob - higher_limit_of_lower_ob <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float distanceTwo(paf ob1, paf ob2)
{
    float lower_limit_of_higher_ob, higher_limit_of_lower_ob;
    paf lower, higher;
    if (ob1.first > ob2.first)
    {
        higher = ob1;
        lower = ob2;
    }
    else if (ob1.first < ob2.first)
    {
        higher = ob2;
        lower = ob1;
    }
    lower_limit_of_higher_ob = higher.first - higher.second;
    higher_limit_of_lower_ob = lower.first + lower.second;
    return lower_limit_of_higher_ob - higher_limit_of_lower_ob;
}
