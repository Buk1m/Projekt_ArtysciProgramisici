//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../include/OrdersRepository.h"

void OrdersRepository::create(const shared_ptr<Order> &order)
{
    orders.push_back(order);
}

void OrdersRepository::remove(const shared_ptr<Order> &order)
{
    auto it = find(orders.begin(), orders.end(), order);
    orders.erase(it);
}

const string OrdersRepository::getAll() const
{
    stringstream info;
    info << "=== OrderRepository ===\n";
    for (auto it:orders)
    {
        info << it->getInfoAboutOrder();
    }
    info << "=============================" << endl;
    return info.str();
}
