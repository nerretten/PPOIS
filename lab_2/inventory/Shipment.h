#ifndef SHIPMENT_H
#define SHIPMENT_H
#include <string>
#include <algorithm>
class Shipment {
private:
    std::string tracking;
    int itemsCount;
    double weightKg;
public:
    Shipment(const std::string &t, int items, double w);
    int getItemsount() const;
    void track();
    void receive();
    double averageItemWeight() const;
};
#endif

