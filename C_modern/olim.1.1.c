//описати масив структур і j 
//координати пройдених вершин
#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>

int fl = 0;

int flag_matrix[10][10];
    
//
struct x_and_y
{
    int x, y;
}mas[30];

typedef struct x_and_y *x_y;

//
void horse_ride(int i, int j, int n, int count);

//
int check(int i, int j, int n);

//
void init_matrix_to_zero(int n, int i1, int j1);

//
void print_matrix(int n);

//
void print_mas(int n);

int main()
{
    int n = 5;

    int i1, j1;

    scanf("%d %d", &i1, &j1);

    init_matrix_to_zero(n, i1, j1);
    
    print_matrix(n);

    horse_ride(i1, j1, n, 1);

    print_mas(n);

}

void horse_ride(int i, int j, int n, int count)
{

    mas[count - 1].x = i;
    mas[count - 1].y = j;

    if(count == (n * n)){
        //print_the_way
        fl = 1;
        return;
    }
 // i-2,j+1
    if(check(i-2, j+1, n)){
        flag_matrix[i-2][j+1] = 1;
        horse_ride(i-2, j+1, n, count+1);
        if (fl) return;
        flag_matrix[i-2][j+1] = 0;
    }
 // i-1,j+2
    if(check(i-1, j+2, n)){
        flag_matrix[i-1][j+2] = 1;
        horse_ride(i-1, j+2, n, count+1);
        if (fl) return;
        flag_matrix[i-1][j+2] = 0;
    }
 // i+1,j+2
    if(check(i+1, j+2, n)){
        flag_matrix[i+1][j+2] = 1;
        horse_ride(i+1, j+2, n, count+1);
        if (fl) return;
        flag_matrix[i+1][j+2] = 0;
    }
 // i+2,j+1
    if(check(i+2, j+1, n)){
        flag_matrix[i+2][j+1] = 1;
        horse_ride(i+2, j+1, n, count+1);
        if (fl == 1) return;
        flag_matrix[i+2][j+1] = 0;
    }
 // i+2,j-1
    if(check(i+2, j-1, n)){
        flag_matrix[i+2][j-1] = 1;
        horse_ride(i+2, j-1, n, count+1);
        if (fl == 1) return;
        flag_matrix[i+2][j-1] = 0;
    }
 // i+1,j-2
    if(check(i+1, j-2, n)){
        flag_matrix[i+1][j-2] = 1;
        horse_ride(i+1, j-2, n, count+1);
        if (fl == 1) return;
        flag_matrix[i+1][j-2] = 0;
    }
 // i-1,j-2
    if(check(i-1, j-2, n)){
        flag_matrix[i-1][j-2] = 1;
        horse_ride(i-1, j-2, n, count+1);
        if (fl == 1) return;
        flag_matrix[i-1][j-2] = 0;
    }
 // i-2,j-1
    if(check(i-2, j-1, n)){
        flag_matrix[i-2][j-1] = 1;
        horse_ride(i-2, j-1, n, count+1);
        if (fl == 1) return;
        flag_matrix[i-2][j-1] = 0;
    }
}

int check(int i, int j, int n)
{
    if(i < 0 || j < 0) return 0;
    if(i  >= n || j >= n) return 0;
    if(flag_matrix[i][j] == 1) return 0;
    return 1;
}

void init_matrix_to_zero(int n, int i1, int j1)
{
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            flag_matrix[i][j] = 0;
        }
    }
    flag_matrix[i1][j1] = 1;
    
}

void print_matrix(int n)
{
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",flag_matrix[i][j]);
        }
        printf("\n");
    }
    

}

void print_mas(int n)
{
    int i;
    
    for(i = 0; i < (n * n); i++)
      printf("%d %d\n",mas[i].x, mas[i].y);
}