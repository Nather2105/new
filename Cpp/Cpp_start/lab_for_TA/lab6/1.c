#include <stdio.h>
#include <stdlib.h>

int dRed[100][100];

void printRes(int n, int m, int d[100][100]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int minF(int first, int second, int third, int fourth) {
    int min = 2147483647;

    if ((first < second && first != 0) || (second == 0 && first != 0)) min = first;
    else if ((second <= first && second != 0) || (first == 0 && second != 0)) min = second;

    if ((third < fourth && third != 0) || (fourth == 0 && third != 0)) min = third;
    else if ((fourth <= third && fourth != 0) || (third == 0 && fourth != 0)) min = fourth;

    return min;
}


int arrayRed[100][2], countRed;
void outRed(int array[100][2], int iter){
    for(int i = iter - 1; i >= 0; i--){
        printf("(%d, %d) ", array[i][0], array[i][1]);
        arrayRed[i][0] = array[i][0];
        arrayRed[i][1] = array[i][1];
    }
    countRed = iter - 1;
    printf("\t%d steps", iter - 1);
}

void outWolf(int array[100][2], int iter){
    int iteratorRed = countRed, waited = 0;
    for(int i = iter - 1; i >= 0; i--){
        if(i > 0 && i < iter) {
            if (array[i][0] == arrayRed[iteratorRed][0] && array[i][1] == arrayRed[iteratorRed][1]){
                iteratorRed--;
                printf("(waiting) ");
                waited++;
            }
        }
        printf("(%d, %d) ", array[i][0], array[i][1]);
        iteratorRed--;
    }
    printf("\t%d steps", iter - 1);
    if(waited != 0) printf(", waited %d times", waited);

    printf("\n\n_________________________________________\n");
//    CHECK HERE
    if((iter - 1) + waited < countRed) printf("Wolf won.");
    else if ((iter - 1) + waited > countRed) printf("Red won.");
    else printf("\tNo one won, but wolf waited. Red won.");
    printf("\n_________________________________________\n");
}


void out(int x, int y, int arr[100][100], int flag) {
    int array[100][2], iter = 0;
    array[iter][0] = x; array[iter][1] = y;
    iter++;
    int prx, pry;

    while (1) {
        if(x == 1 && y == 1) break;
        int minElem;
        prx = x; pry = y;
        if(!flag) minElem = minF(arr[x][y - 1], arr[x][y - 2], arr[x - 1][y], arr[x - 2][y]);
        else {
            minElem = minF(arr[x][y - 1], arr[x][y - 2], arr[x - 1][y], arr[x - 2][y]);
            if (arr[x - 3][y] < minElem && arr[x - 3][y] != 0) minElem = arr[x - 3][y];
            if (arr[x][y - 3] < minElem && arr[x][y - 3] != 0) minElem = arr[x][y - 3];
        }
        if (arr[x][y - 1] == minElem) {
            --y;
        } else if (arr[x][y - 2] == minElem) {
            y -= 2;
        } else if (arr[x - 1][y] == minElem) {
            --x;
        } else if (arr[x - 2][y] == minElem) {
            x -= 2;
        } else if (arr[x - 3][y] == minElem && flag) {
            x -= 3;
        } else if (arr[x][y - 3] == minElem && flag) {
            y -= 3;
        }

        if(prx == x && pry == y && arr[x][y - 1] == 0 && arr[x + 1][y] == 0) {
            printf("%d %d ", x, y);
            printf("There is no way!");
            exit(0);
        } else if (prx == x && pry == y){
            arr[x][y] = 0;
            x++;
            y++;
            iter -= 2;
            continue;
        }

        array[iter][0] = x;
        array[iter][1] = y;
        iter++;
    }
//    array[iter][0] = 1;
//    array[iter][1] = 1;
//    iter++;

    if(!flag) outRed(array, iter);
    if(flag) outWolf(array, iter);
}

void wayRed(int n, int m, int const d[100][100]) {
    dRed[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (d[i][j] != 0) {
                int min;
                min = minF(dRed[i][j - 1], dRed[i - 1][j], dRed[i - 2][j], dRed[i][j - 2]);
                if (min == 2147483647) {
                    dRed[i][j] = 1;
                    continue;
                }
                dRed[i][j] = min + 1;
            }
        }
    }
    printf("\n______________________________\nResult red:\n");
    printRes(n, m, dRed);
}

int dWolf[100][100];

void wayWolf(int n, int m, int const d[100][100]) {
    dWolf[1][1] = 1;
//    until x y
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (d[i][j] != 0) {
                int min;
                min = minF(dWolf[i][j - 1], dWolf[i - 1][j], dWolf[i - 2][j], dWolf[i][j - 2]);
//                    Стрибки через 2
                if (i - 3 >= 0 && dWolf[i - 3][j] < min && dWolf[i - 3][j] != 0) min = dWolf[i - 3][j];
                if (j - 3 >= 0 && dWolf[i][j - 3] < min && dWolf[i][j - 3] != 0) min = dWolf[i][j - 3];
                if (min == 2147483647) {
                    dWolf[i][j] = 1;
                    continue;
                }
                if (dRed[i][j] == min + 1) dWolf[i][j] = min + 2;
                else dWolf[i][j] = min + 1;
            }
        }
    }
    printf("\n______________________________\nResult wolf:\n");
    printRes(n, m, dWolf);
}


int main() {
    int n, m;
    int x, y;    // координати будинку бабусі
    int d[100][100];

// input from file
    FILE *f;
    f = fopen("1.txt", "r");
    fscanf(f, "%d %d", &n, &m);
    fscanf(f, "%d %d", &x, &y);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fscanf(f, "%d", &d[i][j]);
        }
    }

    printf("INPUT: ");
    printf("\n%d %d\n%d %d\n", n, m, x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    wayRed(n, m, d);    // maybe x and y would be better than n and m
    out(x, y, dRed, 0);
    wayWolf(n, m, d);
    out(x, y, dWolf, 1);

    return 0;
}