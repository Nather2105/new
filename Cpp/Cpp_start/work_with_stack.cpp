#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout << "Inpun N ";
    int n, i;
    cin >> n;
    int a[100];
    srand(time(0));
    int head, last;
    head = -1;
    while (++head < n){
        a[head] = rand() % 100 - 20;
    }

    for (i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    cout << "\n" << "Stack: \n";
    head--;
    int b[100];
    int head_new = 0;

    do{
        cout << a[head] << " ";
        if (a[head] < 0)
        {
            b[head_new] = a[head];
            head_new++;
        }
    } while (head-- > 0);

    cout << "\n";
    cout << "Stack new: \n";
    head_new--;
    if (head_new < 0){
        cout << "Stack is empty ";
    }
    else{
        do{
            cout << b[head_new] << " ";
        } while (head_new-- > 0);
    }
    
    cout << "\n";
    // system("PAUSE");
    return EXIT_SUCCESS;
}