#include<stdio.h>
#include<string.h>
enum country{France, England, Spain, Italy, China, Laos, USA, Canada};

enum continent{Europe, Asia, America};

int main()
{
    enum country chosen;
    printf("1.France\n2.England\n3.Spain\n4.Italy\n5.China\n6.Laos\n7.USA\n8.Canada\n");
    printf("choose the country by writing number from 1 to 8:\n");
    scanf("%d",(int*)&chosen);

    chosen-=1;

    if(chosen > 7){
        printf("ERROR\n");
        return 0;
    }
    
    if(chosen == France || chosen == Spain || chosen == England || chosen == Italy){
        printf("Europe\n");
    }
    if(chosen == China || chosen == Laos){
        printf("Asia\n");
    }
    if(chosen == USA || chosen == Canada){
        printf("America\n");
    }
    return 0;
}