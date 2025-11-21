#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <stdexcept>
class Sensor {
private:
    std::string type;
    double value;
    bool ok;
public:
    Sensor(const std::string &type_, double value_, bool ok_);
    double read();
    void calibrate(double offset);
    bool selfTest();
    const std::string& getType() const;
};
#endif

