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
    int count, k, max, sum = 0, i, j, l, r;
    for (k=0; k < n; k++) helper[k]=0;
    helper[0] = 1; count=0; 
    while (count < n-1)
    {
        max=0;
        for (i = 0; i < n; i++)
        {
            if (helper[i]==1)
            for (j=0; j < n; j++)
            if (helper[j] == 0 && matrix[i][j] > max && matrix[i][j]>0)
            {
                    max=matrix[i][j]; l=i; r=j;
            } 
        }
        cout <<"("<< l+1 << ", " << r+1 << ")" << endl;
        helper[r]=1;
        count++;
        sum += max;
    }

    return sum;

}

