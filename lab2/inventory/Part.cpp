#include "Part.h"

Part::Part(const std::string& name, double price, const std::string& manufacturer):
        name(name), price(price), manufacturer(manufacturer){}
const std::string& Part::get_name() const{return name;}
double Part::get_price() const{ return price;}
const std::string& Part::get_manufacturer() const {return manufacturer;}
void Part::set_name(const std::string& s){
    name = s;
}
void Part::set_price(double x){
    price = x;
}
void Part::set_manufacturer(const std::string& s){
    manufacturer = s;
}