#include "DiagnosticTool.h"
#include <iostream>

DiagnosticTool::DiagnosticTool(std::string id, std::string brand)
        : id(id), brand(brand), isConnected(false) {}

void DiagnosticTool::connectToCar() {
    isConnected = true;
    std::cout << "Diagnostic tool connected to car." << std::endl;
}

void DiagnosticTool::runDiagnostics() {
    if (!isConnected) {
        std::cout << "Tool not connected!" << std::endl;
        return;
    }
    std::cout << "Running diagnostics..." << std::endl;
}

void DiagnosticTool::disconnect() {
    isConnected = false;
    std::cout << "Diagnostic tool disconnected." << std::endl;
}

bool DiagnosticTool::getIsConnected() const {
    return isConnected;
}

std::string DiagnosticTool::getBrand() const {
    return brand;
}