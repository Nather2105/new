#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// f замість struct book_info* (для зручності) 
typedef struct book_info (*f);

//структура із інформацією про книгу
struct book_info
{
   char last_name_of_author[30];
   char name_of_book[30];
   int year_of_publication;
   int cost;

};

//виділення пам'яті для структури типу f 
void get_memory_for_struct(f *m, int n);

//заповнення масиву із структур типу f
//потрібно знайти кращий компроміс на рахунок заповнення стрічок(компілятор читає до пробілу
//тому неможливо ввести книжку із назвою яка має більше ніж 1 слово)
void fill_the_mas_of_books(int n, f mas_of_books);

//вивід даних про книгу якщо check_the_same_author_and_name_with_diff_year_of_public спрацьовує 
//зроблена під вивід даних тільки про одну книгу, тому використовуємо її двічі(на себе та на близьнюка, якщо виконується умова)
void print_the_info_about_book(int n, f mas_of_books, int i);

//перевірка на умову задачі(щоб співпадав автор і назва книги проте не рік)
void check_the_same_author_and_name_with_diff_year_of_public(int n, f mas_of_books);

int main()
{
    int i, j, n;
    struct book_info *mas_of_books;
    void (*f_array[])(int, f) ={fill_the_mas_of_books, check_the_same_author_and_name_with_diff_year_of_public};

    printf("input number of books:\n");
    scanf("%d", &n);
 
   get_memory_for_struct(&mas_of_books,  n);
    
   f_array[0](n, mas_of_books); 
  // fill_the_mas_of_books(n, mas_of_books); 
   
   if(n == 1){
       printf("\nonly 1 book in a base(cant compare)\n");
       return 0;
   }
   f_array[1](n, mas_of_books); 
  // check_the_same_author_and_name_with_diff_year_of_public(n, mas_of_books);
   
   return 0;
}

void get_memory_for_struct(f *m, int n)
{
    *m = malloc(sizeof(struct book_info) * n);
}

void fill_the_mas_of_books(int n, f m)
{
    int i;

    for(i = 0; i < n; i++){
        printf("for book #%d:\n", i+1);
        
        printf("input last name of author:");
        scanf("%s", m[i].last_name_of_author);
   //   scanf("%*[^\n]%*c",m[i].last_name_of_author);        
   //     fflush();
   //     fgets(m[i].last_name_of_author,30,stdin);
        
        printf("\nname_of_book:");
        scanf("%s",m[i].name_of_book);

        printf("\nyear_of_publication:");
        scanf("%d", &(m[i].year_of_publication));

        printf("\ncost:");
        scanf("%d", &(m[i].cost));
    }
}

void print_the_info_about_book(int n, f m, int i)
{
        printf("\ninfo about book #%d", i+1);
        printf("\nauthor = %s", m[i].last_name_of_author);
        printf("\nname of book = %s", m[i].name_of_book);
        printf("\nyear = %d", m[i].year_of_publication);
        printf("\ncost = %d\n", m[i].cost);
}

void check_the_same_author_and_name_with_diff_year_of_public(int n, f m)
{
    int i, j, fl = 1;

    for(i = 0; i < n; i++){
        for(j = i + 1;j < n; j++){
            if(strcmp(m[i].last_name_of_author, m[j].last_name_of_author) == 0 && strcmp(m[i].name_of_book, m[j].name_of_book) == 0){
                if(m[i].year_of_publication != m[j].year_of_publication){
                    printf("\nyeah\n");
                    print_the_info_about_book(n, m, i);
                    print_the_info_about_book(n, m, j);
                    fl = 0; 
                }
            }
        }
    }
    if(fl){
        printf("\nnot even 1 access comparing\n");
    }
}