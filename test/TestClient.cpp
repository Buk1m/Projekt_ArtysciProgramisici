//
// Created by Bartek on 1/14/2018.
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
#include "../library/include/Exceptions/ClientException.h"
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
        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client2Address = make_shared<Address>("Wlokniarzy", "3");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");
        auto client2DeliveryAddress = make_shared<Address>("Politechniki", "7");

        BOOST_CHECK_EQUAL(client1Address->getAddressInfo(), "Piorkowska 123");
        BOOST_CHECK_EQUAL(client2Address->getAddressInfo(), "Wlokniarzy 3");
    }

    BOOST_AUTO_TEST_CASE(ClientGetters)
    {
        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           client1Address, client1DeliveryAddress);

        BOOST_CHECK_EQUAL(client1->getFirstName(), "Adam");
        BOOST_CHECK_EQUAL(client1->getLastName(), "Lindner");
    }

    BOOST_AUTO_TEST_CASE(ClientSetters)
    {
        //BOOST_CHECK_EQUAL(klient1->getAddress())
    }

    BOOST_AUTO_TEST_CASE(CartCapacity)
    {
        auto client1Address = make_shared<Address>("Piorkowska", "123");
        auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           client1Address, client1DeliveryAddress);

        auto m1 = make_shared<Laptop>("hp", 1999.0, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
        auto m2 = make_shared<Laptop>("lg", 1555.0, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
        auto m3 = make_shared<Laptop>("xiaomi", 3000.0, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
        auto m4 = make_shared<Smartphone>("xiaomi", 999.0, "ryzen 1600", "grdsg", "sdrg", "sef");


        client1->addToCart(m1);
        //client1->addToCart(m1);
        client1->addToCart(m2);

        //BOOST_CHECK_THROW( client1->addToCart(m2), FullCartException);
        BOOST_CHECK_THROW( client1->removeFromCart(m3), NotInCartException);


        //klient1->addToCart(m3);


    }

    BOOST_AUTO_TEST_CASE(hasOngoingOredesTest)
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

        BOOST_CHECK_EQUAL(client1->isHasOngoingOrder(), false);
        BOOST_CHECK_NO_THROW(ordersManager->createOrder(client1,client1->getClientCart(),selfPickup,cardPayment,"Check on pickup" ));

        BOOST_CHECK_EQUAL(client1->isHasOngoingOrder(), true);
        BOOST_CHECK_THROW(ordersManager->createOrder(client1,client1->getClientCart(),selfPickup,cardPayment,"Check on pickup" ), OrderLimitException);

        ordersManager->cancelOrder(client1);

        BOOST_CHECK_EQUAL(client1->isHasOngoingOrder(), false);
        cout<<client1->isHasOngoingOrder();
        BOOST_CHECK_NO_THROW(ordersManager->createOrder(client1,client1->getClientCart(),selfPickup,cardPayment,"Check on pickup"));
    }


BOOST_AUTO_TEST_SUITE_END()