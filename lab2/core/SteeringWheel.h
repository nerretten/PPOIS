#ifndef STEERINGWHEEL_H
#define STEERINGWHEEL_H

#include <string>

class SteeringWheel {
private:
    std::string type;
    int angleDegrees;

public:
    SteeringWheel(std::string type);
    void turnLeft();
    void turnRight();
    int getAngle() const;
    std::string getType() const;
};

#endif // STEERINGWHEEL_H