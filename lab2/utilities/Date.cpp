#include "Date.h"

bool Date::is_valid(int d, int m, int y){
    if(m > 12 || m < 1)
        return false;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
                           31, 30, 31};
    if((y % 100 != 0 && y % 4 == 0) || (y%400==0))
        days_in_month[1] = 29;
    if(d > days_in_month[m-1] || d < 1)
        return false;
    return true;
}

Date::Date(int d, int m, int y){
    if(is_valid(d, m, y)){
        day = d;
        month = m;
        year = y;
    }
    else
        throw InvalidDateException();
}