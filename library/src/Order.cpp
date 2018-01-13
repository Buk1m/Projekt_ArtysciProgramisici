//
// Created by 4DAM on 13.01.2018.
//

#include "../include/Order.h"
#include "../include/PaymentType.h"
#include "../include/ShipmentType.h"
#include "../include/Client.h"


Order::Order(const shared_ptr<Client> &client, const shared_ptr<ShipmentType> &shipmentType,
             const shared_ptr<PaymentType> &paymentType, const string &orderComment)
      : client(client),
        shipmentType(shipmentType),
        paymentType(paymentType),
        orderComment(orderComment)
{

}

Order::~Order() { }
