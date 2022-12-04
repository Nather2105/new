#include <stdio.h>

// Варіант №9
// На підлозі прямокутного приміщення від однієї стіни до іншої лежить пряма паперова смужка, паралельна довшій стороні.
// Над підлогою розташовані n (1≤n≤100000) паралельних їй шарів перекриттів. У кожному з цих перекриттів над смужкою
// пороблені mi (і=1,2,…,n) прямокутних прорізів різної ширини, проекції яких на підлогу перпендикулярні смужці. Через
// таку систему перекриттів на смужку падають паралельні промені світла.
// Вказати координати освітлених частин смужки, якщо відомі кількість прорізів та пари координат кінців проекцій цих
// прорізів на смужку на кожному шарові даної конструкції. Розсіюванням світла та шириною смужки необхідно знехтувати.


//  Може бути перпендикулярна, але не перетинати!

struct Point{
    int x;
    int y;
};
struct BothPoints {
    struct Point point1;
    struct Point point2;
};
struct BothPoints tag = {1, 0, 1, 12};  // смужка

void coordinates(struct BothPoints p){
    if(p.point1.x <= tag.point1.x && p.point2.x >= tag.point2.x && p.point1.y == p.point2.y){
        struct Point point;
        point.x = tag.point1.x;
        point.y = p.point1.y;
        printf("(%d, %d)\n", point.x, point.y);
    } else printf("No intersection point.\n");

}

int main() {
    FILE *file = fopen("1.txt", "r");
    int m;
    fscanf(file, "%d", &m);
    struct BothPoints light[m];
    for(int i = 0; i < m; i++){
        fscanf(file, "%d %d %d %d", &light[i].point1.x, &light[i].point1.y, &light[i].point2.x, &light[i].point2.y);
        coordinates(light[i]);
    }


    return 0;
}
