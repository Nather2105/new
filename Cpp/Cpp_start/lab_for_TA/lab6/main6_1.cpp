// Варіант №15

// На залізничній станції є буфет, в якому лише один касовий апарат.
// На станції зупиняється багато поїздів, тому в буфеті завжди багато голодних пасажирів у черзі до каси.
// Буфетна каса обслуговує кожного пасажира за однаковий час.
// Частина пасажирів спізнюється на свої потяги й вимушена міняти білети. 
// Адміністрація буфета відшкодовує пов’язані з цим збитки і тому намагається зменшити їх розмір.
// Нехай N – кількість пасажирів у черзі, i – порядковий номер, наданий пасажиру на вході у буфет,
// di – час відправлення потяга у i-го пасажира, а wi – величина збитку, який понесе i-й пасажир,
// якщо спізниться на свій потяг. Домовимося, що каса обслуговує пасажира за одиничний час і в початковий момент
// час рівний нулеві, а також якщо i-го пасажира обслужили в момент часу di, то він не спізнюється.
// Необхідно поставити пасажирів у чергу в такому порядку, щоби сума можливих збитків була найменшою.


#include <iostream>
#include <fstream>
using std::ifstream;
using namespace std;
#include <cstdlib>


class Passenger
{
    private:

        int number;
        int waste_of_money;
        int time_for_train;
    public:

        Passenger(int, int);
        void set(int, int);
        friend int find_the_loss(Passenger*, int);
        friend int find_the_max(Passenger*, int, int);

        void print();


};

void get_memory_for_array(Passenger**, int);

int main()
{
    Passenger *array;
    int n, i, x, y, loss;

    cout << "Input n:" << endl;
    cin >> n;
    get_memory_for_array(&array, n);

    for(i = 0; i < n; i++){
        cout << "input time for train for person #" << i+1 << ":" << endl;
        cin >> x;
        cout << "input waste of money for person #" << i+1 << ":" << endl;  
        cin >> y;
        array[i].set(x, y);
    }
    loss = find_the_loss(array, n);
    for(i = 0; i < n; i++){
        array[i].print();
    }

    cout << "current waste of money is " << loss << endl; 
}

Passenger::Passenger(int w, int t)
{
    waste_of_money = w;
    time_for_train = t;
    number = -1;
}

void get_memory_for_array(Passenger** a, int n)
{
    *a = (Passenger*)malloc(sizeof(Passenger) * n);
}

void Passenger::set(int t, int w)
{
    time_for_train = t; 
    waste_of_money = w;
    number = -1;
}

int find_the_max(Passenger* a, int n, int to)
{
    int i, max = 0, index = -1;

    for(i = 0; i < n; i++){
        if(a[i].time_for_train >= to && a[i].waste_of_money > max && a[i].number == -1){
            max = a[i].waste_of_money;
            index = i;
        }
    }

    return index;
}
int find_the_loss(Passenger* a, int n)
{   
    int i, finder, sum = 0;

    for(i = n - 1; i > 0; i--){
        finder = find_the_max(a, n, i);
        if(finder != -1){
            a[finder].number = i;
        }
    }

    for(i = 0; i < n; i++){
        if(a[i].number == -1){
            sum += a[i].waste_of_money;
        }
    }
    return sum;
}

void Passenger::print()
{
    cout << "waste of money if smth happen is " << waste_of_money << endl; 
    cout << "time for train is " << time_for_train << endl;
    cout << "number in a queue is " << number << endl;
}