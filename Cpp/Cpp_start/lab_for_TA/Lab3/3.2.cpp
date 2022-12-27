// Варіант №2

// Розробити меню-орієнтовану програму, що реалізує побудову частотних словників для підтримки 
// інформаційної системи «Таксі» (номер машини, прізвище/ім’я водія, час замовлення).
// У програмі передбачити виведення інформації на запити про кількість замовлень на вказаний час, 
// кількість замовлень за вказаним номером машини, кількість замовлень за вказаним  прізвищем/ім’ям водія.


#include <iostream>
#include <vector>

using namespace std;

struct Info {
    string number, name, time;

    Info() {};
    
    Info(string Name, string Number, string Time) {
        number = Number;
        name = Name;
        time = Time;
    }
};

struct Dict {
    vector<Info> key;
    int count_number;
    int count_name;
    int count_time;
    Dict *left = nullptr;
    Dict *right = nullptr;

    Dict(Info x) : count_number(1) { key.push_back(x); }
};

void print(Dict *dict, string prefix = "", bool isTail = true, string sb = "");
void search(Info x, Dict* &dict);
Dict* locate(Info x, Dict* dict);
int get_number_count(Dict *dict, string number);
int get_name_count(Dict *dict, string name);
int get_time_count(Dict *dict, string time);


int main(int argc, char const *argv[]) {
    Dict *root = nullptr, *temp = nullptr;
    string x, t_number, t_name, t_time;
    Info input;
    int n, index = 1, option;

    cout << "1 - add new element" << endl;
    cout << "2 - find amount of offers by time" << endl;
    cout << "3 - find amount of offers by number of car" << endl;
    cout << "4 - find amount of offers by name" << endl;
    cout << "5 - output of info" << endl;
    cout << "6 - exit" << endl;

    do {
        cout << endl << "what would you like to do: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << endl;

                cout << "input number of car #" << index << " ";
                cin >> input.number;
                cin.ignore();

                cout << "input name of driver #" << index << " ";
                getline(cin, t_name);
                input.name = t_name;

                cout << "input time of offer for person #" << index << " ";
                cin >> input.time;

                search(input, root);
                index++;

                break;

            case 2: 
                cout << "input time: ";
                cin >> t_time;

                if(get_time_count(root, t_time) != -1){
                    cout << "amount of offers for current time: " << get_time_count(root, t_time) << endl;
                }
                else{
                    cout << "didn't find" << endl;
                }
                break;
            
            case 3:
                cout << "input number of car: ";
                cin >> t_number;

                
                if(get_number_count(root, t_number) != -1){
                    cout << "amount of offers for number of car: " << get_number_count(root, t_number) << endl;
                }
                else{
                    cout << "didn't find" << endl;
                }
                break;

            case 4:
                cin.ignore();
                cout << "input name of driver: ";
                getline(cin, t_name);

                if(get_name_count(root, t_name) != -1){
                    cout << "amount of offers by name: " << get_name_count(root, t_name) << endl;
                }
                else{
                    cout << "Не знайдено!" << endl;
                }
                break;
            
            case 5:
                cout << endl;
                print(root);
                break;

            default:
                exit(0);
                break;
        }       
    } while(option != 6);

    return 0;
}

void print(Dict *dict, string prefix, bool isTail, string sb) {
    if (dict->right != nullptr) {
        print(dict->right, prefix + (isTail ? " │   " : "     "), false, sb);
    }

    string temp = prefix + (isTail ? " └── " : " ┌── ") + dict->key[0].number + " " + dict->key[0].name + " " + dict->key[0].time + "\n";
    sb += temp;
    cout << temp;

    if (dict->left != nullptr) {
        print(dict->left, prefix + (isTail ? "     " : " │   "), true, sb);
    }
}

void search(Info x, Dict* &dict) {
    if (dict == nullptr) {
        dict = new Dict(x);
    }
    else {
        if (x.number < dict->key[0].number) search(x, dict->left);
        else if (x.number > dict->key[0].number) search(x, dict->right);
        else {
            dict->count_number++;
            dict->key.push_back(x);
        }
        if (x.name < dict->key[0].name) search(x, dict->left);
        else if (x.name > dict->key[0].name) search(x, dict->right);
        else {
            dict->count_name++;
            dict->key.push_back(x);
        }
        if (x.time < dict->key[0].time) search(x, dict->left);
        else if (x.time > dict->key[0].time) search(x, dict->right);
        else {
            dict->count_time++;
            dict->key.push_back(x);
        }
    }
}

int get_number_count(Dict *dict, string number) {
    Dict *temp = dict;

    while (temp != nullptr) {
        if (temp->key[0].number < number) temp = temp->right;
        else if (temp->key[0].number > number) temp = temp->left;
        else {
            for (int i = 0; i < temp->key.size(); i++) {
                if (temp->key[i].number == number) 
                    return temp->count_number;
            }
        }
    }

    return -1;
}
int get_name_count(Dict *dict, string name) {
    Dict *temp = dict;

    while (temp != nullptr) {
        if (temp->key[0].name < name) temp = temp->right;
        else if (temp->key[0].name > name) temp = temp->left;
        else {
            for (int i = 0; i < temp->key.size(); i++) {
                if (temp->key[i].name == name) 
                    return temp->count_name + 1;
            }
        }
    }

    return -1;
}
int get_time_count(Dict *dict, string time) {
    Dict *temp = dict;

    while (temp != nullptr) {
        if (temp->key[0].time < time) temp = temp->right;
        else if (temp->key[0].time > time) temp = temp->left;
        else {
            for (int i = 0; i < temp->key.size(); i++) {
                if (temp->key[i].time == time) 
                    return temp->count_time + 1;
            }
        }
    }

    return -1;
}


