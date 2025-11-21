#include "Inspection.h"

Inspection::Inspection(const std::string &ins, bool p, int issues): inspector(ins), passed(p), issuesFound(issues) {}
void Inspection::run(){
    passed = (issuesFound==0);
}
void Inspection::failWith(int n){
    issuesFound = n; passed = false;
}
std::string Inspection::report() const {
    return passed ? "OK" : "ISSUES";
}

