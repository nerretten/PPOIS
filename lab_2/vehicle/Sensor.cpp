#include "Sensor.h"


Sensor::Sensor(const std::string &type_, double value_, bool ok_): type(type_), value(value_), ok(ok_) {}
double Sensor::read() {
    if (!ok) throw std::runtime_error("Sensor malfunction");
    return value;
}
void Sensor::calibrate(double offset){
    value += offset;
}
bool Sensor::selfTest(){
    return ok;
}
const std::string& Sensor::getType() const{
    return type;
}
