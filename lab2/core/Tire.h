#ifndef TIRE_H
#define TIRE_H

#include <string>

class Tire {
private:
    std::string id;
    std::string type;
    double treadDepth;
    int rimSize;

public:
    Tire();
    Tire(std::string id, std::string type, double tread, int rim);
    void inspect();
    void rotate();
    double getTreadDepth() const;
    std::string getType() const;
};

#endif // TIRE_H