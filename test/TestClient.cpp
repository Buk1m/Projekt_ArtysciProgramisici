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

using namespace std;

BOOST_AUTO_TEST_SUITE(ProjectTest)

    BOOST_AUTO_TEST_CASE(CreateAddress)
    {

        auto klient1Address = make_shared<Address>("dupna", "2");
        auto klient2Address = make_shared<Address>("gitignore", "3");
        auto klient3Address = make_shared<Address>("Wagonowa", "4");

        BOOST_CHECK_EQUAL(klient1Address->getAddressInfo(), "dupna 2");
        BOOST_CHECK_EQUAL(klient2Address->getAddressInfo(), "gitignore 3");
        BOOST_CHECK_EQUAL(klient3Address->getAddressInfo(), "Wagonowa 4");

        //BOOST_CHECK_EQUAL();
    }


    BOOST_AUTO_TEST_CASE(ClientGetters)
    {
        auto klient1Address = make_shared<Address>("dupna", "2");
        auto klient2Address = make_shared<Address>("gitignore", "3");
        auto klient3Address = make_shared<Address>("Wagonowa", "4");

        auto klient1deliveryAddress = make_shared<Address>("lol", "6");
        auto klient2deliveryAddress = make_shared<Address>("smile", "7");
        auto klient3deliveryAddress = make_shared<Address>("penis", "8cm");

        auto klient1 = make_shared<Client>("Adam", "Lindner", "dupadupa123", "PostLindner", "lind@gmail.com",
                                           klient1deliveryAddress, klient1Address);
        auto klient2 = make_shared<Client>("Bartosz", "Kudra", "psikuta", "lol", "kud@gmail.com",
                                           klient2Address, klient2deliveryAddress);
        auto klient3 = make_shared<Client>("Julka", "Wagon", "kamien w kieszeni", "kotwica", "porazka@gmail.com",
                                           klient3Address, klient3deliveryAddress);

        BOOST_CHECK_EQUAL(klient1->getFirstName(), "Adam");
        BOOST_CHECK_EQUAL(klient1->getAddress(), "dupna 2");
        BOOST_CHECK_EQUAL(klient1->getLastName(), "Lindner");
        BOOST_CHECK_EQUAL(klient1->getDeliveryAddress(), "lol 6");

    }

    BOOST_AUTO_TEST_CASE(ClientSetters)
    {
        auto klient1Address = make_shared<Address>("dupna", "2");
        auto klient2Address = make_shared<Address>("gitignore", "3");
        auto klient3Address = make_shared<Address>("Wagonowa", "4");

        auto klient1deliveryAddress = make_shared<Address>("lol", "6");
        auto klient2deliveryAddress = make_shared<Address>("smile", "7");
        auto klient3deliveryAddress = make_shared<Address>("penis", "8cm");

        auto klient1 = make_shared<Client>("Adam", "Lindner", "dupadupa123", "PostLindner", "lind@gmail.com",
                                           klient1deliveryAddress, klient1Address);
        auto klient2 = make_shared<Client>("Bartosz", "Kudra", "psikuta", "lol", "kud@gmail.com",
                                           klient2Address, klient2deliveryAddress);
        auto klient3 = make_shared<Client>("Julka", "Wagon", "kamien w kieszeni", "kotwica", "porazka@gmail.com",
                                           klient3Address, klient3deliveryAddress);

        BOOST_CHECK_EQUAL(klient1->getFirstName(), "Adam");
        //BOOST_CHECK_EQUAL(klient1->getAddress())
    }


    BOOST_AUTO_TEST_CASE(CartCapacity)
    {
        auto klient1Address = make_shared<Address>("dupna", "2");

        auto klient1deliveryAddress = make_shared<Address>("lol", "6");

        auto klient1 = make_shared<Client>("Adam", "Lindner", "dupadupa123", "PostLindner", "lind@gmail.com",
                                           klient1deliveryAddress, klient1Address);
/*
       // auto m1 = make_shared<Laptop>("hp", 1999.0, 4, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
       // auto m2 = make_shared<Laptop>("lg", 1555.0, 3, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
       // auto m3 = make_shared<Laptop>("xiaomi", 3000.0, 2, "ryzen 1600", "grdsg", "sdrg", "sef", "asfaes");
        //auto m3 = make_shared<Smartphone>("xiaomi",999.0,4, "ryzen 1600", "grdsg", "sdrg", "sef");

        try
        {
            klient1->addToCart(m1, 2);
            klient1->addToCart(m1, 2);
            klient1->addToCart(m2, 1);
            klient1->addToCart(m2, 1);

        }
        catch (FullCartException &e)
        {
            cout << e.description();
        }

        try
        {
            klient1->removeFromCart(m3);
        }
        catch (NotInCartException &e)
        {
            cout << e.description();
        }

        BOOST_CHECK_THROW( klient1->addToCart(m2, 1), FullCartException);
        BOOST_CHECK_THROW( klient1->removeFromCart(m3), NotInCartException);
*/

        //klient1->addToCart(m3,4);


        BOOST_CHECK_EQUAL(klient1->getFirstName(), "Adam");
    }


BOOST_AUTO_TEST_SUITE_END()