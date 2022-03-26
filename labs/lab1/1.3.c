#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>

//виділення пам'яті для  динамічного масиву
void get_memory_for_mas(int** res, int n);

//заповнення динамічного масиву
void fill_the_mas(int* res, int n);

//вивід динамічного масиву
void print_the_mas(int *res, int n);

//пошук люнцюга(більше ніж 1 в ряд елемент з однаковим значенням)
void find_the_chain_with_more_than_2_same_elem_in_a_row(int* res, int n, int* j, int* count_1);

//якщо функція find_the_chain_with_more_than_2_same_elem_in_a_row виконується, виводимо даний ланцюг
void print_the_longest_chain_of_the_same_number_in_a_row(int* res, int n, int j, int count_1);
int main()
{
	int i, n, x, count, count_1 = 1, y, j;
    int *res;
    
	srand(time(NULL));
	n=rand() % 291 + 10;
    
    get_memory_for_mas(&res, n);
    
    fill_the_mas(res, n);

    print_the_mas(res, n);

	
	find_the_chain_with_more_than_2_same_elem_in_a_row(res, n, &j, &count_1);
	
    printf("\n");

	if(count_1 == 1){
	    printf("\nno one chain that have more than 1 same number in a row\n");
	}
	else{
	   print_the_longest_chain_of_the_same_number_in_a_row(res, n, j, count_1);
	}
	
    free(res);
	return 0;
}
void get_memory_for_mas(int** res,int n)
{
    int i;
   
    *res = (int*)malloc(n * sizeof(int));
    if(!(*res)) exit(0);   
}

void fill_the_mas(int* res, int n)
{
    int i;

    for(i=0;i<n;i++){
        res[i] = rand()%50;
    }
}

void print_the_mas(int *res, int n)
{
    int i;

    for(i=0;i<n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}


void find_the_chain_with_more_than_2_same_elem_in_a_row(int* res, int n, int* j, int* count_1)
{
    int i, count;

    for (i = 1, count = 1; i < n; i++) {
		if (*(res+i) == *(res+i - 1)) {
			count += 1;
		}
		else if (*(res+i) != *(res+i - 1)) {
			count = 1;
		}
		 
		if (res[i] != res[i + 1] && count > *count_1) {
			*count_1 = count;
			*j = i;
			count = 1;
		}
	}
}

void print_the_longest_chain_of_the_same_number_in_a_row(int* res, int n, int j, int count_1)
{
    int i;
     for (i = j; i > j - count_1; i--) {
            printf("%d ",res[i]);
	    }
        printf("\n");
}