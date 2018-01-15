//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H


#include "Repository.h"
#include <vector>
#include <memory>
#include "../Order.h"

class OrdersRepository
        : public Repository<Order>
{
public:
    OrdersRepository() = default;
    ~OrdersRepository() = default;

    void create(const shared_ptr<Order> order);
    void remove(const shared_ptr<Order> order);
    void cancel(const shared_ptr<Order> order);

    const string getAll() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H
