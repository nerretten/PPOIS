#ifndef DIAGNOSTIC_TOOL_H
#define DIAGNOSTIC_TOOL_H
#include <string>
#include <vector>
#include "../vehicle/Sensor.h"
#include "../exceptions/DiagnosticFailureException.h"
#include "exceptions/SensorFailureException.h"
#include "exceptions/CorrodedConnectorException.h"
#include <stdexcept>
#include <sstream>

class DiagnosticTool {
private:
    std::string model;
    bool connected;
    std::vector<std::string> errorCodes;
public:
    DiagnosticTool(const std::string &m, bool conn);
    std::vector<std::string> scanAll(Sensor* s);
    void clearCodes();
    void connectToVehicle();
    bool hasActiveCodes() const;
    std::string getStatusReport() const;
    const std::string& getModel() const;
};
#endif

