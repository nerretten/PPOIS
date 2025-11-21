#include "Alternator.h"

Alternator::Alternator(double out, double tension, bool reg): outputA(out), beltTension(tension), regulatorOk(reg) {}
double Alternator::generate(double rpm) {
    if (!regulatorOk) return 0.0;
    return outputA * (rpm / 1000.0) * (beltTension);
}
void Alternator::adjustBelt(double tension){ beltTension = tension; }
bool Alternator::testOutput(){ return outputA > 0.5 && regulatorOk; }

