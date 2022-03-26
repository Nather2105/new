#include <stdio.h>
#include<time.h>
#include<stdlib.h>

//виділення пам'яті для  динамічного масиву
void get_memory_for_mas(int** a, int n);

//заповнення динамічного масиву
void fill_the_mas(int* a, int n);

//вивід динамічного масиву
void print_the_mas(int *a, int n);

//пошук двох різних за знаками локальних елементів масиву 
int find_the_different_numbers(int* a, int n);

int main()
{
    int *a, n, i;
    
    
    srand(time(NULL));
    n = rand() % 10 + 5;

    get_memory_for_mas(&a, n);

    fill_the_mas(a, n);
    
    print_the_mas(a, n);

    find_the_different_numbers(a, n);

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

    for(i = 0;i < n;i++){
        a[i]=rand()%10 - 5;
    }
}

void print_the_mas(int *a, int n)
{
    int i;

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int find_the_different_numbers(int* a, int n)
{
    int i;

    for(i = 1; i < n; i++){
        if(( *(a + i - 1) < 0 && *(a + i) >= 0) || ( *(a + i - 1) >= 0 && *(a + i) < 0)){
            printf("\nyes\n");
            return 0;
        }
    }
    printf("\nno\n");
    return 0;
}