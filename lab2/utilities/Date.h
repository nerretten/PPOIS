#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

class InvalidDateException : public std::runtime_error {
public:
    InvalidDateException(const std::string& message) : std::runtime_error(message) {}
};

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y);
    Date(std::string dateString);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    std::string toString() const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    int operator-(const Date& other) const;
};

#endif // DATE_H