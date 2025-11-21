#include "StockItem.h"


StockItem::StockItem(const std::string &sku_, int qty, double temp): sku(sku_), quantity(qty), storageTemp(temp) {}
const std::string& StockItem::getSKU() const {
    return sku;
}
const int StockItem::getQuantity() const {
    return quantity;
}
void StockItem::consume(int q){
    quantity = std::max(0, quantity - q);
}
void StockItem::restock(int q){
    quantity += q;
}
bool StockItem::checkTemperature(){
    return storageTemp >= 0 && storageTemp <= 30;
}

