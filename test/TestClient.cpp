//
// Created by Bartek on 1/14/2018.
//

#include <memory>
#include <boost/test/unit_test.hpp>
#include "../library/include/Client.h"
#include "../library/include/Address.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProjectTest)

    BOOST_AUTO_TEST_CASE(CreateAddress) {

        auto klient1Address = make_shared<Address>("dupna", "2");
        auto klient2Address = make_shared<Address>("gitignore", "3");
        auto klient3Address = make_shared<Address>("Wagonowa", "4");

        BOOST_CHECK_EQUAL(klient1Address->getAddressInfo(), "dupna 2");
        BOOST_CHECK_EQUAL(klient2Address->getAddressInfo(), "gitignore 3");
        BOOST_CHECK_EQUAL(klient3Address->getAddressInfo(), "Wagonowa 4");





        //BOOST_CHECK_EQUAL();
    }

    BOOST_AUTO_TEST_CASE(CreateDeliveryAddress) {

            auto klient1deliveryAddress = make_shared<Address>("lol", "6");
            auto klient2deliveryAddress = make_shared<Address>("smile", "7");
            auto klient3deliveryAddress = make_shared<Address>("penis", "8cm");

            BOOST_CHECK_EQUAL(klient1deliveryAddress->getAddressInfo(), "lol 6");
            BOOST_CHECK_EQUAL(klient2deliveryAddress->getAddressInfo(), "smile 7");
            BOOST_CHECK_EQUAL(klient3deliveryAddress->getAddressInfo(), "penis 8cm");;
    }

BOOST_AUTO_TEST_CASE(CreateClient){
            auto klient1Address = make_shared<Address>("dupna", "2");
            auto klient2Address = make_shared<Address>("gitignore", "3");
            auto klient3Address = make_shared<Address>("Wagonowa", "4");

            auto klient1deliveryAddress = make_shared<Address>("lol", "6");
            auto klient2deliveryAddress = make_shared<Address>("smile", "7");
            auto klient3deliveryAddress = make_shared<Address>("penis", "8cm");

            auto klient1 = make_shared<Client>("Adam", "Lindner", "dupadupa123", "PostLindner", "lind@gmail.com",
                                               klient1Address, klient1deliveryAddress);
            auto klient2 = make_shared<Client>("Bartosz", "Kudra", "psikuta", "lol", "kud@gmail.com",
                                               klient1Address, klient2deliveryAddress);
            auto klient3 = make_shared<Client>("Julka", "Wagon", "kamien w kieszeni", "kotwica", "porazka@gmail.com",
                                               klient1Address, klient3deliveryAddress);

    }

BOOST_AUTO_TEST_SUITE_END()