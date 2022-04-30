/*
В інформаційній базі мережі супермаркетів «Фантастік»,
що містить інформацію про товари (назва магазину, назва товару та його кількість),
визначити кількість повторів однакових товарів та їх кількість у відповідних магазинах.
Використати алгоритм рекурсивного бінарного пошуку.
*/
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// f замість struct book_info* (для зручності) 
typedef struct fantastic (*f);

//структура із інформацією про книгу
struct fantastic
{
   char name_of_shop[30];
   char name_of_goods[30];
   int count;

};

//виділення пам'яті для структури типу f 
void get_memory_for_struct(f *m, int n);

//заповнення масиву із структур типу f
//потрібно знайти кращий компроміс на рахунок заповнення стрічок(компілятор читає до пробілу
//тому неможливо ввести книжку із назвою яка має більше ніж 1 слово)
void fill_the_mas_of_shops(int n, f shops, FILE input);

//вивід даних про книгу якщо check_the_same_author_and_name_with_diff_year_of_public спрацьовує 
//зроблена під вивід даних тільки про одну книгу, тому використовуємо її двічі(на себе та на близьнюка, якщо виконується умова)
void print_the_info_about_shop(int n, f shops, int i, FILE** output);

//перевірка на умову задачі(щоб співпадав автор і назва книги проте не рік)
void check_the_same_author_and_name_with_diff_year_of_public(int n, f shops, FILE* output);

int main()
{
    int i, j, n;
    struct fantastic *shops;
    
    FILE *input;
    FILE *output;

     if((input = fopen("in.txt", "r"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }

    if((output = fopen("out.txt", "w"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }

    fscanf(input,"%d",&n);
 
    printf("count of shops: %d\n", n);
   
   get_memory_for_struct(&shops,  n);
    
   fill_the_mas_of_shops(n, shops, *input); 
   
   check_the_same_author_and_name_with_diff_year_of_public(n, shops, output);
   
   fclose(output);
   fclose(input);

   return 0;
}

void get_memory_for_struct(f *m, int n)
{
    *m = malloc(sizeof(struct fantastic) * n);
}

void fill_the_mas_of_shops(int n, f m, FILE input)
{
    int i;

    for(i = 0; i < n; i++){
        
        fscanf(&input, "%s", m[i].name_of_shop);

        fscanf(&input,"%s",m[i].name_of_goods);

        fscanf(&input, "%d", &(m[i].count));
    }
}

void print_the_info_about_shop(int n, f m, int i, FILE** output)
{
        fprintf(*output, "\ninfo about shop #%d", i+1);
        fprintf(*output, "\nname of shop = %s", m[i].name_of_shop);
        fprintf(*output, "\nname of good = %s", m[i].name_of_goods);
        fprintf(*output, "\ncount of good in a shop = %d\n", m[i].count);
}

void check_the_same_author_and_name_with_diff_year_of_public(int n, f m, FILE* output)
{
    int i, j, count = 0;

    for(i = 0; i < n; i++){
        for(j = i + 1;j < n; j++){

            if(strcmp(m[i].name_of_goods, m[j].name_of_goods) == 0){
                count++;
            }
            if(strcmp(m[i].name_of_goods, m[j].name_of_goods) == 0 && strcmp(m[i].name_of_shop, m[j].name_of_shop) == 0){
                m[i].count += m[j].count;
                m[j].count = 0;
                printf("\n%d\n",m[i].count);
            }
        }
        if(m[i].count != 0){
        print_the_info_about_shop(n, m, i, &output);
        }
    }
    fprintf(output,"\nrepeats = %d\n",count);
}