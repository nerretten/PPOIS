#ifndef WARRANTY_H
#define WARRANTY_H
#include <string>
#include "../exceptions/WarrantyExpiredException.h"
#include <stdexcept>
class Warranty {
private:
    std::string terms;
    int months;
    bool transferable;
public:
    Warranty(const std::string &t, int m, bool tr);
    bool validate(int monthsSince) const;
    double prorateRefund(int monthsSince) const;
    void extend(int monthsAdd);
};
#endif

