/*
В інформаційній базі мережі супермаркетів «Фантастік»,
що містить інформацію про товари (назва магазину, назва товару та його кількість),
визначити кількість повторів однакових товарів та їх кількість у відповідних магазинах.
Використати алгоритм рекурсивного бінарного пошуку.
*/
//відсортувати за назвою і якщо назва співпадає то +1 повтор
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count = 0;
// f замість struct book_info* (для зручності) 
typedef struct fantastic (*f);

//структура із інформацією про книгу
struct fantastic
{
   char name_of_shop[30];
   char name_of_goods[30];
   int count;
   int PIN;

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
void print_the_infos(int n, f shops, FILE* output);

//
void sort(int n, f shops, FILE* output, struct fantastic x);

//
void Bin_Recurs(int L, int R, f s);

int main()
{
    int i, j, n;
    struct fantastic *shops;
    struct fantastic x;
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

    fscanf(input, "%d", &n);
 
    printf("count of shops: %d\n", n);
   
   get_memory_for_struct(&shops,  n);
    
   fill_the_mas_of_shops(n, shops, *input);

   sort(n, shops, output, x);

   print_the_infos(n, shops, output);
   
   Bin_Recurs(1, n - 1, shops);
   
   fprintf(output, "\n repeats: %d\n",count);
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

        fscanf(&input, "%d", &(m[i].PIN));
    }
}

void print_the_info_about_shop(int n, f m, int i, FILE** output)
{
        fprintf(*output, "\ninfo about shop #%d", i+1);
        fprintf(*output, "\nname of shop = %s", m[i].name_of_shop);
        fprintf(*output, "\nname of good = %s", m[i].name_of_goods);
        fprintf(*output, "\ncount of good in a shop = %d", m[i].count);
        fprintf(*output, "\ncode of product = %d\n", m[i].PIN);
}

void print_the_infos(int n, f m, FILE* output)
{
    int i, j, count = 0;

    for(i = 0; i < n; i++){
        print_the_info_about_shop(n, m, i, &output);
    }
}
void sort(int n, f m, FILE* output, struct fantastic x)
{
    int i, j, count = 0;

    for(i = 0; i < n; i++){
        for(j = i + 1;j < n; j++){
            if(m[i].PIN > m[j].PIN){
                x = m[i];
                m[i] = m[j];
                m[j] = x;
            }
        }
    }
}
void Bin_Recurs(int L, int R, f s)
{
    int  m;
    if  (L+1!=R)  // чому ???
         {
               m=(L+R)/2;
               if  (s[m].PIN - s[L].PIN != m - L)  Bin_Recurs(L, m, s);
               if  (s[R].PIN - s[m].PIN != R - m) Bin_Recurs(m, R, s);
          }
    else count++;
}