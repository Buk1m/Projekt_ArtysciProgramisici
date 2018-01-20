//
// Created by pobi on 1/15/18.
//

//
// Created by pobi on 1/15/18.
//

//
// Created by Bartek on 1/14/2018.
//

#include <memory>
#include <boost/test/unit_test.hpp>
#include "../library/include/Client.h"
#include "../library/include/Address.h"
#include "../library/include/Merchandise.h"
#include "../library/include/Order.h"
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

    BOOST_AUTO_TEST_CASE(ClientManagerTest)
    {
        auto clientRepository = make_shared<ClientRepository>();
        auto clientManager = make_shared<ClientsManager>(clientRepository);

        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client2Address = make_shared<Address>("Wlokniarzy", "3");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");
        auto client2DeliveryAddress = make_shared<Address>("Politechniki", "7");


        auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           client1Address, client1DeliveryAddress);
        auto client2 = make_shared<Client>("Bartosz", "Kudra", "Buk1m", "1123", "kud@gmail.com",
                                           client1Address, client2DeliveryAddress);

        BOOST_CHECK_EQUAL(clientManager->getClientRepositorySize(), 0);

        clientManager->createClient(client1);
        clientManager->createClient(client2);
        BOOST_CHECK_EQUAL(clientManager->getClientRepositorySize(), 2);

        BOOST_CHECK_NO_THROW( clientManager->removeClient(client1) );
        BOOST_CHECK_EQUAL(clientManager->getClientRepositorySize(), 1);

        BOOST_CHECK_NO_THROW( clientManager->removeClient(client2) );
        BOOST_CHECK_EQUAL(clientManager->getClientRepositorySize(), 0);

        BOOST_CHECK_THROW(clientManager->removeClient(client2), ObjectNotFoundException);
    }

    BOOST_AUTO_TEST_CASE(OrderManagerTest)
    {
        auto archieveOrdersRepository = make_shared<OrdersRepository>();
        auto ordersRepository = make_shared<OrdersRepository>();

        auto ordersManager = make_shared<OrdersManager>(ordersRepository, archieveOrdersRepository);

        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client2Address = make_shared<Address>("Wlokniarzy", "3");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");
        auto client2DeliveryAddress = make_shared<Address>("Politechniki", "7");

        auto cashPayment = make_shared<CashPayment>();
        auto cardPayment = make_shared<CardPayment>();
        auto courierDelivery = make_shared<CourierDelivery>();
        auto selfPickup = make_shared<SelfPickup>();

        auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           client1Address, client1DeliveryAddress);
        auto client2 = make_shared<Client>("Bartosz", "Kudra", "Buk1m", "1123", "kud@gmail.com",
                                           client1Address, client2DeliveryAddress);

        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");
        auto m3 = make_shared<Laptop>("ACER", 3000.0, "Intel_i5", "GTX_970", "4", "500Gb_HDD", "15,6");
        auto m4 = make_shared<Smartphone>("XIAOMI", 999.0, "Kirin", "5,5_inches", "12.3_Mpix", "3_Gb");

        client1->addToCart(m1);
        client1->addToCart(m2);
        client2->addToCart(m3);
        client2->addToCart(m4);

        ordersManager->createOrder(client1, selfPickup, cardPayment, "Check on pickup");
        auto currentClient1Order = ordersManager->getCurrentOrderForClient(client1);
        BOOST_CHECK(ordersManager->getCurrentOrderForClient(client1) != nullptr);
        BOOST_CHECK_EQUAL(currentClient1Order->getOrderState(), "current");


        ordersManager->createOrder(client2, selfPickup, cardPayment, "Check on pickup");
        auto currentClient2Order = ordersManager->getCurrentOrderForClient(client2);
        BOOST_CHECK(ordersManager->getCurrentOrderForClient(client2) != nullptr);
        BOOST_CHECK_EQUAL(currentClient2Order->getOrderState(), "current");

        BOOST_CHECK_EQUAL(ordersManager->getOrdersRepositorySize(), 2);

        ordersManager->endOrderAndPrintBill(client1);
        BOOST_CHECK_EQUAL(currentClient1Order->getOrderState(), "completed");
        auto client1ArchOrders = ordersManager->getOrdersForClient(client1);
        BOOST_CHECK_EQUAL(client1ArchOrders[0], currentClient1Order);
        BOOST_CHECK_EQUAL(ordersManager->getOrdersRepositorySize(), 1);
        BOOST_CHECK_THROW(ordersManager->endOrderAndPrintBill(client1), ObjectNotFoundException);

        ordersManager->cancelOrder(client2);
        BOOST_CHECK_EQUAL(currentClient2Order->getOrderState(), "cancelled");
        auto client2ArchOrders = ordersManager->getOrdersForClient(client2);
        BOOST_CHECK_EQUAL(client2ArchOrders[0], currentClient2Order);
        BOOST_CHECK_EQUAL(ordersManager->getOrdersRepositorySize(), 0);
        BOOST_CHECK_THROW(ordersManager->endOrderAndPrintBill(client2), ObjectNotFoundException);

        client2->addToCart(m3);
        client2->addToCart(m4);

        ordersManager->createOrder(client2, selfPickup, cashPayment, "Check on pickup");
        auto currentClient2Order2 = ordersManager->getCurrentOrderForClient(client2);
        BOOST_CHECK(ordersManager->getCurrentOrderForClient(client2) != nullptr);
        BOOST_CHECK_EQUAL(currentClient2Order2->getOrderState(), "current");

        float orderPrice = m3->getPrice() + m4->getPrice();
        BOOST_CHECK_EQUAL(currentClient2Order2->getOrderCost(), orderPrice);
        currentClient2Order2->setPaymentType(cardPayment);
        currentClient2Order2->setShipmentType(courierDelivery);
        orderPrice += cardPayment->makeDiscount(2);
        orderPrice += courierDelivery->makeDiscount(2);
        BOOST_CHECK_EQUAL(currentClient2Order2->getOrderCost(), orderPrice);

        ordersManager->endOrderAndPrintBill(client2);
        client2ArchOrders = ordersManager->getOrdersForClient(client2);
        BOOST_CHECK_EQUAL(client2ArchOrders[1]->getOrderState(), "completed");
        BOOST_CHECK_EQUAL(client2ArchOrders[1]->getOrderCost(), orderPrice);
    }

    BOOST_AUTO_TEST_CASE(MerchandisesManagerTest)
    {
        auto archieveOrdersRepository = make_shared<OrdersRepository>();
        auto ordersRepository = make_shared<OrdersRepository>();

        auto ordersManager = make_shared<OrdersManager>(ordersRepository, archieveOrdersRepository);
        auto merchandisesRepository = make_shared<MerchandisesRepository>();
        auto merchandisesManager = make_shared<MerchandisesManager>(merchandisesRepository);
        auto clientRepository = make_shared<ClientRepository>();
        auto clientManager = make_shared<ClientsManager>(clientRepository);

        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client2Address = make_shared<Address>("Wlokniarzy", "3");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");
        auto client2DeliveryAddress = make_shared<Address>("Politechniki", "7");

        auto cashPayment = make_shared<CashPayment>();
        auto cardPayment = make_shared<CardPayment>();
        auto courierDelivery = make_shared<CourierDelivery>();
        auto selfPickup = make_shared<SelfPickup>();

        auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           client1Address, client1DeliveryAddress);
        auto client2 = make_shared<Client>("Bartosz", "Kudra", "Buk1m", "1123", "kud@gmail.com",
                                           client1Address, client2DeliveryAddress);

        clientRepository->create(client1);
        clientRepository->create(client2);

        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");
        auto m3 = make_shared<Laptop>("ACER", 3000.0, "Intel_i5", "GTX_970", "4", "500Gb_HDD", "15,6");
        auto m4 = make_shared<Smartphone>("XIAOMI", 999.0, "Kirin", "5,5_inches", "12.3_Mpix", "3_Gb");

        merchandisesManager->createMerchandise(m1);
        merchandisesManager->createMerchandise(m2);
        merchandisesManager->createMerchandise(m3);
        merchandisesManager->createMerchandise(m4);

        client1->addToCart(m1);
        client1->addToCart(m2);
        client2->addToCart(m3);
        client2->addToCart(m4);

        BOOST_CHECK_EQUAL(m1->getAvailability(), "Available");
        ordersManager->createOrder(client1, selfPickup, cashPayment, "Check on pickup");
        BOOST_CHECK_EQUAL(m1->getAvailability(), "NotAvailable");
        ordersManager->endOrderAndPrintBill(client1);
        BOOST_CHECK_EQUAL(m1->getAvailability(), "NotAvailable");

        BOOST_CHECK_EQUAL(merchandisesManager->getMerchandiseRepositorySize(), 4);
        merchandisesManager->removeMerchandise(m4);
        BOOST_CHECK_THROW(merchandisesManager->removeMerchandise(m4), ObjectNotFoundException);
        BOOST_CHECK_EQUAL(merchandisesManager->getMerchandiseRepositorySize(), 3);
        merchandisesManager->removeMerchandise(m3);
        merchandisesManager->removeMerchandise(m2);
        merchandisesManager->removeMerchandise(m1);
        BOOST_CHECK_EQUAL(merchandisesManager->getMerchandiseRepositorySize(), 0);
        BOOST_CHECK_THROW(merchandisesManager->removeMerchandise(m1), ObjectNotFoundException);

        merchandisesManager->resupplyMerchandise(m1, 1);
        merchandisesManager->resupplyMerchandise(m4, 2);
        BOOST_CHECK_EQUAL(merchandisesManager->getMerchandiseRepositorySize(), 3);
        auto products = merchandisesRepository->getMerchandises();
        BOOST_CHECK_EQUAL(m1->loadSpecification(), products[0]->loadSpecification());
        BOOST_CHECK_EQUAL(m4->loadSpecification(), products[1]->loadSpecification());
        BOOST_CHECK_EQUAL(m4->loadSpecification(), products[2]->loadSpecification());
    }

BOOST_AUTO_TEST_SUITE_END()