#include <stdio.h>
#include<time.h>
#include<stdlib.h>

//виділення пам'яті для  динамічного масиву
void get_memory_for_mas(int** a, int n);

//заповнення динамічного масиву
void fill_the_mas(int* a, int n);

//вивід динамічного масиву
void print_the_mas(int *a, int n);

//шукаємо перший елемент який ділиться на 5
int find_the_first_number_that_divided_on_5(int* a, int n, int *max_i);

//якщо команда find_the_first_number_that_divided_on_5 знайшла підходяще число, шукаємо максимальне після нього
void max_after_number_that_divided_on_5(int *a, int n, int max_i, int* max);

int main()
{
    int i,  max=0, n, max_i=0;
    int *a;
    

    srand(time(NULL));
    n = rand() % 10 + 5;
   
    get_memory_for_mas(&a, n);
    
    fill_the_mas(a, n);

    print_the_mas(a, n);
    
    if (find_the_first_number_that_divided_on_5(a, n, &max_i) != 0){
        max_after_number_that_divided_on_5(a, n, max_i, &max);
    }
    else{
        printf("\nnot even 1 number that divided on 5\n");
    }
    free(a);
    return 0;   
}

void get_memory_for_mas(int** a,int n)
{
    int i;

    *a = (int*)malloc(n * sizeof(int));
    if(!(*a)) exit(0);   
}

void fill_the_mas(int* a, int n)
{
    int i;

    for(i=0;i<n;i++){
        a[i]=rand()%50;
    }
}

void print_the_mas(int *a, int n)
{
    int i;

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}
int find_the_first_number_that_divided_on_5(int *a, int n, int* max_i)
{
    int i;
    int max=0;
    for(i=0;i<n;i++){
        if ( a[i] % 5 == 0 && a[i] != 0){
           printf ("\nfirst number that divided on 5=%d",*(a+i));
           max = a[i];
           *max_i = i;

           return max;
        }
    }
    return max;
}

void max_after_number_that_divided_on_5(int *a, int n, int max_i, int* max)
{
    int i;
    for(i = max_i; i < n; i++){
        if(a[i] > *max) *max = a[i];
    }
    printf("\nmax after number that divided on 5 = %d\n",*max);
}