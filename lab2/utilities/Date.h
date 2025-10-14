#ifndef LAB2_DATE_H
#define LAB2_DATE_H
#include "../exceptions.h"

class Date{
private:
    int day;
    int month;
    int year;
    bool is_valid(int d, int m, int y);
public:
    Date(int d, int m, int y);
};

#endif
