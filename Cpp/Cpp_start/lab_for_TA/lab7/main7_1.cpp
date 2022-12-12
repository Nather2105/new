// Варіант №15

// Прибиральниця тьотя Мотя по вихідних підробляла в астрономічній лабораторії. 
// Якось вона задумала роздивитися у телескоп, що стояв у цій лабораторії, сузір’я, під яким вона народилися.

// До сузір’я тьоті Моті входило N (1≤N≤100) зірок та їх розміщення на небосхилі визначалося координатами (xi,yi),
// де і=1,2,3,…,N. Увімкнувши телескоп, рішуча тьотя Мотя зразу ж зіткнулася з проблемою: вона ніяк не могла навести
// об’єктив телескопу таким чином, щоб охопити всі зірки свого сузір’я.

// Допоможіть тьоті Моті визначити координати центру об’єктива телескопа з точністю 0,001,
// щоб при цьому всі зірки сузір’я оптимальним чином опинилися в її полі зору.

#include <iostream>
#include <fstream>
using std::ifstream;
using namespace std;
#include <cstdlib>


class Star
{
    private:
        int x;
        int y;
    
    public:
        void set(int, int);
        int get_x();
        int get_y();

};

void get_memory_for_array(Star**, int);

Star find_the_answer(Star*, Star*, int);

int main()
{
    Star *stars;
    Star center;
    int i, n, x1, y1;

    cout << "input n:" << endl;

    cin >> n;

    get_memory_for_array(&stars, n);

    for(i = 0; i < n; i++){
        cout << "input x for star #" << i+1 << ":" << endl;
        cin >> x1;
        cout << "input y for star #" << i+1 << ":" << endl;
        cin >> y1;

        stars[i].set(x1, y1);
    }
    find_the_answer(stars, &center, n);

    cout << "center is (" << center.get_x() << ", " << center.get_y() << ")" << endl;
}

void get_memory_for_array(Star** a, int n)
{
    *a = (Star*)malloc(sizeof(Star) * n);
}

void Star::set(int x1, int y1)
{
    x = x1;
    y = y1;
}

int Star::get_x()
{
    return x;
}
int Star::get_y()
{
    return y;
}

Star find_the_answer(Star* a, Star* center, int n)
{
    int i, sum_for_x = 0, sum_for_y = 0;

    for(i = 0; i < n; i++){
        sum_for_x += a[i].get_x();
        sum_for_y += a[i].get_y();
    }

    center->set(sum_for_x / n, sum_for_y / n);

    return *center;
}

