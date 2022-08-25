#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void get_memory_for_matrix_a(int*** a, int n, int m);

void fill_the_matrix_a(int **a, int m, int n);

void print_matrix_a(int **a, int m, int n);

void free_memory_a(int** a, int n);

int main()
{
    int i, n, m;
    int **a;
    
    srand(time(NULL));

    n = rand() % 3 + 2;
    m = rand() % 3 + 2;

    get_memory_for_matrix_a(&a, n, m);

    fill_the_matrix_a(a, m, n);

    print_matrix_a(a, m, n);

    free_memory_a(a, n);

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
void free_memory_a(int** a, int n)
{
    int i;
    
    for(i=0;i<n;i++) 
       if(a[i]) free(a[i]);
    
    if (a) free(a);   
}