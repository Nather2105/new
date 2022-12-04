#include <stdio.h>

//  Варіант №9
//  Для проведення профілактичних робіт місцевий водоканал має відключити воду в одному з районів міста.
//  Для попередження про відключення води кур’єр має обійти всі помешкання у цьому районі. Однак наперед
//  відомо, що деякі господарки зустрічають цю новину не дуже спокійно.
//  Допоможіть кур’єру визначити такий маршрут обходу будинків, щоб сумарна кількість децибел була найменшою.

//  Відомо, що n (2 ≤ n ≤ 100) – кількість помешкань; (i, j, w) – m (1 ≤ m ≤ 1000) трійок чисел, що вказують номери будинків,
//  безпосередньо з'єднаних між собою, та рівень децибел, якими супроводжується обурення господарки будинку і.

//  Врахувати також, що при переміщеннях між будинками (i, j) та (j, i) рівень децибел може бути різним.

int a[50];

void buildP(int n, int d[100][100]){
    int l, r, min;
    int point[100], d_new[100][100], resList[100][100], count, dBCount = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d_new[i][j] = 0;
        }
    }

    int arrayWasHere[7];
    for (int i = 1; i <= n; i++) {
        point[i] = 0;
        arrayWasHere[i] = 0;
    }
    point[1] = 1;
    count = 0;

    int numOfLines = 0;

    while (count < n - 1){
        min = 65535;
        for (int i = 1; i <= n; i++){
            if (point[i] == 1) {
                for (int j = 1; j <= n; j++) {
                    if (point[j] == 0 && d[i][j] < min && d[i][j] > 0) {
                        min = d[i][j];
                        l = i;
                        r = j;
                        resList[count][0] = l;
                        resList[count][1] = r;
                        numOfLines++;
                    }
                }
            }
        }
        if (arrayWasHere[l] == 0) arrayWasHere[l] = 1;
        d_new[l][r] = d[l][r];
        d_new[r][l] = d[r][l];
        printf("%d %d \n", l, r);
        dBCount += d_new[l][r];

        point[r] = 1;
        count++;
    }

    printf("\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d\t", d_new[i][j]);
        }
        printf("\n");
    }

    printf("Count = %d", dBCount);
}

int main() {
    int n, m, d[100][100];
    FILE *f;
    f = fopen("input1.txt", "r");
    fscanf(f,"%d%d",&n,&m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = 0;
        }
    }
    int x, y, w;

//    Зчитувати по одному w кожен раз, тобто (1 2 3) і (2 1 4)
    for(int i = 1; i <= m * 2; i++){
        fscanf(f,"%d %d %d", &x, &y, &w);
        d[x][y] = w;
        a[i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    buildP(n, d);

    return 0;
}
