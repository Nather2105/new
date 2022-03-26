#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>

//виділення пам'яті для матриці а
void get_memory_for_matrix_a(int*** a, int n, int m);

//заповнити випадковим чином матрицю
void fill_the_matrix_a(int **a, int m, int n);

//виділення пам'яті для матриці б
void get_memory_for_matrix_b(int*** b, int m, int n);

//заповнити випадковим чином матрицю
void fill_the_matrix_b(int** b, int m, int n);

//вивід матриці а
void print_matrix_a(int **a, int m, int n);

//вивід матриці б 
void print_matrix_b(int **b, int m, int n);

//вивільнення матриці а
void free_memory_a(int** a, int n);

//вивільнення матриці б
void free_memory_b(int** b, int m);

//додавання у випадку якщо рядки = стовпці в матриці
void same_size_of_matrixes(int **a, int **b, int n, int m);


//додавання у випадку якщо рядки != стовпці в матриці
void not_same_size_of_matrixes(int **a, int **b, int n, int m);

int main()
{
	int i, m, n, j;
    int **a, **b;
    int *h, *l;
    
    srand(time(NULL));

    n = rand () % 3 + 2;
    m = rand () % 3 + 2;
 
    get_memory_for_matrix_a(&a, n, m);

    fill_the_matrix_a(a, m, n);
    
    print_matrix_a(a, m, n);

    get_memory_for_matrix_b(&b, m, n);

    fill_the_matrix_b(b, m, n);

    print_matrix_b(b, m, n);
    
    if(m == n){
        same_size_of_matrixes(a, b, n, m);
        return 0;
    }
    else {
        not_same_size_of_matrixes(a, b, n, m);
    }

    free_memory_a(a, n);

    free_memory_b(b, m);
}

void get_memory_for_matrix_a(int*** a, int n, int m)
{
    int i;
    int **pa;

    pa = (int**) malloc(sizeof(int*) * n);
    *a = pa;

    for (i = 0; i < n; i++) {
        pa[i] = (int*)malloc(sizeof(int) * m);
    }
}

void fill_the_matrix_a(int **a, int m, int n)
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand()%10;
        }
    }
}

void get_memory_for_matrix_b(int ***b, int m, int n)
{
    int i;
    int **pb;

    pb = malloc(sizeof(int*) * m);
    *b = pb;

    for (i = 0; i < m; i++) {
        pb[i] = malloc(sizeof(int) * n);
    }
    
}

void fill_the_matrix_b(int **b, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = rand()%10;
        }
    }
}

void print_matrix_a(int **a, int m, int n)
{
    int i,j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d|", a[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_b(int **b, int m, int n)
{
    int i,j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d|", b[i][j]);
        }
        printf("\n");
    }
}

void free_memory_a(int** a, int n)
{
    int i;
    
    for(i=0;i<n;i++) 
       if(a[i]) free(a[i]);
    
    if (a) free(a);   
}

void free_memory_b(int** b, int m)
{
    int i;
    
    for(i = 0; i < m; i++) 
       if(b[i]) free(b[i]);
    
    if (b) free(b);   
}

void same_size_of_matrixes(int **a, int **b, int n, int m)
{
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d\t",a[i][j]+b[i][j]);
        }
        printf("\n");
    }
}
void not_same_size_of_matrixes(int **a, int **b, int n, int m)
{
    int *h, *l, i, j;

    if(n > m){
        h = &n;
        l = &m;
        for(i = 0; i < *h; i++){
           for(j=0;j<*h;j++){
              if(i<*l && j<*l){
                printf("%d\t",a[i][j] + b[i][j]);
              }
              if(i>=*l && j<*l){
                printf("%d\t", a[i][j]);
              }
              if(i<*l && j>=*l){
                printf("%d\t", b[i][j]);
              }
              if(i>=*l && j>=*l){
                printf(" \t");
              }
           }
        printf("\n");
        }
    }
    else if(m > n){
        h = &m;
        l = &n;
        for(i=0;i<*h;i++){
            for(j=0;j<*h;j++){
              if(i<*l && j<*l){
                printf("%d\t",a[i][j] + b[i][j]);
              }
              if(i>=*l && j<*l){
                printf("%d\t", b[i][j]);
              }
              if(i<*l && j>=*l){
                printf("%d\t", a[i][j]);
              }
              if(i>=*l && j>=*l){
                printf(" \t");
              }
            }
        printf("\n");
        }
    } 
}