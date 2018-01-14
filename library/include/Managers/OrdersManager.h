//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDERSMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDERSMANAGER_H

#include <memory>
#include "../Repositories/OrdersRepository.h"

using namespace std;

class Order;

class OrdersManager
{
private:
    shared_ptr<OrdersRepository> ordersRepository;
public:
    OrdersManager();
    ~OrdersManager() = default;

    void createClient(const shared_ptr<Order> &order);
    void removeClient(const shared_ptr<Order> &order);
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDERSMANAGER_H
