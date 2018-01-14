//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Managers/OrdersManager.h"

OrdersManager::OrdersManager()
{}

void OrdersManager::createOrder(const shared_ptr<Order> &order)
{
    ordersRepository->create(order);
}

void OrdersManager::removeOrder(const shared_ptr<Order> &order)
{
    ordersRepository->remove(order);
}
