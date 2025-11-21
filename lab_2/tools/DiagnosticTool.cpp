#include "DiagnosticTool.h"


DiagnosticTool::DiagnosticTool(const std::string &m, bool conn)
        : model(m), connected(conn) {
    if (model.empty()) {
        throw std::invalid_argument("Diagnostic tool model cannot be empty");
    }
}

std::vector<std::string> DiagnosticTool::scanAll(Sensor* s) {
    if (!connected) {
        throw DiagnosticFailureException();
    }
    if (!s) {
        throw std::invalid_argument("Sensor pointer is null");
    }

    std::vector<std::string> codes;

    if (model == "DT-OLD") {
        throw CorrodedConnectorException();
    }

    try {
        double value = s->read();

        if (value < 0) {
            codes.push_back("P0001");
        } else if (value > 150.0) {
            codes.push_back("P1001");
        } else if (value > 100.0) {
            codes.push_back("P1002");
        }

        if (s->getType() == "O2") {
            if (value < 0.1) codes.push_back("P0171");
        }

    } catch (const std::runtime_error&) {
        codes.push_back("SENSOR_ERR");
    }

    errorCodes = codes;
    return codes;
}

void DiagnosticTool::clearCodes() {
    if (!connected) {
        throw DiagnosticFailureException();
    }
    errorCodes.clear();
}

void DiagnosticTool::connectToVehicle() {
    connected = true;
}

bool DiagnosticTool::hasActiveCodes() const {
    return !errorCodes.empty();
}

std::string DiagnosticTool::getStatusReport() const {
    std::ostringstream ss;
    ss << "Tool: " << model << " | Connected: " << (connected ? "Yes" : "No")
       << " | Active codes: " << errorCodes.size();
    return ss.str();
}

const std::string& DiagnosticTool::getModel() const {
    return model;
}