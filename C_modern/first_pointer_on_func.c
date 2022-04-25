#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>

//
void get_memory_matrix(int***, int*);
//
void generate_matrix(int** , int);
//
void print_matrix(int**, int);
//
void free_memory(int**, int);

 int main()
{
    int** pm;
    int i, j, n;
    void (*pf)(int** , int); //pointer on func
    void (*pf_array[])(int** , int) = {generate_matrix, print_matrix, free_memory}; // mas of pointers on funcs
    
    srand(time(NULL));
    
    get_memory_matrix(&pm, &n);
    
    (*pf_array[0])(pm, n);

    (*pf_array[1])(pm, n);
    
    (*pf_array[2])(pm, n);
    
}

void get_memory_matrix(int*** ppm, int* pn)
{
    int i, n;
    int** pm;
    
    n = rand() % 3 + 2;
    *pn = n;
    
    pm = (int**)malloc(n * sizeof(int*)); 
    *ppm = pm;
    
    for(i=0;i<n;i++){
        pm[i] = (int*)malloc(n * sizeof(int));
    }
}

void generate_matrix(int** pm, int n)
{
    int i,j;
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           pm[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int** pm, int n)
{
    int i,j;
    
    printf("\nPrinting of matrix\n");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           printf("%4d|",pm[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int** pm, int n)
{
    int i;
    
    for(i=0;i<n;i++) 
       if(pm[i]) free(pm[i]);
    
    if (pm) free(pm);
}