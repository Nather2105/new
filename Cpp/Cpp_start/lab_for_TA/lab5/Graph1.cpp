#include <iostream>
#include <fstream>
using std::ifstream;
using namespace std;
#include <cstdlib>
#include <math.h>

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
    int m1, i, j, x, y, z, e;
    info.open("1.txt");
     if(!info) {
       printf("Cannot open file.");
       return 0;
    }
    
    info >> n;
    info >> m1;

    get_memory_matrix();

    for(i = 0;i < n;i++){
        for(j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    for(i = 0; i < m1; i++){
        info >> x;
        info >> y;
        info >> z;
        info >> e;
        matrix[x][y] = abs(z + e);
        matrix[y][x] = abs(z + e);
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
int Graph::find_the_answer()
{
    int i, j, k, min = 66535, route, route1_a, route2_a;

    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            if(matrix[k][i] == 0){
                continue;
            }
            for(j = i + 1; j < n; j++){
                if(matrix[k][j] == 0){
                    continue;
                }
                if(matrix[k][i] + matrix[k][j] < min){
                    min = matrix[k][i] + matrix[k][j];
                    route = k + 1;
                    route1_a = i + 1;
                    route2_a = j + 1;
                }
            }
        }
    }

    cout << "short route is (" << route << ", " << route1_a << ")" << " + ";
    cout << "(" << route << ", " << route2_a << ")" << endl;
    return min;

}

