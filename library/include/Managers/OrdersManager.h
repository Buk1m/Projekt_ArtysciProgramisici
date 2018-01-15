//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDERSMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDERSMANAGER_H

#include <memory>
#include "../Repositories/OrdersRepository.h"

using namespace std;

class Order;
class Client;

class OrdersManager
{
private:
    shared_ptr<OrdersRepository> ordersRepository;
public:
    OrdersManager(const shared_ptr<OrdersRepository> ordersRepository);
    ~OrdersManager() = default;

    //void createOrder(const shared_ptr<Order> &order);

    void createOrder(const shared_ptr<Client> client, const shared_ptr<Cart> cart,
                     const shared_ptr<ShipmentType> shipmentType,
                     const shared_ptr<PaymentType> paymentType,
                     const string orderComment);
    void cancelOrder(const shared_ptr<Client> &client);
    const string endOrderAndPrintBill(const shared_ptr<Client> &client);

};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDERSMANAGER_H
