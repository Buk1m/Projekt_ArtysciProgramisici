//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H


#include "Repository.h"
#include <vector>
#include <memory>
#include "../Order.h"

class Order;

class OrdersRepository
        : public Repository<Order>
{
public:
    explicit OrdersRepository() = default;
    ~OrdersRepository() = default;

    void create(const shared_ptr<Order> order) override;
    void remove(const shared_ptr<Order> order) override;
    void cancel(const shared_ptr<Order> order);
    unsigned long getRepositorySize() const override;
    const shared_ptr<Order> getOrderForClient(const shared_ptr<Client>& client) const;

    const string getAll() const override;
};



#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDERSREPOSITORY_H
