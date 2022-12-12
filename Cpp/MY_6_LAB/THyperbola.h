#ifndef THyperbola_h
#define THyperbola_h


class THyperbola: public TFunction
{
    private:
        int a;
        int b;
        

    public:
        THyperbola(int, int);
        THyperbola();
        void print();
        float get_answer(int x);
};

#endif