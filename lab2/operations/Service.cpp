#include "Service.h"

Service::Service(const std::string& name, double base_price, int estimated_minutes):
        name(name), base_price(base_price), estimated_minutes(estimated_minutes){}
const std::string& Service::get_name() const{
    return name;
}
double Service::get_base_price() const{
    return base_price;
}
int Service::get_estimated_minutes() const{
    return estimated_minutes;
}
void Service::set_name(const std::string& s) {
    name=s;
}
void Service::set_base_price(double x) {
    base_price=x;
}
void Service::set_estimated_minutes(int x) {
    estimated_minutes = x;
}