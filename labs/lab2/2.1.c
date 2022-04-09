#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

//виділення пам'яті для  динамічного масиву
void get_memory_for_mas(long double** a, int n);

//заповнення динамічного масиву
void fill_the_mas(long double* y, int n);

//вивід динамічного масиву
void print_the_mas(long double *a, int n);

//заповнення рекурсивного масиву Т
void fill_the_mas_t(long double* t, int n, float x);

//рекурсивна функція суми
long double sum_func(long double *t, long double *y, int n);

int main()
{
    int n, i;
    float x;
    long double *t;
    long double s;
    long double *y;

    srand(time(NULL));
    n = 2;
    x = 123.53;
    printf("\nx = %f\n", x);

    get_memory_for_mas(&t, n+1);
    
    fill_the_mas_t(t, n, x);
    
    printf("printing mas T:");

    print_the_mas(t, n);

    get_memory_for_mas(&y, n+1);

    fill_the_mas(y, n);
    
    printf("\nprinting mas Y:");

    print_the_mas(y, n);

    s = sum_func(t, y, n);
    printf("\n%.2Lf\n", s);

    free(t);
    free(y);

    return 0;
}
void get_memory_for_mas(long double** a,int n)
{
    int i;
   
    *a = (long double*)malloc(n * sizeof(long double));
    if(!(*a)) exit(0);   
}

void fill_the_mas(long double* y, int n)
{
    int i;

    for(i = 0; i <= n; i++){
        y[i] = rand() % 50 * 1.234;
    }
}

void print_the_mas(long double *a, int n)
{
    int i;
    
    printf("\n");

    for(i = 0;i <= n; i++){
        printf("%.2Lf ",a[i]);
    }
    printf("\n");
}

void fill_the_mas_t(long double* t, int n, float x)
{
    int i;
    
    t[0] = 1;
    t[1] = x;
    
    for(i = 2; i <= n; i++){
        t[i] = 2 * x * t[i-1] - t[i-2];
    }
}

long double sum_func(long double *t, long double *y, int n)
{
    if (n == 0) return pow(-y[n],n) * t[n];
    return pow(-y[n], n) * t[n] + sum_func(t, y, n-1);
}