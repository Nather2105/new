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


//
struct Star
{
    int x, y;
    
};

//
Star p0;

//
Star nextToTop(stack<Star>& S);

//
void swap(Star&, Star&);

//
int distSq(Star, Star);

//
int orientation(Star, Star, Star);

//
int compare(const void*, const void*);

//
void find_the_answer(Star stars[], int);

int main()
{
    cout << "Input amount of stars: ";
    int n; cin >> n;
    Star* points = new Star[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cout << "input x and y for star #" << i+1 << endl;
        cin >> x >> y;
        points[i].x = x;
        points[i].y = y;
    }
    find_the_answer(points, n);
    return 0;
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

int orientation(Star p, Star q, Star r)
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

void find_the_answer(Star stars[], int n)
{

    int ymin = stars[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = stars[i].y;

        if ((y < ymin) || (ymin == y &&
            stars[i].x < stars[min].x))
            ymin = stars[i].y, min = i;
    }

    swap(stars[0], stars[min]);

    p0 = stars[0];
    qsort(&stars[1], n - 1, sizeof(Star), compare);

    int m = 1; 
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, stars[i],
            stars[i + 1]) == 0)
            i++;


        stars[m] = stars[i];
        m++;
    }

    if (m < 3){
        cout << "cannot find the answer " << endl;
        return;
    }

    stack<Star> S;
    S.push(stars[0]);
    S.push(stars[1]);
    S.push(stars[2]);

    for (int i = 3; i < m; i++)
    {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), stars[i]) != 2)
            S.pop();
        S.push(stars[i]);
    }
    vector <Star> path;
    double suma_x = 0, suma_y = 0;
    
    while (!S.empty())
    {
        Star p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        path.push_back(p);
        S.pop();
    }
    for (int i = 0; i < path.size(); i++) {
        suma_x += path[i].x;
        suma_y += path[i].y;
    }
    
    cout << "center is (" << suma_x/path.size() <<", " << suma_y/path.size() <<")" << endl;  
}
