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
void print_the_info_about_book(int n, f mas_of_books, int i, FILE** output);

//перевірка на умову задачі(щоб співпадав автор і назва книги проте не рік)
void check_the_same_author_and_name_with_diff_year_of_public(int n, f mas_of_books, FILE* output);


int main()
{
    char start[1000];
    int i, j, n, k, p;
    struct book_info *mas_of_books;
    struct book_info *mas_of_books1;
    FILE *input_for_writing;
    FILE *input_for_reading;
    FILE *output;
    FILE *output_txt;
    
    if((input_for_writing = fopen("input.bin", "wb"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }

    scanf("%d", &n);

    get_memory_for_struct(&mas_of_books,  n);

    fill_the_mas_of_books(n, mas_of_books); 

    fwrite(mas_of_books, n, sizeof(*mas_of_books), input_for_writing); //записуємно вхідні дані в бін файл

    free(mas_of_books); // вивільнення структури

    fclose(input_for_writing);
    
    if((input_for_reading = fopen("input.bin", "rb"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }

    fseek(input_for_reading, 0, SEEK_END); // поінтер в кінець заради того щоби дізнатися довжину файлу
    
    k = ftell(input_for_reading) / sizeof(struct book_info); // довжина файлу

    get_memory_for_struct(&mas_of_books1,  k); 

    fseek(input_for_reading, 0, SEEK_SET); // поінтер на початок
    fread(mas_of_books1, k, sizeof(*mas_of_books1), input_for_reading); // читаємо інформацію з бін файлу
    fclose(input_for_reading);

    printf("Number of books: %d\n", n);
  
    if(n == 1){  // перевірка умови
       printf("\nonly 1 book in a base(cant compare)\n");
       return 0;
    }

    if((output = fopen("output.txt", "w"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }
   
    check_the_same_author_and_name_with_diff_year_of_public(n, mas_of_books1, output);
    
    fclose(output);

    if((output_txt = fopen("output.txt", "r"))==NULL) {
       printf("Cannot open file.");
       return 0;
    }
    fseek(output_txt, 0, SEEK_END);
    p = ftell(output_txt);
    fseek(input_for_reading, 0, SEEK_SET);
    fread(start, p , sizeof(char), output_txt);
    
    printf("%s",start);

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
        
        scanf("%s", m[i].last_name_of_author);

        scanf("%s",m[i].name_of_book);

        scanf("%d", &(m[i].year_of_publication));

        scanf("%d", &(m[i].cost));
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
            // перевірка умови чи співпадають назви та автори фільму але з різними роками видавництва
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
        fprintf(output,"\nnot even 1 access comparing\n");
    }
}
