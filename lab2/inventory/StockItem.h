#ifndef STOCK_ITEM_H
#define STOCK_ITEM_H
#include <string>

class StockItem {
private:
    std::string sku;
    int quantity;
    double storageTemp;
public:
    StockItem(const std::string &sku_, int qty, double temp);
    const std::string& getSKU() const;
    const int getQuantity() const;
    void consume(int q);
    void restock(int q);
    bool checkTemperature();
};
#endif

