#include "Mechanic.h"

Mechanic::Mechanic(const std::string& name, const std::string& specialization, int experiance_years):
        name(name), specialization(specialization), experiance_years(experiance_years){}
const std::string& Mechanic::get_name() const{ return name;}
const std::string& Mechanic::get_specialization() const{ return specialization; }
const int Mechanic::get_experiance_years() const { return experiance_years; }
void Mechanic::set_name(const std::string& s){
    name = s;
}
void Mechanic::set_specialization(const std::string& s){
    specialization = s;
}
void Mechanic::set_experiance_years(int x){
    experiance_years = x;
}

void Mechanic::use_tool(Tool &t) {
    if(!t.get_is_available())
        throw ToolUnavailableException();
    t.use();
}