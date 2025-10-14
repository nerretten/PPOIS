#ifndef LAB2_CAR_H
#define LAB2_CAR_H
#include <string>


class Car{
private:
    std::string make;
    std::string model;
    int year;
    std::string vin;
public:
    Car();
    Car(const std::string &make, const std::string &model, int year, const std::string &vin);
    const std::string& get_make() const;
    const std::string& get_model () const;
    const std::string& get_vin() const;
    int get_year () const;
    void set_make(const std::string &s);
    void set_model(const std::string &s);
    void set_vin(const std::string &s);
    void set_year(int x);
    void validate() const;
};

#endif
