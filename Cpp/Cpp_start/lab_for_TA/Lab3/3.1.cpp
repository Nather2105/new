// Варіант №15

// Створити хеш-таблицю «Файли на диску», елементами якої є ім'я файлу, розмір, дата створення, 
// кількість звернень, використавши хеш-функцію за методом множення за сумою ASCI-кодів букв
// назв файлів для розбиття інформації на сегменти. Передбачити виведення інформації про всі файли,
// які містяться у тому ж сегменті-списку, що і файл з вказаною назвою, коректування хеш-таблиці, 
// виведення поточного стану хеш-таблиці та її реструктуризацію.

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct File { // структура файла
    char *name;
    int size;
    int countReq;
    time_t date;
    
    friend ostream& operator <<(ostream& out, File); // перегрузка оператора виводу
};

ostream& operator <<(ostream& out, File t){
    out << t.name << " " << "-> "  << "size is " << t.size << ", amount of requests is " << t.countReq << endl;
    return out;
}

struct Segment{
    struct File element;
    struct Segment *next;
};

class Tabel { // хеш-таблиця
private:
    struct Segment *list; // список на 10 елементів, в якому будуть зберігатись елементи таблиці
    
    double const C = 0.7; // random constant
    int mult; // size of table
    int n;
    
    int h(char*); // get hash for item
    
public:
    
    void set_n(int);
    void set_mult(int);
    void add(File);
    void MakeNull();
    void output(char*);
    void get_memory(int);
    void ins(File);
    int find(char*);
    void print();
    void restruct();
    void del(char*);
    
};

void Tabel::set_n(int n1)
{
    n = n1;
}
void Tabel::set_mult(int n)
{
    mult = n;
}

void Tabel::get_memory(int n)
{
    list = (struct Segment*)malloc(sizeof(struct Segment)* n);
}
int Tabel::h(char* fileName) {
    int key = 0;
    
    for (int i = 0; i < strlen(fileName); i++) { // пошук суми ASCII кодів із сиволів назви файла
        key += fileName[i];
    }
    
    
    return mult * ((key * C) - (int)(key * C)); // пошук ключа методом множення
}

void Tabel::MakeNull()
{ 
    int i;
    for (i=0; i<mult; i++){
        list[i].element.name=0;
        list[i].element.date = 0;
        list[i].element.countReq = 0;
        list[i].element.size = 0;
    }
}

int Tabel::find(char* name){
    struct Segment *q;
    q=&list[h(name)];
    while (q!=0 && q->element.name != name) q=q->next;  
    if (q==0) return 0; 
    else return 1;
 }


void Tabel::ins(File x)
{  int i; struct Segment *q; struct Segment *t;
    if (!find(x.name)) 
    {   i=h(x.name);
         if (list[i].element.name==0){
            list[i].element.name = x.name;
            list[i].element.countReq = x.countReq;
            list[i].element.date = x.date;
            list[i].element.size = x.size;
            list[i].next=(struct Segment*)malloc(sizeof(struct Segment));  // сегмент порожній, створюється сегмент 
            // cout << list[i].element << endl;
          
          }
         else                          // сегмент не порожній, новий елемент дописується у кінець
         {   q=&list[i];
            while (q->next!=0) q=q->next;
            q->element.name = x.name;
            q->element.countReq = x.countReq;
            q->element.date = x.date;
            q->element.size = x.size;
            q->next = (struct Segment*)malloc(sizeof(struct Segment));
            // cout << q->element << endl;
         }
    }

    
}

