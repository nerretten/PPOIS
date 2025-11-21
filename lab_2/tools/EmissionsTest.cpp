#include "EmissionsTest.h"


EmissionsTest::EmissionsTest(double co, double hc, TestEquipment* e): coLevel(co), hcLevel(hc), equipment(e) {}
bool EmissionsTest::passStandard(){
    return coLevel < 0.5 && hcLevel < 50;
}
void EmissionsTest::perform(){
    coLevel *= 0.9; hcLevel *= 0.8; if (equipment) equipment->measure();
}
double EmissionsTest::computeScore() const {
    return coLevel * 0.6 + (hcLevel / 100.0) * 0.4;
}

