#include "Engine.h"

Engine::Engine(double displacement, const std::string& fuel_type, int horse_power):
        displacement(displacement), fuel_type(fuel_type), horse_power(horse_power){}
double Engine::get_displacement() const{
    return displacement;
}
const std::string& Engine::get_fuel_type() const{
    return fuel_type;
}
int Engine::get_horse_power() const{
    return horse_power;
}
void Engine::set_displacement(double x){
    displacement = x;
}
void Engine::set_fuel_type(const std::string& s){
    fuel_type = s;
}
void Engine::set_horse_power(int x){
    horse_power = x;
}