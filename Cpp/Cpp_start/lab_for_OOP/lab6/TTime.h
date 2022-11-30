#ifndef TTime_h
#define TTime_h

class TTime : public TTriad
{
    private:
        int hours;
        int minutes;
        int seconds;
    
    public:
        TTime(int, int, int);
        TTime();
        void increase_first();
        void increase_second();
        void increase_third();
        void triple_print();
};

#endif