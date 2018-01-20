//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../../include/Repositories/OrdersRepository.h"
#include "../../include/Client.h"
#include "../../include/Order.h"
#include "../../include/Exceptions/RepositoryException.h"

void OrdersRepository::create(const shared_ptr<Order> order)
{
    objects.push_back(order);
}

void OrdersRepository::remove(const shared_ptr<Order> order)
{
    auto it = find(objects.begin(), objects.end(), order);
    if(it == objects.end())
    {
        throw OBJECT_NOT_FOUND_EXCEPTION;
    }
    objects.erase(it);
}

void OrdersRepository::cancel(const shared_ptr<Order> order)
{
    order->setOrderState("cancelled");
}

const string OrdersRepository::getAll() const
{
    stringstream info;
    info << "====== OrderRepository ======\n";
    for (auto order : objects)
    {
        info << order->getInfoAboutOrder();
    }
    info << "=============================" << endl;
    return info.str();
}

const shared_ptr<Order> OrdersRepository::getOrderForClient(const shared_ptr<Client> &client) const
{
    for(auto i=0; i<objects.size(); i++)
    {
        if (objects[i]->getClient() == client)
            return objects[i];
    }
    return nullptr;
}

unsigned long OrdersRepository::getRepositorySize() const
{
    return objects.size();
}

const vector<shared_ptr<Order>> OrdersRepository::getOrdersForClient(const shared_ptr<Client> &client) const
{
    vector<shared_ptr<Order>> orders;
    for(auto order : objects)
    {
        if(order->getClient() == client)
        {
            orders.push_back(order);
        }
    }
    return orders;
}
