#ifndef DIAGNOSTICREPORT_H
#define DIAGNOSTICREPORT_H

#include "../Inventory/DiagnosticTool.h"
#include "../core/Car.h"
#include <string>
#include <vector>

class DiagnosticReport {
private:
    std::string reportId;
    Car* car;
    DiagnosticTool* tool;
    std::vector<std::string> findings;
    std::string conclusion;

public:
    DiagnosticReport(std::string id, Car* c, DiagnosticTool* t);
    void addFinding(std::string finding);
    void generateConclusion();
    void printReport() const;
    std::string getReportId() const;
};

#endif // DIAGNOSTICREPORT_H