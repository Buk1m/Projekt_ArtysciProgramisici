//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Managers/OrdersManager.h"
#include "../../include/Cart.h"
#include "../../include/Order.h"
#include "../../include/Merchandise.h"
#include "../../include/Repositories/MerchandisesRepository.h"

void OrdersManager::createOrder(const shared_ptr<Client> client, const shared_ptr<Cart> cart,
                                const shared_ptr<ShipmentType> shipmentType,
                                const shared_ptr<PaymentType> paymentType, const string orderComment)
{

    auto order = make_shared<Order>(client, cart, shipmentType, paymentType, orderComment);
    ordersRepository->create(order);

    /*vector<shared_ptr<Merchandise>> productsToArchieve =  cart->getProducts();

    for(auto product : productsToArchieve)
    {
        product->setAvailability(false);
    }*/

}

void OrdersManager::cancelOrder(const shared_ptr<Order> &order)
{
    vector<shared_ptr<Merchandise>> productsToReturn = order->getOrderedProducts();
    for(auto product : productsToReturn)
    {
        product->setAvailability(true);
    }
    ordersRepository->cancel(order);
}


