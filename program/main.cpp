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

using namespace std;

int main()
{

    auto clientRepo = make_shared<ClientRepository>();
    auto ordersRepo = make_shared<OrdersRepository>();
    auto merchandisesRepo = make_shared<MerchandisesRepository>();

    auto klient1Address = make_shared<Address>("kupna", "2");
    auto klient2Address = make_shared<Address>("gitignore", "3");
    auto klient3Address = make_shared<Address>("Wagonowa", "4");

    auto klient1deliveryAddress = make_shared<Address>("lol", "6");
    auto klient2deliveryAddress = make_shared<Address>("smile", "7");
    auto klient3deliveryAddress = make_shared<Address>("frisebee", "8");

    auto klient1 = make_shared<Client>("Adam", "Lindner", "upaupa123", "PostLindner", "lind@gmail.com",
                                       klient1Address, klient1deliveryAddress);
    auto klient2 = make_shared<Client>("Bartosz", "Kudra", "psikuta", "lol", "kud@gmail.com",
                                       klient1Address, klient2deliveryAddress);
    auto klient3 = make_shared<Client>("Julka", "Wagon", "kamien w kieszeni", "kotwica", "porazka@gmail.com",
                                       klient1Address, klient3deliveryAddress);

    clientRepo->create(klient1);
    clientRepo->create(klient2);
    clientRepo->create(klient3);

    auto laptop = make_shared<Laptop>("HP", 3000, 5, "Intel i7", "GTX 1060", "8", "250Gb SSD", "17,3");
    auto smartphone = make_shared<Smartphone>("LG", 2000, 10, "Snapdragon 810", "5,5 inches", "12 Mpix", "3 Gb");

    merchandisesRepo->create(laptop);
    merchandisesRepo->create(smartphone);

    klient1->addToCart(laptop,1);
    klient1->addToCart(smartphone,1);

    cout << endl << endl;
    cout << merchandisesRepo->getAll() << endl;
    cout << clientRepo->getAll() << endl;
    cout << klient1->getProductsCart()<<endl;

    auto cashPayment = make_shared<CashPayment>();
    auto cardPayment = make_shared<CardPayment>();
    auto courierDelivery = make_shared<CourierDelivery>();
    auto selfPickup = make_shared<SelfPickup>();

    auto klient1Order = make_shared<Order>(klient1, klient1->getClientCart(),
                                           selfPickup, cashPayment,
                                           "Produkt fabrycznie zaplombowany");

    return 0;
}