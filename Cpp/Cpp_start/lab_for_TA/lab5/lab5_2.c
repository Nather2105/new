#include <stdio.h>
#include <stdbool.h>

int minResult = 65535, minResultFrom[50], minResultTo[50], iter;

bool isInList(int a, int b){
    for(int i = 0; i < iter; i++){
        if (b == minResultFrom[i] && a == minResultTo[i]) return true;
    }
    return false;
}

void findAWay(int n, int d[100][100]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j] && d[i][k] != 0 && d[k][j] != 0) {
                    d[i][j] = d[i][k] + d[k][j];
                }
                if(d[i][j] < minResult && d[i][j] != 0) minResult = d[i][j];
            }
        }
    }

    printf("\nMin result: %d\n", minResult);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
//            printf("%d\t", d[i][j]);
            if(d[i][j] == minResult && !isInList(i, j)) {
                minResultFrom[iter] = i;
                minResultTo[iter] = j;
                iter++;
                printf("From %d to %d\n", i, j);
            }
        }
//        printf("\n");
    }
}

int main() {
    int d[100][100];
    int n, m;

    FILE *f;
    f = fopen("1.txt", "r");
    fscanf(f, "%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = 0;
        }
    }
    int x, y, w;

    for (int i = 1; i <= m; i++) {
        fscanf(f, "%d %d %d", &x, &y, &w);
        d[x][y] = w;
        d[y][x] = w;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    findAWay(n, d);
    return 0;
}
