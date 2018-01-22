//
// Created by 4DAM on 19.01.2018.
//

#include <memory>
#include <sstream>
#include <boost/test/unit_test.hpp>
#include "../library/include/Client.h"
#include "../library/include/Merchandise.h"
#include "../library/include/Merchandises/Laptop.h"
#include "../library/include/Merchandises/Smartphone.h"
#include "../library/include/Managers/MerchandisesManager.h"

using namespace std;


BOOST_AUTO_TEST_SUITE(TestFile)

    BOOST_AUTO_TEST_CASE(DataImmutability)
    {
        auto merchandisesRepository = make_shared<MerchandisesRepository>();
        auto merchandiseManager = make_shared<MerchandisesManager>(merchandisesRepository);

        auto laptop = make_shared<Laptop>("ASUS", 4500, "Intel_i5", "GTX_1050", "12", "500Gb_HDD", "15.6");
        auto smartphone = make_shared<Smartphone>("SAMSUNG", 3800, "Snapdragon_845", "6.1_inches", "16_Mpix", "6_Gb");

        merchandisesRepository->create(laptop);
        merchandisesRepository->create(smartphone);

        merchandiseManager->pushSmartphoneSpecsToFile();
        merchandiseManager->pushLaptopSpecsToFile();

        merchandiseManager->removeMerchandise(laptop);
        merchandiseManager->removeMerchandise(smartphone);

        merchandiseManager->pullSmartphoneSpecsFromFile();
        merchandiseManager->pullLaptopSpecsFromFile();


        stringstream laptopInfo, smartphoneInfo;
        laptopInfo  << endl
                    << "ASUS" << endl
                    << "Intel_i5" << endl
                    << "GTX_1050" << endl
                    << "12" << endl
                    << "500Gb_HDD" << endl
                    << "15.6" << endl
                    << 4500;
        smartphoneInfo  << endl
                        << "SAMSUNG" << endl
                        << "Snapdragon_845" << endl
                        << "6.1_inches" << endl
                        << "16_Mpix" << endl
                        << "6_Gb" << endl
                        << 3800;

        auto merchandises = merchandisesRepository->getMerchandises();
        BOOST_CHECK_EQUAL(merchandiseManager->getMerchandiseRepositorySize(), 2);

        BOOST_CHECK_EQUAL(merchandises[0]->loadSpecification(), smartphoneInfo.str());
        BOOST_CHECK_EQUAL(merchandises[1]->loadSpecification(), laptopInfo.str());
    }

BOOST_AUTO_TEST_SUITE_END()