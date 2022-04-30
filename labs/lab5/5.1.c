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
void fill_the_mas_of_books(int n, f mas_of_books, FILE input);

//вивід даних про книгу якщо check_the_same_author_and_name_with_diff_year_of_public спрацьовує 
//зроблена під вивід даних тільки про одну книгу, тому використовуємо її двічі(на себе та на близьнюка, якщо виконується умова)
void print_the_info_about_book(int n, f mas_of_books, int i, FILE** output);

//перевірка на умову задачі(щоб співпадав автор і назва книги проте не рік)
void check_the_same_author_and_name_with_diff_year_of_public(int n, f mas_of_books, FILE* output);

int main()
{
    int i, j, n;
    struct book_info *mas_of_books;
    
    FILE *input;
    FILE *output;

     if((input = fopen("input.txt", "r"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }

    if((output = fopen("output.txt", "w"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }

    fscanf(input,"%d",&n);
 
    printf("Number of books: %d\n", n);
        
    if(n == 1){
       printf("\nonly 1 book in a base(cant compare)\n");
       return 0;
   }
   
   get_memory_for_struct(&mas_of_books,  n);
    
   fill_the_mas_of_books(n, mas_of_books, *input); 
   
   check_the_same_author_and_name_with_diff_year_of_public(n, mas_of_books, output);
   
   fclose(output);
   fclose(input);

   return 0;
}

void get_memory_for_struct(f *m, int n)
{
    *m = malloc(sizeof(struct book_info) * n);
}

void fill_the_mas_of_books(int n, f m, FILE input)
{
    int i;

    for(i = 0; i < n; i++){
        
        fscanf(&input, "%s", m[i].last_name_of_author);

        fscanf(&input,"%s",m[i].name_of_book);

        fscanf(&input, "%d", &(m[i].year_of_publication));

        fscanf(&input, "%d", &(m[i].cost));
    }
}

void print_the_info_about_book(int n, f m, int i, FILE** output)
{
        fprintf(*output, "\ninfo about book #%d", i+1);
        fprintf(*output, "\nauthor = %s", m[i].last_name_of_author);
        fprintf(*output, "\nname of book = %s", m[i].name_of_book);
        fprintf(*output, "\nyear = %d", m[i].year_of_publication);
        fprintf(*output, "\ncost = %d\n", m[i].cost);
}

void check_the_same_author_and_name_with_diff_year_of_public(int n, f m, FILE* output)
{
    int i, j, fl = 1;

    for(i = 0; i < n; i++){
        for(j = i + 1;j < n; j++){
            if(strcmp(m[i].last_name_of_author, m[j].last_name_of_author) == 0 && strcmp(m[i].name_of_book, m[j].name_of_book) == 0){
                if(m[i].year_of_publication != m[j].year_of_publication){
                    printf("\nyeah\n");
                    fprintf(output,"the same book but diff year of publication");
                    print_the_info_about_book(n, m, i, &output);
                    print_the_info_about_book(n, m, j, &output);
                    fl = 0; 
                }
            }
        }
    }
    if(fl){
        printf("\nnot even 1 access comparing\n");
    }
}