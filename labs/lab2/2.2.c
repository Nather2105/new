#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//рекурентна функція факторіалу
long int fact(int);

int main(void) {
	
	int n;
	long int res;
	
    srand(time(NULL));
    
	n = rand() % 10;
	
	res = fact(n);
	
	printf("%d! = %ld\n", n, res);
	
	return 0;
}

long int fact(int n)
{ 
      if(n == 0) return 1;
      return n * fact(n - 1);
}