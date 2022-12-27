// Робота Куриляка Назарія (211 група)
//Стек заповнений однозначними і двозначними числами.Помістити однозначні числа в початок стека, двозначні - в кінець.
//Створити копію черги, елементи якої розміщені у зворотному порядку. Організувати перегляд елементів черги.
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int n, i, j, swapper, head = -1, tail = 0, k;
    int *a, *reversed, *two_numbers, *one_number; 
    srand(time(NULL));
    
    cout << "Inpun N ";
    cin >> n;
    a = new int[n];
    reversed = new int[n];
    two_numbers = new int[n];
    one_number = new int[n];

    while (++head < n){ // заповнення випадковим чином по умові: "Стек заповнений однозначними і двозначними числами."
        a[head] = rand() % 30;
    }

    for (i = 0; i < n; i++){ // вивід масиву а
        cout << a[i] << " ";
    }

    cout << "\n" << "Stack: \n";
    head--;

    do{ // вивід стеку на основі масиву а 
        cout << a[head] << " ";
    } while (head-- > tail);


    cout << "\n";
    cout << "Stack new: \n";
    for(head = n-1, j = 0, k = 0; head >= 0; head--){ // виконання умови:  "Помістити однозначні числа в початок стека, двозначні - в кінець."
        if (a[head] >= 0 && a[head] <= 9){
            one_number[j++] = a[head]; 
        }
        else{
            two_numbers[k++] = a[head]; 
        }
    }
    k--;
    j--;
    for(head = 0; head < n; head++){
        if(k != -1){
            reversed[head] =  two_numbers[k--];
            
        }
        else if(j != -1){
            reversed[head] =  one_number[j--];
            
        }
    }
    head--;
    do{ // вивід стеку
        cout << reversed[head] << " ";
    } while (head-- > tail);

////////////////////////////////////////////////

    int *turn, *steck, start, finish;
    cout << endl << "Inpun N ";
    cin >> n;
    turn = new int[n];
    steck = new int[n];
    head = -1;
    while (++head < n){ // створюємо чергу
        turn[head] = rand() % 30;
    }
    finish = n;
    for(start = 0; start < finish; start++){
        cout << turn[start] << " ";
    }
    tail = n;
    for(head = 0; head < tail; head++){
        steck[head] = turn[head];
    }
    for(head--, start = 0; start < finish; start++, head--){
        turn[start] = steck[head];
    }
    cout << endl << "reversed turn is " << endl;
    for(start = 0; start < finish; start++){
        cout << turn[start] << " ";
    }
}
