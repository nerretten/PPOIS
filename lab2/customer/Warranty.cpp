#include "Warranty.h"

Warranty::Warranty(const std::string &t, int m, bool tr): terms(t), months(m), transferable(tr) {}
bool Warranty::validate(int monthsSince) const {
    if (monthsSince > months)
        throw WarrantyExpiredException();
    return true;
}
double Warranty::prorateRefund(int monthsSince) const {
    if (monthsSince >= months)
        return 0.0;
    return (months - monthsSince) / (double)months;
}
void Warranty::extend(int monthsAdd){
    months += monthsAdd;
}

