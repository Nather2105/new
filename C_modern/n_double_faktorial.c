#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//рекурентна функція подвійного факторіалу
long int double_fact(int);

int main(void) {
	
	int n;
	long int res;
	
    srand(time(NULL));
    
	n = rand() % 10;
	
	res = double_fact(n);
	
	printf("%d! = %ld\n ", n, res);
	
	return 0;
}

long int double_fact(int n)
{ 
      if(n == 0 || n == 1) return 1;
      return n * double_fact(n - 2);
}

