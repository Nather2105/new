#include <iostream>
#include <cstring>
#include <cmath>
#include <limits>

using namespace std;

struct Segment {
    string number;
    string name;
    Segment *next;

    Segment() { next = nullptr; }

    Segment(string Number, string Name) {
        number = Number;
        name = Name;
        next = nullptr;
    }

    ~Segment() { delete[] next; }
};

ostream &operator<<(ostream &os, Segment *names) {
    Segment *temp = names;

    os << "(";
    while (temp) {
        os << temp->number;
        if (temp->next != nullptr) os << ", ";
        else os << ")";
        temp = temp->next;
    }

    return os;
}

class HashTable {
    private:
        int size;
        Segment **Table;

    public:
        HashTable(int size);
        ~HashTable();

        int hash(string x);
        void insert(string number, string name);
        bool find_number(string number);
        void find_number_return(string number);
        void del(string number);
        void reset();
        void restruct(int new_size);
        string get(string number);
        void output();
};

int main() {
    int n, option, new_size;
    string temp_name, temp_number;

    cout << "Введіть кількість сегментів у геш-таблиці: ";
    cin >> n;

    HashTable Results(n);

    cout << "1 - Знайти елемент" << endl;
    cout << "2 - Вставити новий елемент" << endl;
    cout << "3 - Видалити елемент" << endl;
    cout << "4 - Реструктуризувати таблицю" << endl;
    cout << "5 - Вивести таблицю на екран" << endl;
    cout << "6 - Вихід" << endl;

    do {
        cout << endl << "Що ви хочете зробити? Введіть відповідний номер: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Номер телефону: ";
                cin >> temp_number;
                if(Results.find_number(temp_number) == 1){
                    Results.find_number_return(temp_number);
                }
                else{
                    cout << "Не знайдено!" << endl;
                }
                break;
            
            case 2:
                cout << "Номер телефону: ";
                cin >> temp_number;
                cin.ignore();
                cout << "Прізвище та ім'я: ";
                getline(cin, temp_name);
                Results.insert(temp_number, temp_name);
                break;

            case 3:
                cout << "Прізвище та ім'я студента: ";
                cin >> temp_number;
                Results.del(temp_number);
                break;

            case 4:
                cout << "Нова кількість сегментів у таблиці: ";
                cin >> new_size;
                Results.restruct(new_size);
                break;
            
            case 5:
                Results.output();
                break;

            default:
                exit(0);
        }
    } while (option != 5);

    return 0;
}

HashTable::HashTable(int size) {
    this->size = size;
    Table = new Segment *[size];
    reset();
}

HashTable::~HashTable() {
    delete[] Table;
}

void HashTable::reset() {
    for (int i = 0; i < size; i++) {
        Table[i] = nullptr;
    }
}

bool HashTable::find_number(string x) {
    Segment *current = Table[hash(x)];
    while (current != nullptr && current->number.find(x) == string::npos) {
        current = current->next;
    }

    if (current == nullptr) return false;
    else return true;
}

void HashTable::find_number_return(string x){
    Segment *current = Table[hash(x)];
    string temp;
    while (current != nullptr) {
        if(current->number.find(x) != string::npos){
            cout << current->number << " - " << current->name << endl;
        }
        current = current->next;
    }
}

void HashTable::insert(string number, string name) {
    Segment *temp;
    int index = hash(number);

    if (!find_number(number)) {
        if (Table[index] == nullptr) {
            temp = new Segment(number, name);
            Table[index] = temp;
        }
        else {
            temp = Table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Segment(number, name);
        }
    }
}

void HashTable::del(string number) {
    if (find_number(number)) {
        int index = hash(number);

        if (Table[index]->number == number) {
            Table[index] = Table[index]->next;
        }
        else {
            Segment *temp = Table[index];
            while (temp->next != nullptr && temp->next->number != number) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }
}

void HashTable::restruct(int new_size) {
    HashTable NewTable(new_size);
    Segment *temp;

    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < size; j++) {
            temp = Table[j];
            while (temp != nullptr) {
                NewTable.insert(temp->number, temp->name);
                temp = temp->next;
            }
        }
    }

    size = new_size;
    Table = new Segment *[new_size];
    reset();

    for (int i = 0; i < new_size; i++) {
        temp = NewTable.Table[i];
        while (temp != nullptr) {
            insert(temp->number, temp->name);
            temp = temp->next;
        }
    }
}

int HashTable::hash(string number) {
    int sum = 0;

    for (auto letter : number) {
        sum += letter;
    }
    
    return sum % size;
}

string HashTable::get(string number) {
    if (find_number(number)) {
        Segment *temp = Table[hash(number)];
        while (temp != nullptr && temp->number != number) {
            temp = temp->next;
        }

        return temp->name;
    }

    return 0;
}

void HashTable::output() {
    Segment *temp;
    for (int i = 0; i < size; i++) {
        if (Table[i] != nullptr) {
            cout << i << ": ";
            temp = Table[i];
            while (temp != nullptr) {
                cout << "(" << temp->number << " - " << temp->name << ")";
                if (temp->next != nullptr) cout << ", ";
                else cout << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

