#ifndef Drib_h
#define Drib_h

class Drib
{
    private:
        MyClass *top;
        MyClass *bot;

    public:
          
        Drib(int, int); //done
        Drib(); //done
        ~Drib(); //done
        void print_drib(); //done
        float get_the_answer(float); //done
        Drib& pohidna(); //done
        void copy_for_drib(Drib&); // done
        void pow_for_drib(int); //done
        Drib& operator+(Drib&); //done
        Drib& operator-(Drib&); //done
        Drib& operator*(Drib&); //done
        friend void operator<<(ostream&, Drib&); //done


        

};

#endif