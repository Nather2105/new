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

//
int search(int* a, int l, int r, int value);

//
void get_value(int* pvalue);

int main()
{
    int *a, n, i, value, result;
    
    
    srand(time(NULL));
    n = 50;

    get_memory_for_mas(&a, n);

    fill_the_mas(a, n);
    
    print_the_mas(a, n);

    while(1){
      get_value(&value);
    
      result = search(a, 0, n - 1, value);
      
      if(result != -1) printf("value at %d\n", result);
      else{ 
          printf("value is not found\n");
          break;
      }
    };
    
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
        a[i] = i;
    }
}

void print_the_mas(int *a, int n)
{
    int i;

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int search(int* a, int l, int r, int value)
{
    int i;
    
    if(l > r) return -1;
    
    i = (l + r) / 2;
    
    if(value == a[i]) return i;
    
    if (value > a[i]) return search(a, i + 1, r, value);
    else return search(a, l, i - 1, value);
    
}

void get_value(int* pvalue)
{
    printf("\nvalue = ");
    
    scanf("%d", pvalue);
}