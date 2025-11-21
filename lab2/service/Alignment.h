#ifndef ALIGNMENT_H
#define ALIGNMENT_H
class Alignment {
private:
    double toeFront;
    double camberFront;
    double caster;
public:
    Alignment(double toe, double camber, double cast);
    double getToeFront() const;
    void adjustToe(double newToe);
    double computeCorrection();
};
#endif

