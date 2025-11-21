#include "Toolbox.h"


Toolbox::Toolbox(int owner, const std::string &loc): ownerId(owner), location(loc) {}
void Toolbox::addTool(Tool* t){
    tools.push_back(t);
}
Tool* Toolbox::findTool(const std::string &name) {
    for (auto t : tools) {
        if (t && t->getName() == name) {
            return t;
        }
    }
    return nullptr;
}
void Toolbox::inventory() {
    std::cout << "[Toolbox Inventory] Owner ID: " << ownerId
              << ", Location: " << location
              << ", Tools (" << tools.size() << "):\n";
    for (size_t i = 0; i < tools.size(); ++i) {
        Tool* t = tools[i];
        if (t) {
            std::cout << "  [" << i << "] " << t->getName()
                      << (t->needsCalibration() ? " [NEEDS CALIBRATION]" : " [OK]")
                      << " (used " << t->getTimesUsed() << " times)\n";
        } else {
            std::cout << "  [" << i << "] [NULL TOOL]\n";
        }
    }
}

