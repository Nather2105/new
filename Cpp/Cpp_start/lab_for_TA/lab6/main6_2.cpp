// Варіант №15

// Команда Святих Миколаїв на новорічні свята розвозить слухняним діткам подарунки.
// У кожного бородатого дідуся є свій власний розклад об’їзду діточок. 
// За спільною домовленістю дідусі періодично мають спільну перерву для спілкування та чаювання.
// Визначити, скільки таких перерв передбачено для команди з n (1≤n≤100000) Святих Миколаїв та їх часові інтервали, 
// якщо відомий розклад роботи для кожного і-го (1≤i≤n) дідуся: ki – кількість відвідувань протягом доби,
// sti – час початку відвідування (години/хвилини), ti – час, протягом якого відбувається дане відвідування.
// Всі часові інтервали опрацьовуються протягом доби.



#include <iostream>
#include <fstream>
using std::ifstream;
using namespace std;
#include <cstdlib>


//
class Visit
{
    public:
        int hour_of_start;
        int minute_of_start;
        int hour_of_finish;
        int minute_of_finish;
        int time_for_visit;
        int set_visit();
        void print();

};

//
class Santa
{
    private:

        int amount_of_visits;
        Visit *visits;

    public:

        Santa(int);
        ~Santa();
        void print();
        friend void fill_the_info(Santa* a, int n);
        friend void print_info_about_all_santas(Santa*, int);
        friend int check_time_for_santas(int i, int j, Santa* a, int n);


};

struct List
{
    Visit tea_visit;
    struct List *next;
};

//
void get_memory_for_array(Santa**, int);

//
void get_memory_for_visits(Visit**, int);

//
void print_info_about_all_santas(Santa*, int);

//
int find_the_answer(Santa*, int);

//
int check_time_for_santas(int i, int j, Santa* a, int n);

int main()
{
    Santa *santas;
    int n, i, x, y, loss;

    cout << "Input amount of Santas:" << endl;
    cin >> n;
    get_memory_for_array(&santas, n);


    fill_the_info(santas, n);    
    print_info_about_all_santas(santas, n);

    find_the_answer(santas, n);

    return 1;
}

void get_memory_for_array(Santa** a, int n)
{
    *a = (Santa*)malloc(sizeof(Santa) * n);
}

void get_memory_for_visits(Visit** a, int n)
{
    *a = (Visit*)malloc(sizeof(Visit) * n);
}


int Visit::set_visit()
{
    int helper, i, count = 0;
    for(i = minute_of_start + time_for_visit; i >= 60; i-=60){
        count++;
    }
    hour_of_finish = hour_of_start + count;
    minute_of_finish = i;
    if(hour_of_finish >= 24){
        return 0;
    }

    return 1;


}

void Visit::print()
{
        cout << "from " << hour_of_start << ":";
        if(minute_of_start >= 0 && minute_of_start <= 9){
            cout << "0" << minute_of_start << endl;
        }
        else{
            cout << minute_of_start << endl;
        }
        
        cout << "to " << hour_of_finish << ":";
        if(minute_of_finish >= 0 && minute_of_finish <= 9){
            cout << "0" << minute_of_finish << endl;
        }
        else{
            cout << minute_of_finish << endl;
        }
}



void Santa::print()
{
    int i, helper;

    cout << "amount of visits is " << amount_of_visits << endl; 
    for(i = 0; i < amount_of_visits; i++){
        visits[i].print();
    }
}

void print_info_about_all_santas(Santa* a, int n)
{
    for(int i = 0; i < n; i++){
        cout << "info about Santa #" << i+1 << ":" << endl;
        a[i].print();
    }
}

void fill_the_info(Santa* a, int n)
{   
    int i, j;
    for(i = 0; i < n; i++){
        cout << "input amount of visits about santa #" << i+1 << ":" << endl;
        cin >> a[i].amount_of_visits;
        get_memory_for_visits(&(a[i].visits), a[i].amount_of_visits);
        for(j = 0; j < a[i].amount_of_visits; j++){
            cout << "input hour of start for visit #" << j+1 << "(for santa #" << i+1 << "):" << endl;
            cin >> a[i].visits[j].hour_of_start;
            if(a[i].visits[j].hour_of_start >= 24){
                cout << "hour can't be 24 or more" << endl;
                cout << "renew the info" << endl;
                j--;
                continue;
            }
            cout << "input minute of start for visit #" << j+1 << "(for santa #" << i+1 << "):" << endl;
            cin >> a[i].visits[j].minute_of_start;
            if(a[i].visits[j].minute_of_start >= 60){
                cout << "minute can't be 60 or more" << endl;
                cout << "renew the info" << endl;
                j--;
                continue;
            }
            cout << "input time for visit #" << j+1 << "(for santa #" << i+1 << "):" << endl;
            cin >> a[i].visits[j].time_for_visit;

            if (a[i].visits[j].set_visit() == 0){
                j--;
                cout << "error: a lot of work for Santa(he will not work after 00:00)" << endl;
                cout << "renew the info" << endl;
            }
        }
    }

}

int check_time_for_santas(int i, int j, Santa* a, int n)
{
    int x, y;

    for(x = 0; x < n; x++){
        for(y = 0; y < a[x].amount_of_visits; y++){
            if(a[x].visits[y].hour_of_start < i && a[x].visits[y].hour_of_finish > i){
                return 0;
            }
            else if(a[x].visits[y].hour_of_start == i && (a[x].visits[y].minute_of_start <= j)){
                return 0;
            }
            else if(a[x].visits[y].hour_of_finish == i && (a[x].visits[y].minute_of_finish >= j)){
                return 0;
            }
        }
    }

    return 1;

}

void print_info_about_list(List* list, int n_for_list)
{
    int i;
    
    cout << "info about visits for tea(amount is " << n_for_list << "):" << endl;
    for(i = 0; i < n_for_list; i++, list = list->next){
        list->tea_visit.print();

    }
}
int find_the_answer(Santa* a, int n)
{
    int i, j, k, fl = 0, counter = 0, n_for_list = 0;
    List *list;
    List *head;

    list = (struct List*)malloc(sizeof(struct List));
    head = list;

    for(i = 0; i < 24; i++){
        for(j = 0; j < 60; j++){
            if(check_time_for_santas(i, j, a, n) && fl == 0){
              list->tea_visit.hour_of_start = i;
              list->tea_visit.minute_of_start = j;
              fl = 1; 
            }
            else if(check_time_for_santas(i, j, a, n) && fl == 1 && i == 23 && j == 60){
                counter++;
                list->tea_visit.time_for_visit = counter;
                counter = 0;
                list->tea_visit.set_visit();
                list->next = (struct List*)malloc(sizeof(struct List));
                list = list->next;
                n_for_list += 1;
                fl = 0;

            }
            else if(check_time_for_santas(i, j, a, n) && fl == 1){
                counter++;
            }
            else if(check_time_for_santas(i, j, a, n) != 1 && fl == 1){
                list->tea_visit.time_for_visit = counter;
                counter = 0;
                list->tea_visit.set_visit();
                list->next = (struct List*)malloc(sizeof(struct List));
                list = list->next;
                n_for_list += 1;
                fl = 0;
            }

        }
    }
    if(n_for_list == 0){
        cout << "Santas don`t even have a time to drink a tea(" << endl;
        return 0;
    }
    print_info_about_list(head, n_for_list);
    return 1;
}