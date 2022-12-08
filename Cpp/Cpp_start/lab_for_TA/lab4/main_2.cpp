// Варіант №15

// Закоханий студент хоче провести свою кохану через усі кав’ярні міста.
// Він пообіцяв дорогою між будь-якими двома кав’ярнями у кожної квіткарки купувати по одній троянді.
// Оскільки він не може зекономити на кав’ярнях, по залишається лише мінімізувати кількість куплених троянд. 
// Допоможіть студенту знайти такий шлях відвідування кав’ярень, який максимально зекономить його кошти на купівлі троянд.
// Відомо, що у місті є n (1<n≤100) кав’ярень та m (1≤m≤1000) можливих переходів між ними. 
// На кожному такому переході (i,j), де i,j=1,2,3…,n, стоять w квіткарок троянд.

#include <iostream>
#include <fstream>
using std::ifstream;
using namespace std;
#include <cstdlib>

//   1 2 3 4 5 6 7 
// 1 0 3 2 4 9 8 1 
// 2 3 0 8 2 4 1 9 
// 3 2 8 0 2 6 5 4 
// 4 4 2 2 0 6 7 8 
// 5 9 4 6 6 0 8 8 
// 6 8 1 5 7 8 0 9 
// 7 1 9 4 8 8 9 0 


class Graph
{
    public:
        int n;
        int **matrix;
        int *helper;
        void get_memory_matrix();
        void get_memory_for_helper();
        void fill_zeros_for_helper();
        void print_the_helper();
        int create_and_fill_the_matrix();
        void print_the_matrix();
        int helper_do_not_have_it(int);
        Graph();
        ~Graph();
        int find_the_index(int);
        int find_the_answer();


};



int main()
{
    Graph graph;
    int ans;
    ans = graph.find_the_answer();
    
    cout << "min sum of roses is " << ans << endl;
     


}

void Graph::get_memory_matrix()
{
    int i;
    
    matrix = (int**)malloc(n * sizeof(int*)); 
    
    for(i=0;i<n;i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
}


void Graph::get_memory_for_helper()
{
    helper = (int*)malloc(n * sizeof(int));
}

void Graph::fill_zeros_for_helper()
{
    int i;
    
    for(i = 0; i < n; i++){
        helper[i] = 0;
    }
}

void Graph::print_the_helper()
{
    int i;
    cout << endl;
    for(i = 0; i < n; i++){
        cout << helper[i] << " ";
    }
    cout << endl;
}
void Graph::print_the_matrix()
{
    int i, j;
    cout << "  ";
    for(i = 0; i < n; i++){
        cout << i+1 << " ";
    }
    cout << endl;
    for(i = 0; i < n; i++){
        cout << i+1 << " ";
        for(j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int Graph::create_and_fill_the_matrix()
{
    ifstream info;
    int m1, i, j, x, y, d;
    info.open("input.txt");
     if(!info) {
       printf("Cannot open file.");
       return 0;
    }

    info >> n;
    info >> m1;


    get_memory_matrix();

    for(i=0;i<n;i++){
        for(j=0;j<n;j++) matrix[i][j] = 0;
    }

    for(i=0;i<m1;i++){
        info >> x;
        info >> y;
        info >> d;
        matrix[x][y] = matrix[y][x] = d;
    }
    print_the_matrix();
    return 1;

}

Graph::Graph()
{
    create_and_fill_the_matrix();
    get_memory_for_helper();
    fill_zeros_for_helper();
    
}
Graph::~Graph()
{
    delete[] matrix;
}

int Graph::helper_do_not_have_it(int j)
{
    int x;

    for(x = 0; x < n; x++){
        if(helper[x] - 1 == j) return 0;
    }
    return 1;
}
int Graph::find_the_answer()
{
    int i, k, j, index_of_min, sum = 0, counter_for_helper = 0, min, cor_index;

    helper[counter_for_helper++] = 1;
    min = matrix[0][1];
    index_of_min = 1;
    for(k = 0, i = helper[k] - 1; k < n - 1; k++, i = helper[k] - 1){
        for(j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(matrix[i][j] < min && helper_do_not_have_it(j) == 1){
                min = matrix[i][j];  
                index_of_min = j;
            }
        }

        sum += min;
        helper[counter_for_helper++] = index_of_min + 1;
        if(k != n - 2){
            cor_index = find_the_index(index_of_min);
            min = matrix[index_of_min][cor_index];
            index_of_min = cor_index;
        }
    }
    print_the_helper();
    return sum;
}

int Graph::find_the_index(int index)
{
    int s;
    for(s = 0; s < n; s++){
        if(helper_do_not_have_it(s) && s != index){
            return s;
        } 
    }
    return 0;
}


