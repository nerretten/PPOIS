#ifndef TEST_EQUIPMENT_H
#define TEST_EQUIPMENT_H
#include <string>
class TestEquipment {
private:
    std::string serial;
    bool calibrated;
    int lastCalibrationDays;
public:
    TestEquipment(const std::string &s, bool cal, int days);
    void calibrate();
    bool needsCalibration() const;
    double measure();
    const std::string& getSerial() const { return serial; }
    bool isCalibrated() const { return calibrated; }
    int getLastCalibrationDays() const { return lastCalibrationDays; }
};
#endif

