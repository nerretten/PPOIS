#ifndef DIAGNOSTICTOOL_H
#define DIAGNOSTICTOOL_H

#include <string>

class DiagnosticTool {
private:
    std::string id;
    std::string brand;
    bool isConnected;

public:
    DiagnosticTool(std::string id, std::string brand);
    void connectToCar();
    void runDiagnostics();
    void disconnect();
    bool getIsConnected() const;
    std::string getBrand() const;
};

#endif // DIAGNOSTICTOOL_H