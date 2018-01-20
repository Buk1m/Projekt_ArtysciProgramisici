//
// Created by pobi on 1/15/18.
//

#include <memory>
#include <boost/test/unit_test.hpp>
#include "../library/include/Client.h"
#include "../library/include/Address.h"
#include "../library/include/Merchandise.h"
#include "../library/include/Cart.h"
#include "../library/include/Merchandises/Laptop.h"
#include "../library/include/Merchandises/Smartphone.h"
#include "../library/include/Exceptions/CartException.h"
#include "../library/include/Exceptions/MerchandiseException.h"
#include "../library/include/Exceptions/OrderException.h"
#include "../library/include/Exceptions/RepositoryException.h"
#include "../library/include/Managers/MerchandisesManager.h"
#include "../library/include/Repositories/OrdersRepository.h"
#include "../library/include/Managers/ClientsManager.h"
#include "../library/include/Managers/OrdersManager.h"
#include "../library/include/Payment/CashPayment.h"
#include "../library/include/Payment/CardPayment.h"
#include "../library/include/Shipment/CourierDelivery.h"
#include "../library/include/Shipment/SelfPickup.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProjectTest)

    BOOST_AUTO_TEST_CASE(ProductAvilable)
    {
        auto cashPayment = make_shared<CashPayment>();
        auto cardPayment = make_shared<CardPayment>();
        auto courierDelivery = make_shared<CourierDelivery>();
        auto selfPickup = make_shared<SelfPickup>();

        auto ordersRepository = make_shared<OrdersRepository>();
        auto archieveOrdersRepository = make_shared<OrdersRepository>();

        auto ordersManager = make_shared<OrdersManager>(ordersRepository, archieveOrdersRepository);

        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           client1Address, client1DeliveryAddress);
        auto m1 = make_shared<Laptop>("hp", 1999.0, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
        auto m2 = make_shared<Laptop>("lg", 1555.0, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");

        client1->addToCart(m1);
        client1->addToCart(m2);

        BOOST_CHECK_EQUAL(m1->isAvailable(), true);
        ordersManager->createOrder(client1, selfPickup, cardPayment, "Check on pickup");
        BOOST_CHECK_EQUAL(m1->isAvailable(), false);

        ordersManager->cancelOrder(client1);
        BOOST_CHECK_EQUAL(m1->isAvailable(), true);
        client1->addToCart(m1);
        client1->addToCart(m2);

        ordersManager->createOrder(client1, selfPickup, cardPayment, "Check on pickup");
        BOOST_CHECK_EQUAL(m1->isAvailable(), false);

        ordersManager->endOrderAndPrintBill(client1);
        BOOST_CHECK_EQUAL(m1->isAvailable(), false);

        //stwozenie zamownienia ktore tworzy te same produkty z innym id w ilosci 2
        vector<shared_ptr<Laptop>> m5 = m1->resupply(2);
        BOOST_CHECK_EQUAL(m5[0]->isAvailable(), true);
        BOOST_CHECK_EQUAL(m5[1]->isAvailable(), true);
    }


BOOST_AUTO_TEST_SUITE_END()