#include<stdio.h>
#include<string.h>
enum country{France, England, Spain, Italy, China, Laos, USA, Canada};

typedef enum country c;

enum continent{Europe, Asia, America};

int main()
{
    c chosen;
    printf("1.France\n2.England\n3.Spain\n4.Italy\n5.China\n6.Laos\n7.USA\n8.Canada\n");
    printf("choose the country by writing number from 1 to 8:\n");
    scanf("%d",(int*)&chosen);
    chosen-=1;
    
    switch (chosen)
    {
        case (0 | 1 | 2 | 3) :
        printf("Europe\n");
        return 0;
        case (4 | 5) :
        printf("Asia\n");
        return 0;
        case(6 | 7) :
        printf("America\n");
        return 0;
    }
}