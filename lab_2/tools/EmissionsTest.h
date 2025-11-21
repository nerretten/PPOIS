#ifndef EMISSIONS_TEST_H
#define EMISSIONS_TEST_H
#include "TestEquipment.h"
class TestEquipment;
class EmissionsTest {
private:
    double coLevel;
    double hcLevel;
    TestEquipment* equipment;
public:
    EmissionsTest(double co, double hc, TestEquipment* e);
    bool passStandard();
    void perform();
    double computeScore() const;
};
#endif

