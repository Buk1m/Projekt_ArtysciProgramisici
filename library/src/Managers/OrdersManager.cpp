//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Managers/OrdersManager.h"
#include "../../include/Cart.h"
#include "../../include/Order.h"
#include "../../include/Client.h"
#include "../../include/Merchandise.h"
#include "../../include/Repositories/MerchandisesRepository.h"
#include "../../include/Exceptions/OrderException.h"

#define ORDER_LIMIT_EXCEPTION OrderLimitException(__FILE__, __LINE__)

OrdersManager::OrdersManager(const shared_ptr<OrdersRepository> ordersRepository,
                             const shared_ptr<OrdersRepository> archieveOrdersRepository)
              :ordersRepository(ordersRepository),
              archieveOrdersRepository(archieveOrdersRepository)
{}

void OrdersManager::createOrder(const shared_ptr<Client> client, const shared_ptr<Cart> cart,
                                const shared_ptr<ShipmentType> shipmentType,
                                const shared_ptr<PaymentType> paymentType, const string orderComment)
{

    if(client->isHasOngoingOrder())
    {
        throw ORDER_LIMIT_EXCEPTION;
    }

    auto order = make_shared<Order>(client, cart, shipmentType, paymentType, orderComment);
    ordersRepository->create(order);

    client->setHasOngoingOrder(true);
    vector<shared_ptr<Merchandise>> productsToArchieve =  cart->getProducts();

    for(auto product : productsToArchieve)
    {
        product->setAvailability(false);
    }
}

void OrdersManager::cancelOrder(const shared_ptr<Client> &client)
{
    auto order = ordersRepository->getOrderForClient(client);
    vector<shared_ptr<Merchandise>> productsToReturn = order->getOrderedProducts();
    for(auto product : productsToReturn)
    {
        product->setAvailability(true);
    }
    ordersRepository->cancel(order);
    client->setHasOngoingOrder(false);
    client->clearCart();

    archieveOrdersRepository->create(order);
    ordersRepository->remove(order);
}

const string OrdersManager::endOrderAndPrintBill(const shared_ptr<Client> &client)
{
    auto order = ordersRepository->getOrderForClient(client);
    if(order->getOrderState() == "cancelled")
        throw make_shared<CartIsEmptyExcepton>(__FILE__, __LINE__);
    order->endOrder();
    client->setHasOngoingOrder(false);
    client->clearCart();
    order->setCompletionOrderTime();

    archieveOrdersRepository->create(order);
    ordersRepository->remove(order);
    return order->printBill();
}

unsigned long OrdersManager::getOrdersRepositorySize() const
{
    return ordersRepository->getRepositorySize();
}

shared_ptr<Client> OrdersManager::getClientForOrder(shared_ptr<Order> order) const
{
    return order->getClient();
}
