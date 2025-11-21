#include "TestEquipment.h"

TestEquipment::TestEquipment(const std::string &s, bool cal, int days): serial(s), calibrated(cal), lastCalibrationDays(days) {}
void TestEquipment::calibrate(){
    calibrated = true;
    lastCalibrationDays = 0;
}
bool TestEquipment::needsCalibration() const {
    return !calibrated || lastCalibrationDays > 365;
}
double TestEquipment::measure(){
    return 42.0;
}

