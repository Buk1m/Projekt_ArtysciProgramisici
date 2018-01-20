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

    BOOST_AUTO_TEST_CASE(CreateAddress)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        BOOST_CHECK_EQUAL(clientAddress->getAddressInfo(), "Piorkowska 123");
        BOOST_CHECK_EQUAL(clientDeliveryAddress->getAddressInfo(), "Zgierska 6");
    }

    BOOST_AUTO_TEST_CASE(ClientGetters)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                          clientAddress, clientDeliveryAddress);

        BOOST_CHECK_EQUAL(client->getFirstName(), "Adam");
        BOOST_CHECK_EQUAL(client->getLastName(), "Lindner");
        BOOST_CHECK_EQUAL(client->getE_mail(), "lind@gmail.com");
        BOOST_CHECK_EQUAL(client->getAddress(), "Piorkowska 123");
        BOOST_CHECK_EQUAL(client->getDeliveryAddress(), "Zgierska 6");
        BOOST_CHECK( client->checkLogin("PostAdam") );
        BOOST_CHECK( client->checkPassword("passwd") );
    }

    BOOST_AUTO_TEST_CASE(hasOngoingOrdersTest)
    {
        auto cashPayment = make_shared<CashPayment>();
        auto cardPayment = make_shared<CardPayment>();
        auto courierDelivery = make_shared<CourierDelivery>();
        auto selfPickup = make_shared<SelfPickup>();

        auto ordersRepository = make_shared<OrdersRepository>();
        auto archieveOrdersRepository = make_shared<OrdersRepository>();

        auto ordersManager = make_shared<OrdersManager>(ordersRepository, archieveOrdersRepository);

        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           clientAddress, clientDeliveryAddress);
        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");

        client->addToCart(m1);
        client->addToCart(m2);

        BOOST_CHECK_EQUAL(client->isHasOngoingOrder(), false);
        BOOST_CHECK_NO_THROW(ordersManager->createOrder(client, selfPickup, cardPayment, "Check on pickup"));

        BOOST_CHECK_EQUAL(client->isHasOngoingOrder(), true);
        BOOST_CHECK_THROW(ordersManager->createOrder(client, selfPickup, cardPayment, "Check on pickup"), OrderLimitException);

        ordersManager->cancelOrder(client);
        BOOST_CHECK_EQUAL(client->isHasOngoingOrder(), false);
        BOOST_CHECK_THROW(ordersManager->createOrder(client, selfPickup, cardPayment, "Check on pickup"), CartIsEmptyException);
    }

    BOOST_AUTO_TEST_CASE(updateInfoTest)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                          clientAddress, clientDeliveryAddress);

        BOOST_CHECK_EQUAL(client->getFirstName(), "Adam");
        BOOST_CHECK_EQUAL(client->getLastName(), "Lindner");
        BOOST_CHECK_EQUAL(client->getE_mail(), "lind@gmail.com");
        BOOST_CHECK( client->checkLogin("PostAdam") );
        BOOST_CHECK( client->checkPassword("passwd") );

        client->updateInfo("Bartek", "Kudra", "kud@gmail.com");
        BOOST_CHECK_EQUAL(client->getFirstName(), "Bartek");
        BOOST_CHECK_EQUAL(client->getLastName(), "Kudra");
        BOOST_CHECK_EQUAL(client->getE_mail(), "kud@gmail.com");

        client->updateLoginAndPassword("Buk1m", "1123");
        BOOST_CHECK( client->checkLogin("Buk1m") );
        BOOST_CHECK( client->checkPassword("1123") );
    }
BOOST_AUTO_TEST_SUITE_END()