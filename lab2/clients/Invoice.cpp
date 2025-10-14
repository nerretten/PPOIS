#include "Invoice.h"

Invoice::Invoice(const Client& client, const ServiceOrder& order, const Date& date): client(client), order(order), date(date){}
double Invoice::generate_total(){
    return order.calculate_total_cost();
}