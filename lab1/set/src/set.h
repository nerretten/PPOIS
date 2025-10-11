#ifndef LAB1_SET_H
#define LAB1_SET_H

#include <iostream>
#include <vector>
#include <string>

bool is_balanced_braces(const std::string&s);


class Set{
private:
    std::vector <std::string> items;
    std::vector <Set> subsets;

public:
    Set();
    Set(const std::string& s);
    explicit Set(const char* str);

    bool is_empty() const;

    bool operator[](const std::string& s) const;
    bool operator[](const Set& s) const;

    void add_element(const std::string &s);
    void add_element(const Set& s);
    void delete_element(const std::string& s);
    void delete_element(const Set& set);
    int power() const;
    Set boolean() const;

    bool operator ==(const Set& set) const;
    bool operator !=(const Set& set) const;

    Set operator +(const Set& set) const;
    Set& operator +=(const Set& set);

    Set operator -(const Set& set);
    Set& operator -=(const Set& set);

    Set operator *(const Set& set) const;
    Set& operator *=(const Set& set);

    friend std::ostream& operator<<(std::ostream& os, const Set& s);
    friend std::istream& operator>>(std::istream& os, Set& s);

};

void check_comma(int& lst, Set &s, const std::string& new_s, int i, int cnt_open);
void check_open_brace(const std::string& new_s, int i, int& cnt_open, int &pos_open);
void check_close_brace(const std::string& new_s, int &cnt_close, int &cnt_open, int &i, Set& s, int&pos_open, int& lst);
#endif
