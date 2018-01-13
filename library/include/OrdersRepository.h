//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H


#include "Repository.h"
#include <vector>
#include <memory>
class Order;

class OrdersRepository
        : public Repository<Order>
{
private:
    vector<shared_ptr<Order>> orders;
public:
    OrdersRepository() = default;

    ~OrdersRepository() = default;

    void create(shared_ptr<Order> order);

    void remove(shared_ptr<Order> order);

    string getAll() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H
