//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Managers/OrdersManager.h"

OrdersManager::OrdersManager()
{}

void OrdersManager::createClient(const shared_ptr<Order> &order)
{
    ordersRepository->create(order);
}

void OrdersManager::removeClient(const shared_ptr<Order> &order)
{
    ordersRepository->remove(order);
}
