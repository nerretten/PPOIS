#ifndef LAB2_ENGINE_H
#define LAB2_ENGINE_H
#include <string>

class Engine{
private:
    double displacement;
    std::string fuel_type;
    int horse_power;
public:
    Engine(double displacement, const std::string& fuel_type, int horse_power);
    double get_displacement() const;
    const std::string& get_fuel_type() const;
    int get_horse_power() const;
    void set_displacement(double x);
    void set_fuel_type(const std::string& s);
    void set_horse_power(int x);
};


#endif
