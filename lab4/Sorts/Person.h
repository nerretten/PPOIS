#ifndef LAB4_PERSON_H
#define LAB4_PERSON_H
#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    Person() = default;
    Person(const std::string& n, int a) : name(n), age(a) {}

    bool operator<(const Person& other) const {
        if (age != other.age) return age < other.age;
        return name < other.name;
    }


    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "{" << p.name << ", " << p.age << "}";
        return os;
    }
};

#endif
