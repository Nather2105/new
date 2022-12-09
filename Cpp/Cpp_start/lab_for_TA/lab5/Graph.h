//   1 2 3 4 5 6 7 
// 1 0 1 1 1 0 0 0 
// 2 1 0 1 0 1 1 0 
// 3 1 1 0 1 1 0 0 
// 4 1 0 1 0 0 0 0 
// 5 0 1 1 0 0 0 1 
// 6 0 1 0 0 0 0 1 
// 7 0 0 0 0 1 1 0 

#ifndef Graph_h
#define Graph_h


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
        int find_the_answer();


};

#endif