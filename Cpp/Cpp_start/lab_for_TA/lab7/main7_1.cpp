// Варіант №15

// Прибиральниця тьотя Мотя по вихідних підробляла в астрономічній лабораторії. 
// Якось вона задумала роздивитися у телескоп, що стояв у цій лабораторії, сузір’я, під яким вона народилися.

// До сузір’я тьоті Моті входило N (1≤N≤100) зірок та їх розміщення на небосхилі визначалося координатами (xi,yi),
// де і=1,2,3,…,N. Увімкнувши телескоп, рішуча тьотя Мотя зразу ж зіткнулася з проблемою: вона ніяк не могла навести
// об’єктив телескопу таким чином, щоб охопити всі зірки свого сузір’я.

// Допоможіть тьоті Моті визначити координати центру об’єктива телескопа з точністю 0,001,
// щоб при цьому всі зірки сузір’я оптимальним чином опинилися в її полі зору.

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;


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

Star nextToTop(stack<Star>& S);

void swap(Star& p1, Star& p2);

void convexHull(Star *stars, int);

int distSq(Star p1, Star p2);

int orientation(Star p, Star q, Star r);

int compare(const void*, const void*);

Star find_the_answer(Star*, Star*, int);

int main()
{
    Star *stars, *obolonka;
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

Star nextToTop(stack<Star>& S)
{
    Star p = S.top();
    S.pop();
    Star res = S.top();
    S.push(p);
    return res;
}

void swap(Star& p1, Star& p2)
{
    Star temp = p1;
    p1 = p2;
    p2 = temp;
}


int distSq(Star p1, Star p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  
    return (val > 0) ? 1 : 2; 
}

int compare(const void* vp1, const void* vp2)
{
    Star* p1 = (Star*)vp1;
    Star* p2 = (Star*)vp2;


    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void convexHull(Point points[], int n)
{

    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        if ((y < ymin) || (ymin == y &&
            points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);

    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    int m = 1; 
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i],
            points[i + 1]) == 0)
            i++;


        points[m] = points[i];
        m++;
    }

    if (m < 3) return;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    vector <Point> path;
    double suma = 0;
    
    while (!S.empty())
    {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        path.push_back(p);
        S.pop();
    }
    for (int i = 0; i < path.size() - 1; i++) {
        double p = sqrt(pow(path[i + 1].x - path[i].x, 2) + pow(path[i + 1].y - path[i].y, 2));
        suma += p;
    }
    suma += sqrt(pow(path[0].x - path[path.size() - 1].x, 2) + pow(path[0].y - path[path.size() - 1].y, 2));
    cout << "������� �������: " << suma << endl;
}