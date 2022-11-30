#ifndef TDate_h
#define TDate_h

class TDate
{
    private:
        int day;
        int month;
        int year;

    public:
        TDate(int, int, int);
        TDate();
        void increase_first();
        void increase_second();
        void increase_third();
        void triple_print();
};

#endif