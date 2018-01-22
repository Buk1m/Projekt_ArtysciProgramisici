//

// Created by 4DAM on 13.01.2018.
//

#include "../include/Order.h"
#include "../include/Payment/PaymentType.h"
#include "../include/Shipment/ShipmentType.h"
#include "../include/Client.h"
#include "../include/Cart.h"
#include "../include/Merchandise.h"
#include "../include/Exceptions/OrderException.h"

#define CART_IS_EMPTY_EXCEPTION CartIsEmptyException(__FILE__, __LINE__)

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

void Order::moveProductsFromCartToOrder(const vector<shared_ptr<Merchandise>> &products)
{
    if(products.empty())
    {
        throw CART_IS_EMPTY_EXCEPTION;
    }

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

string Order::printBill() const
{
    stringstream bill;
    bill << "==================BILL==================" << endl
         << getInfoAboutOrder() << endl
         << "PersonalData:===========================" << endl
         << client->getInfoAboutClient() << endl
         << "Products:===============================" << endl;
    for(auto product : products)
    {
        bill << product->getSpecification() << endl;
    }
    bill << "TotalCost:\t\t\t" << getOrderCost() << " PLN" << endl
         << "=======================================" << endl;
    return bill.str();
}

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
         << "\nCompletionDate: ";
    if(completionOrderTime == nullptr)
        info << "---";
    else
        info << *completionOrderTime;
    info << "\nCost: " << getOrderCost() << " PLN"
         << "\nComment: " << orderComment
         << "\nShipmentType: " << shipmentType->getShipmentTypeName()
         << "\nPaymentType: " << paymentType->getPaymentTypeName()
         << "\nState: " << getOrderState()
         << endl;
    return info.str();
}

const float Order::getOrderCost() const
{
    float sum = 0.0;
    for(auto product : products)
    {
        sum += product->getPrice();
    }
    sum += shipmentType->makeDiscount(products.size());
    sum += paymentType->makeDiscount(products.size());
    return sum;
}

const vector<shared_ptr<Merchandise>> Order::getOrderedProducts() const
{
    return products;
}

const shared_ptr<Client>& Order::getClient() const
{
    return client;
}

void Order::setCompletionOrderTime()
{
    time_zone_ptr zone(new posix_time_zone("UTC-00:00:00"));
    ptime currentTime = second_clock::local_time();
    completionOrderTime = make_shared<local_date_time>(currentTime, zone);
}
