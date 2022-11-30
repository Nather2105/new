#ifndef TTriad_h
#define TTriad_h

class TTriad
{
    private:
        int first;
        int second;
        int third;
    
    public:
        TTriad(int, int, int);
        TTriad();
        virtual void increase_first();
        virtual void increase_second();
        virtual void increase_third();
        virtual void triple_print();
};

#endif