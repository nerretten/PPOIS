#include "Car.h"
#include "../exceptions.h"

Car::Car() = default;
Car::Car(const std::string &make, const std::string &model, int year, const std::string &vin):
        make(make), model(model), year(year), vin(vin) {}

const std::string& Car::get_make() const{
    return make;
}
const std::string& Car::get_model () const{
    return model;
}
const std::string& Car::get_vin() const{
    return vin;
}
int Car::get_year() const{
    return year;
}
void Car::set_make(const std::string &s){
    make = s;
}
void Car::set_model(const std::string &s){
    model = s;
}
void Car::set_vin(const std::string &s){
    vin = s;
}
void Car::set_year(int x){
    year = x;
}
void Car::validate() const{
    if(vin.empty() || year>2025 || year < 1900){
        throw InvalidCarException();
    }
}