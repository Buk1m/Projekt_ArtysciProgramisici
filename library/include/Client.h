//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CLIENT_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CLIENT_H

#include <memory>
#include <string>
#include "Address.h"
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;

class Merchandise;
class Cart;
class Client
{
private:
    uuid personalID;
    string firstName;
    string lastName;
    string password;
    string login;
    string e_mail;
    shared_ptr<local_date_time> registerDate;
    shared_ptr<Address> deliveryAddress;
    shared_ptr<Address> clientAddress;
    shared_ptr<Cart> cart;
public:

    Client(const string &firstName, const string &lastName, const string &password, const string &login,
           const string &e_mail, const shared_ptr<Address> &deliveryAddress, const shared_ptr<Address> &clientAddress);

    ~Client() = default;

    const uuid getPersonalID() const;

    const string &getFirstName() const;

    const string &getLastName() const;

    const string getProductsCart() const;

    const string getAddress() const;

    const string getDeliveryAddress() const;

    void updateInfo(const string &firstName, const string &lastName, const string &e_mail);

    void updateLoginAndPassword(const string &login, const string &password);

    void addToCart(const shared_ptr<Merchandise> &product, const int &amount);

    void removeFromCart(const shared_ptr<Merchandise> &merchendise);

    const string getClientOrders() const;

    void reviceOrder() const;

    bool makePaymant();

    const string getInfoAboutClient() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENT_H
