#ifndef EXHAUSTSYSTEM_H
#define EXHAUSTSYSTEM_H

#include <string>

class ExhaustSystem {
private:
    std::string id;
    std::string material;
    double noiseLevelDb;

public:
    ExhaustSystem(std::string id, std::string mat, double noise = 60.0);
    void inspect();
    void replace();
    double getNoiseLevel() const;
    std::string getMaterial() const;
};

#endif // EXHAUSTSYSTEM_H