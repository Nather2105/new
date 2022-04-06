#include <stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>


//
float sin_2(float x);

//
float cos_2(float x);

//
void print_table(float, float, float, float pf (float));

int main ()
{
    float x;
    float (*pf_array[])(float) = {sin_2 , cos_2};
    int choise;

    while (1){
        printf("\npush 1 for sin\n");
        printf("push 2 for cos\n");
        printf("push 3 for exit\n");
        scanf("%d", &choise);
        if (choise == 1 || choise == 2)  print_table(1, 10, 1, pf_array[choise - 1]);
        else break;
    }
    
    return 0;
}

void print_table(float a, float b, float step, float pf (float))
{
    float x = a;
    
    for(;x<=b; x+=step){
        printf("\nx = %5.3f f(x) = %5.3f", x, (*pf)(x));
    }
}

float sin_2(float x)
{
    return sin(x) * sin(x);
}
float cos_2(float x)
{
    return cos(x) * cos(x);
}
