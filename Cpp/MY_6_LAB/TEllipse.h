#ifndef TEllipse_h
#define TEllipse_h

class TEllipse:public TFunction
{
    private:
        int a;
        int b;
        

    public:
        TEllipse(int, int);
        TEllipse();
        void print();
        float get_answer(int x);
};

#endif