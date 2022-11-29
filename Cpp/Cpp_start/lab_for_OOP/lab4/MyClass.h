#ifndef MyClass_h
#define MyClass_h

class MyClass
{
    private:
        float *arr;
        int n;

    public:
        friend float* input(int); //done
        MyClass(int); //done
        MyClass(); //done
        ~MyClass(); //done
        void print_xs(); //done
        float get_the_answer(float); //done
        MyClass& pohidna(); //done
        void pqx(); //done
        void xbpx(); //done
        void pxb(); //done
        friend MyClass operator+(MyClass, MyClass); //done
        friend MyClass operator-(MyClass, MyClass); //done
        friend MyClass operator*(MyClass, MyClass); //done
        MyClass& operator=(MyClass&); //done
        friend MyClass copy(MyClass*, MyClass); //done
        friend void div_mnogo(MyClass, MyClass); // done

};

#endif