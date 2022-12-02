#include <iostream>
#include <string>
#include <list>
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
    out << t.name << " " << t.size << " -> ";
    return out;
}

class Tabel { // хеш-таблиця
private:
    list<File> list[10]; // список на 10 елементів, в якому будуть зберігатись елементи таблиці
    
    double const C = 0.7; // random constant
    int const mult = 10; // size of table
    
    int function(char*); // get hash for item
    
public:
    
    void add(File);
    
    void output(char*);
    
};

int Tabel::function(char* fileName) {
    int key = 0;
    
    for (int i = 0; i < strlen(fileName); i++) { // пошук суми ASCII кодів із сиволів назви файла
        key += fileName[i];
    }
    
    
    return mult * ((key * C) - (int)(key * C)); // пошук ключа методом множення
}

void Tabel::add(File t) { // додавання нового елемента в таблицю
    list[function(t.name)].push_back(t);
}

void Tabel::output(char* name){ // вивід елементів таблиці, що мають такий ж ключ, що й name
    int hash = function(name);
    
    for (File ticket : list[hash]) {
        cout << ticket << "hash: " << hash << endl;
    }
}

int main() {
    srand(time(0));
    
    Tabel tabel;
    
    for (int i = 0; i < 30; i++) { // рандомне заповнення
        File elem;
        
        elem.name = new char[5];
        elem.name[0] = rand() % ('A' - 'Z') + 'A';
        for (int i = 1; i < 5; i++) elem.name[i] = rand() % ('a' - 'z') + 'a';
        
        elem.size = rand() % 100;
        elem.countReq = rand() % 100;
        elem.date = time(0);
        
        cout << i <<  ")" << elem << endl;
        tabel.add(elem);
    }
    
    char* fileName = new char(50);
    
    while (true) {
        cout << "Input name of file: " << endl;
        cin >> fileName;
        
        tabel.output(fileName);
    }

}
