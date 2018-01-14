//
// Created by 4DAM on 13.01.2018.
//

#include "../include/Order.h"
#include "../include/Payment/PaymentType.h"
#include "../include/Shipment/ShipmentType.h"
#include "../include/Client.h"
#include "../include/Cart.h"
#include "../include/Merchandise.h"

//constructor==========================================================================
Order::Order(const shared_ptr<Client> &client, const shared_ptr<Cart> &cart,
             const shared_ptr<ShipmentType> &shipmentType,
             const shared_ptr<PaymentType> &paymentType, const string &orderComment)
        : orderId(boost::uuids::random_generator()()),
          client(client),
          shipmentType(shipmentType),
          paymentType(paymentType),
          orderComment(orderComment)
{
    _state = current;

    time_zone_ptr zone(new posix_time_zone("UTC-00:00:00"));
    ptime currentTime = second_clock::local_time();
    submitOrderTime = make_shared<local_date_time>(currentTime, zone);
    completionOrderTime = nullptr;

    moveProductsFromCartToOrder(cart->getProducts());
}

//methods==========================================================================
void Order::moveProductsFromCartToOrder(const vector<shared_ptr<Merchandise>> &products)
{
    for(auto product : products)
    {
        this->products.push_back(product);
    }
}


void Order::setOrderState(const string &state)
{
    if(state == "completed")
        _state = completed;
    else if(state == "cancelled")
        _state = cancelled;
}

void Order::setPaymentType(const shared_ptr<PaymentType> &paymentType)
{
    this->paymentType = paymentType;
}

void Order::setShipmentType(const shared_ptr<ShipmentType> &shipmentType)
{
    this->shipmentType = shipmentType;
}

//=============================
string Order::printBill() const
{
    return std::__cxx11::string();
}
//=============================

string Order::getOrderState() const
{
    if(_state == current)
        return "current";
    else if(_state == completed)
        return "completed";
    else if(_state == cancelled)
        return "cancelled";
}

void Order::endOrder()
{
    _state = completed;
}

string Order::getInfoAboutOrder() const
{
    stringstream info;
    info << "------------Order------------"
         << "\nId: " << orderId
         << "\nOrderDate: " << *submitOrderTime
         << "\nCost: " << getOrderCost()
         << "\nComment: " << orderComment
         << "\nShipmentType: " << shipmentType->getShipmentTypeName()
         << "\nPaymentType: " << paymentType->getPaymentTypeName()
         << "\nState: " << getOrderState()
         << endl;
    return info.str();
}

const float Order::getOrderCost() const
{
    float sum = 0;
    for(auto product : products)
    {
        sum += product->getPrice();
    }
    return sum;
}
