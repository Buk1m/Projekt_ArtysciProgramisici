//
// Created by pobi on 1/15/18.
//

//
// Created by Bartek on 1/14/2018.
//

#include <memory>
#include <boost/test/unit_test.hpp>
#include "../library/include/Client.h"
#include "../library/include/Merchandise.h"
#include "../library/include/Cart.h"
#include "../library/include/Merchandises/Laptop.h"
#include "../library/include/Merchandises/Smartphone.h"
#include "../library/include/Exceptions/CartException.h"
#include "../library/include/Managers/MerchandisesManager.h"
#include "../library/include/Repositories/OrdersRepository.h"
#include "../library/include/Managers/ClientsManager.h"
#include "../library/include/Managers/OrdersManager.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProjectTest)

    BOOST_AUTO_TEST_CASE(CartCapacity)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           clientAddress, clientDeliveryAddress);

        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");
        auto m3 = make_shared<Laptop>("ACER", 3000.0, "Intel_i5", "GTX_970", "4", "500Gb_HDD", "15,6");
        auto m4 = make_shared<Smartphone>("XIAOMI", 999.0, "Kirin", "5,5_inches", "12.3_Mpix", "3_Gb");

        client->addToCart(m1);
        client->addToCart(m2);
        client->addToCart(m3);

        BOOST_CHECK_THROW(client->addToCart(m4), FullCartException);
        BOOST_CHECK_THROW(client->removeFromCart(m4), NotInCartException);
    }


    BOOST_AUTO_TEST_CASE(PriceTest)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           clientAddress, clientDeliveryAddress);

        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");
        auto m3 = make_shared<Laptop>("ACER", 3000.0, "Intel_i5", "GTX_970", "4", "500Gb_HDD", "15,6");

        client->addToCart(m1);
        client->addToCart(m2);
        client->addToCart(m3);

        float price = 1999.0 + 1555.0 + 3000.0;
        BOOST_CHECK_EQUAL(client->getClientCart()->getAllProductsPrice(), price);

        client->removeFromCart(m2);
        price -= 1555.0;
        BOOST_CHECK_EQUAL(client->getClientCart()->getAllProductsPrice(), price);
    }

    BOOST_AUTO_TEST_CASE(QuantityAndClearingTest)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                           clientAddress, clientDeliveryAddress);

        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");
        auto m3 = make_shared<Laptop>("ACER", 3000.0, "Intel_i5", "GTX_970", "4", "500Gb_HDD", "15,6");

        client->addToCart(m1);
        client->addToCart(m2);
        client->addToCart(m3);
        BOOST_CHECK_EQUAL(client->getClientCart()->getProductsQuantity(), 3);

        client->clearCart();
        BOOST_CHECK_EQUAL(client->getClientCart()->getAllProductsPrice(), 0);
    }

    BOOST_AUTO_TEST_CASE(PassingProductsTest)
    {
        auto clientAddress = make_shared<Address>("Piorkowska", "123");
        auto clientDeliveryAddress = make_shared<Address>("Zgierska", "6");

        auto client = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                          clientAddress, clientDeliveryAddress);

        auto m1 = make_shared<Laptop>("HP", 1999.0, "Ryzen_1600", "Radeon_580", "8", "500Gb_SSD", "17,3");
        auto m2 = make_shared<Laptop>("LG", 1555.0, "Intel_i3", "GTX_1050", "16", "1000Gb_HDD", "17,3");
        auto m3 = make_shared<Laptop>("ACER", 3000.0, "Intel_i5", "GTX_970", "4", "500Gb_HDD", "15,6");

        vector<shared_ptr<Merchandise>> products;
        client->addToCart(m1);
        products.push_back(m1);

        client->addToCart(m2);
        products.push_back(m2);

        client->addToCart(m3);
        products.push_back(m3);

        vector<shared_ptr<Merchandise>> productsFromCart =  client->getClientCart()->getProducts();
        BOOST_CHECK_EQUAL(products[0]->getSpecification(), productsFromCart[0]->getSpecification());
        BOOST_CHECK_EQUAL(products[1]->getSpecification(), productsFromCart[1]->getSpecification());
        BOOST_CHECK_EQUAL(products[2]->getSpecification(), productsFromCart[2]->getSpecification());
    }


BOOST_AUTO_TEST_SUITE_END()