void Tabel::output(char* name){ // вивід елементів таблиці, що мають такий ж ключ, що й name
    int hash = h(name);
    int i;
    struct Segment *q;
    q = &list[hash];
    cout << "number of segment is " << hash << endl;
    while(q->element.name != 0){
        cout << q->element;
        q = q->next;
    }
}
int compare_for_strings(char* x1, char* x2)
{
    int i, j;
    i = strlen(x1);
    j = strlen(x2);
    if( i != j){
        return 0;
    }

    for(i = 0; i < j; i++){
        if(x1[i] != x2[i]){
            return 0;
        }
    } 

    return 1;


}
void Tabel::del (char* x)
{
    int i; struct Segment *q;
    i=h(x);
    if (compare_for_strings(list[i].element.name, x)){
        list[i] = *list[i].next;
    }
    else 
    {
        q=&list[i];
        while (q->next!=0 && compare_for_strings(q->next->element.name, x) == 0) q=q->next;
        q->next=q->next->next;
    }
    restruct();
 }

void Tabel::restruct()
{
     int i, j;
     struct Segment *q;
     File B[1000];
     j=0;
     for (i=0; i<=mult-1; i++){
        // cout << "hi" << endl;
        q =  &list[i];
        // cout << q->element; 
        while (q->element.name != 0)
         {
            // cout << "no" << endl;
            // cout << q->element;
              B[j].countReq = q->element.countReq;
              B[j].date=q->element.date;
              B[j].name=q->element.name;
              B[j].size=q->element.size;
            //   cout << B[j];
              j++;
              if(q->next == 0){
                break;
              }
              q=q->next;
         };
     }
     n=j--;
     mult=n/3;
     get_memory(mult);
     MakeNull();
     for (j=0; j<=n-1; j++) ins(B[j]); 
 }

void Tabel::print()
{

    int i; struct Segment *q; 
     
     for (i=0; i<=mult-1; i++){ 
        q=&list[i];
        while(q->element.name != 0){
            cout << q->element;
            cout << endl;
            if(q->next == 0){
                break;
            }
                q = q->next;
        }
        
    }
}

void Tabel::add(File t) { // додавання нового елемента в таблицю
    ins(t);
    restruct();
    // print();    
}

int main() {
    srand(time(0));
    
    Tabel tabel;
    int n;
    cout << "input n:" << endl;
    cin >> n;

    tabel.set_n(n);
    tabel.get_memory(n/3);
    tabel.set_mult(n/3);
    tabel.MakeNull();
    for (int i = 0; i < n; i++) { // рандомне заповнення
        File elem;
        
        elem.name = new char[5];
        elem.name[0] = rand() % ('A' - 'Z') + 'A';
        for (int i = 1; i < 5; i++) elem.name[i] = rand() % ('a' - 'z') + 'a';
        
        elem.size = rand() % 100;
        elem.countReq = rand() % 100;
        elem.date = time(0);
        
        cout << i <<  ")" << elem << endl;
        tabel.ins(elem);
    }
    
    // tabel.print();
    char* fileName = new char(50);
    int waiter = 0;
    while (waiter != 5) {
        
        cout << "what you would like to do?" << endl;
        cout << "1 - find a segment by name of file inside" << endl;
        cout << "2 - add new file" << endl;
        cout << "3 - delete a file" << endl;
        cout << "4 - print info about files" << endl;

        cout << "5 - exit" << endl;
        
        cin >> waiter;
        if(waiter == 1){
            cout << "Input name of file: " << endl;
            cin >> fileName;
            tabel.output(fileName);
        }
        else if(waiter == 2){
            File elem;
            elem.name = new char[5];
            elem.name[0] = rand() % ('A' - 'Z') + 'A';
            for (int i = 1; i < 5; i++) elem.name[i] = rand() % ('a' - 'z') + 'a';
            
            elem.size = rand() % 100;
            elem.countReq = rand() % 100;
            elem.date = time(0);
            
            cout << "new element is " << endl;
            cout << elem;

            tabel.add(elem);
        }
        else if(waiter == 3){
            cout << "Input name of file that you would like to delete: " << endl;
            cin >> fileName;
            tabel.del(fileName);
        }
        else if(waiter == 4){
            tabel.print();

        }
        else if(waiter == 5){
            return 0;
        }
        
    }
}
