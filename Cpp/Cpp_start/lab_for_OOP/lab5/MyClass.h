#ifndef MyClass_h
#define MyClass_h

class MyClass
{
    private:
        float *arr;
        int n;

    public:
        float* input(int); //done
        MyClass(int); //done
        MyClass(); //done
        ~MyClass(); //done
        void print_xs(); //done
        float get_the_answer(float); //done
        MyClass& pohidna(); //done
        void pqx(); //done
        void xbpx(); //done
        void pxb(); //done
        MyClass& operator*(MyClass&); //done
        MyClass& operator+(MyClass&); //done
        MyClass& operator-(MyClass&); //done
        MyClass& operator=(MyClass&); //done
        friend MyClass copy(MyClass*, MyClass); //done
        friend void div_mnogo(MyClass, MyClass); // done
        
        int get_n(); //done
        void set_n(int); //done
        void set_arr(); //done
        float* get_arr(int); //done
        float get_part_of_arr(int); //done
        void set_part_of_arr(float, int); //done
};

#endif