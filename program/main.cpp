#include <iostream>
#include <memory>
#include "../library/include/Address.h"
#include "../library/include/Repositories/ClientsRepository.h"
#include "../library/include/Repositories/OrdersRepository.h"
#include "../library/include/Repositories/MerchandisesRepository.h"
#include "../library/include/Merchandise.h"
#include "../library/include/Merchandises/Laptop.h"
#include "../library/include/Merchandises/Smartphone.h"
#include "../library/include/Cart.h"
#include "../library/include/Client.h"
#include "../library/include/Shipment/SelfPickup.h"
#include "../library/include/Shipment/CourierDelivery.h"
#include "../library/include/Payment/CardPayment.h"
#include "../library/include/Payment/CashPayment.h"
#include "../library/include/Managers/OrdersManager.h"
#include "../library/include/Managers/MerchandisesManager.h"
#include "../library/include/Managers/ClientsManager.h"

using namespace std;

int main()
{
//==========================================================================================
    auto clientRepository = make_shared<ClientRepository>();
    auto merchandisesRepository = make_shared<MerchandisesRepository>();
    auto ordersRepository = make_shared<OrdersRepository>();
    auto archieveOrdersRepository = make_shared<OrdersRepository>();

    auto clientManager = make_shared<ClientsManager>(clientRepository);
    auto merchandiseManager = make_shared<MerchandisesManager>(merchandisesRepository);
    auto ordersManager = make_shared<OrdersManager>(ordersRepository, archieveOrdersRepository);

    auto client1Address = make_shared<Address>("Piorkowska", "123");
    auto client2Address = make_shared<Address>("Wlokniarzy", "3");
    auto client1DeliveryAddress = make_shared<Address>("Zgierska", "6");
    auto client2DeliveryAddress = make_shared<Address>("Politechniki", "7");
//==========================================================================================


    auto client1 = make_shared<Client>("Adam", "Lindner", "PostAdam", "passwd", "lind@gmail.com",
                                       client1Address, client1DeliveryAddress);
    auto client2 = make_shared<Client>("Bartosz", "Kudra", "Buk1m", "1123", "kud@gmail.com",
                                       client1Address, client2DeliveryAddress);

    clientRepository->create(client1);
    clientRepository->create(client2);
    

    auto laptop = make_shared<Laptop>("ASUS", 4500, "Intel_i5", "GTX_1050", "12", "500Gb_HDD", "15.6");
    auto smartphone = make_shared<Smartphone>("SAMSUNG", 3800, "Snapdragon 845", "6.1_inches", "16_Mpix", "6_Gb");

    merchandisesRepository->create(laptop);
    merchandisesRepository->create(smartphone);


    merchandiseManager->pushSmartphoneSpecsToFile();
    merchandiseManager->pushLaptopSpecsToFile();

    merchandiseManager->removeMerchandise(laptop);
    merchandiseManager->removeMerchandise(smartphone);

    merchandiseManager->pullSmartphoneSpecsFromFile();
    merchandiseManager->pullLaptopSpecsFromFile();


    merchandiseManager->pullLaptopSpecsFromFile();
    merchandiseManager->pullSmartphoneSpecsFromFile();

    cout << merchandisesRepository->getAll() << endl;

    cout << endl << endl << endl;


    //cout << merchandisesRepository->getAll() << endl;
    //client1->addToCart(laptop);
    //client1->addToCart(smartphone);


    /*cout << endl << endl;
    cout << merchandisesRepository->getAll() << endl;
    cout << clientRepository->getAll() << endl;*/

//==========================================================================================
    auto cashPayment = make_shared<CashPayment>();
    auto cardPayment = make_shared<CardPayment>();
    auto courierDelivery = make_shared<CourierDelivery>();
    auto selfPickup = make_shared<SelfPickup>();

    //merchandiseManager->resupplyMerchandise(laptop, 3);

    /*ordersManager->createOrder(client1, client1->getClientCart(),
                               courierDelivery, cardPayment,

                               "Produkt fabrycznie zaplombowany");


                               "Produkt fabrycznie zaplombowany");*/
//==========================================================================================
   /* cout << laptop->getSpecification() << endl;
    //ordersManager->cancelOrder(client1);
    cout << ordersManager->endOrderAndPrintBill(client1) << endl;

    cout << ordersRepository->getAll() << endl;

   /* vector< shared_ptr<Laptop> > laptops = laptop->resupply(2);
    for(auto lap : laptops)
    {
        cout << lap->getSpecification() << endl;
    }*/

    //cout << laptop->getSpecification() << endl;*/
    /* ordersManager->cancelOrder(client1);
     cout << ordersManager->endOrderAndPrintBill(client1) << endl;
     cout << ordersRepository->getAll()  << endl;

     cout << ordersRepository->getAll() << endl;*/

    return 0;
}