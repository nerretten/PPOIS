#include "Alignment.h"

Alignment::Alignment(double toe, double camber, double cast): toeFront(toe), camberFront(camber), caster(cast) {}
void Alignment::adjustToe(double newToe){
    toeFront = newToe;
}

double Alignment::computeCorrection(){
    return (toeFront + camberFront + caster) / 3.0;
}
double Alignment::getToeFront() const {
    return toeFront;
}
