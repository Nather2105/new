// Варіант №15

// Задана карта метрополітену деякого міста m (1<m≤1000) парами відповідних n (1<n≤100) станцій,
// серед яких є пересадочні станції. Необхідно визначити, за яку найменшу кількість пересадок 
// між різними лініями можна добратися зі станції i на станцію j або повідомити, що це зробити не можливо.

#include <iostream>
#include <fstream>
using std::ifstream;
using namespace std;
#include <cstdlib>

//   1 2 3 4 5 6 7 
// 1 0 1 1 1 0 0 0 
// 2 1 0 1 0 1 1 0 
// 3 1 1 0 1 1 0 0 
// 4 1 0 1 0 0 0 0 
// 5 0 1 1 0 0 0 1 
// 6 0 1 0 0 0 0 1 
// 7 0 0 0 0 1 1 0 


class Graph
{
    public:
        int n;
        int **matrix;
        int *road;
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
        int find_the_answer(int, int);


};



int main()
{
    Graph graph;
    int ans;
    ans = graph.find_the_answer(1, 7);
    if(ans){
        cout << "it is possible" << endl;
        cout << ans << " peresadok for short way" << endl;  
    }
    else{
        cout << "it is impossible" << endl;
    }


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
    // FILE *info;
    ifstream info;
    int m1, i, j, x, y;
    info.open("info.txt");
     if(!info) {
       printf("Cannot open file.");
       return 0;
    }

    info >> n;
    info >> m1;


    get_memory_matrix();

    for(i=0;i<n;i++){
        for(j=0;j<n;j++) matrix[i][j]=0;
    }

    for(i=0;i<m1;i++){
        info >> x;
        info >> y;
        matrix[x][y] = matrix[y][x] = 1;
    }
    print_the_matrix();
    return 1;

}

Graph::Graph()
{
    create_and_fill_the_matrix();
    get_memory_for_helper();
    fill_zeros_for_helper();
    print_the_helper();
    
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
int Graph::find_the_answer(int start, int finish)
{
    int i, k, j, counter_for_helper = 0, counter_for_road = 1, counter = 0, main = 0;

    helper[counter_for_helper++] = start;
    for(k = 0, i = helper[k] - 1; i != finish - 1; k++, i = helper[k] - 1){
        counter_for_road--;
        for(j = 0; j < n; j++){
            if(matrix[i][j] == 1 && helper_do_not_have_it(j) == 1){
                helper[counter_for_helper++] = j + 1;
                counter++;
            }
        }
        if(counter_for_road == 0){
            counter_for_road = counter;
            counter = 0;
            main++;
        }
    }
    if(i == finish - 1){
        return main;
    }
    else{
        return 0;
    }

}

