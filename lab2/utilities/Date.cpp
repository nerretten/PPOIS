#include "Date.h"
#include <sstream>
#include <iomanip>
#include <cmath>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (d < 1 || d > 31 || m < 1 || m > 12) {
        throw InvalidDateException("Invalid date: " + std::to_string(day) + "/" + std::to_string(month)
        + "/" + std::to_string(year));
    }
}

Date::Date(std::string dateString) {
    std::istringstream iss(dateString);
    char dash;
    if (!(iss >> year >> dash >> month >> dash >> day)) {
        throw InvalidDateException("Invalid date format: " + dateString);
    }
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        throw InvalidDateException("Invalid date: " + dateString);
    }
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << year << "-"
        << std::setw(2) << month << "-"
        << std::setw(2) << day;
    return oss.str();
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}


int toDays(const Date& date) {
    int days = date.getDay();
    for (int m = 1; m < date.getMonth(); ++m) {
        days += daysInMonth(m, date.getYear());
    }

    int years = date.getYear();
    days += years * 365;

    days += years / 4 - years / 100 + years / 400;

    return days;
}

int Date::operator-(const Date& other) const {
    int days1 = toDays(*this);
    int days2 = toDays(other);
    return std::abs(days1 - days2);
}