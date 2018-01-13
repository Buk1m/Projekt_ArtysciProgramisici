//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDER_H

#include <iostream>
#include <memory>
#include <vector>
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
//#include "boost/uuid/uuid_io.hpp"
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"


using namespace std;
using namespace boost::uuids;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;

enum orderState
{
    current = 0,
    completed = 1,
    cancelled = 2
};

class Client;
class Cart;
class Merchandise;
class ShipmentType;
class PaymentType;


class Order
{
private:
    const uuid orderId;
    float orderCost;
    string orderComment;
    orderState _state;

    shared_ptr<local_date_time> submitOrderTime;
    shared_ptr<local_date_time> completionOrderTime;

    shared_ptr<Client> client;
    shared_ptr<ShipmentType> shipmentType;
    shared_ptr<PaymentType> paymentType;
    vector< shared_ptr<Merchandise> > products;

public:
    Order(const shared_ptr<Client> &client, const shared_ptr<Cart> &cart,
          const shared_ptr<ShipmentType> &shipmentType,
          const shared_ptr<PaymentType> &paymentType,
          const string &orderComment);
    ~Order();

private:
    void moveProductsFromCartToOrder(const vector<shared_ptr<Merchandise>> &products);

public:
    void setOrderState(const string &state);
    void setPaymentType(const shared_ptr<PaymentType> &paymentType);
    void setShipmentType(const shared_ptr<ShipmentType> &shipmentType);
    string printBill() const; //??? nwm czy dać tutaj ???
    string getOrderState() const;
    void endOrder();
    string getInfoAboutOrder() const;


};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDER_H
