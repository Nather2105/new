#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>

//виділення пам'яті для  динамічного масиву
void get_memory_for_mas(int** a, int n);

//заповнення динамічного масиву
void fill_the_mas(int* a, int n);

//вивід динамічного масиву
void print_the_mas(int *a, int n);

//пошук місця для змінної х(головна умова = попередній елемент < x , наступний елемент > x) 
void find_the_place_for_x(int* a, int n, int *i, int x);

//заповнення масиву б із елементами масиву а з умовою функції find_the_place_for_x
void fill_the_b(int* a, int* b, int n, int i, int x) ;

int main()
{
	int i=0, n, x, j,fl,z;
    int *a,*b;
    
	srand(time(NULL));
	n=rand() % 50 + 10;
	x=rand()%2000;
    
    printf("%d\n",x);
    get_memory_for_mas(&a, n);
    
    fill_the_mas(a, n);

    print_the_mas(a, n);

    find_the_place_for_x(a, n, &i, x);
    
    get_memory_for_mas(&b, n+1);
    
    fill_the_b(a, b, n, i, x);

    print_the_mas(b, n+1);

    free(a);
    free(b);
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
    
    a[0] = rand() % 50;
    for(i = 1; i < n; i++){
        a[i] = rand() % 50 + a[i-1];
    }
}

void print_the_mas(int *a, int n)
{
    int i;

    for(i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}
void find_the_place_for_x(int* a, int n, int *i, int x)
{
    if(x >= a[*i]){
        for(*i = 1; *i < n; *i+=1){
            if(a[*i-1] <= x && a[*i] >= x){
                break;
            }
        }  

        if (*i == n){
          printf("\nplace for x in the end of mas (%d)\n",*i);
        }
        else{
          printf("\nbetween this two %d %d\n",*i-1, *i);
        }
    }
    else{
        printf("\nplace for x in a start of the mas\n");
    }
}

void fill_the_b(int* a, int* b, int n, int i, int x) 
{
    int j;

    for(j = 0; j < i; j++){
        b[j] = a[j];
    }
    b[j] = x;

    if(i != n){ 
        for(j = i+1; j <= n; j++){
            b[j] = a[j-1];
        }
    }
}