//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../../include/Repositories/OrdersRepository.h"

void OrdersRepository::create(const shared_ptr<Order> &order)
{
    objects.push_back(order);
}

void OrdersRepository::remove(const shared_ptr<Order> &order)
{
    auto it = find(objects.begin(), objects.end(), order);
    objects.erase(it);
}

const string OrdersRepository::getAll() const
{
    stringstream info;
    info << "=== OrderRepository ===\n";
    for (auto order:objects)
    {
        info << order->getInfoAboutOrder();
    }
    info << "=============================" << endl;
    return info.str();
}
