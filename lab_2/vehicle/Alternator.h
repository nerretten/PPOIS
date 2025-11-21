#ifndef ALTERNATOR_H
#define ALTERNATOR_H
class Alternator {
private:
    double outputA;
    double beltTension;
    bool regulatorOk;
public:
    Alternator(double out, double tension, bool reg);
    double generate(double rpm);
    void adjustBelt(double tension);
    bool testOutput();
};
#endif

