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
    bool hasOngoingOrder;

public:
    explicit Client(const string &firstName, const string &lastName, const string &login, const string &password,
                    const string &e_mail, const shared_ptr<Address> &clientAddress, const shared_ptr<Address> &deliveryAddress);
    ~Client() = default;

    const uuid getPersonalID() const;
    const string getFirstName() const;
    const string getLastName() const;
    const string getE_mail() const;
    const string getAddress() const;
    const string getDeliveryAddress() const;
    const string getProductsCart() const;

    const string getInfoAboutClient() const;
    const shared_ptr<Cart>& getClientCart() const;
    bool isHasOngoingOrder() const;

    bool checkPassword(const string &password) const;
    bool checkLogin(const string &login) const;

    void updateInfo(const string &firstName, const string &lastName, const string &e_mail);
    void updateLoginAndPassword(const string &login, const string &password);

    void addToCart(const shared_ptr<Merchandise> &product);
    void removeFromCart(const shared_ptr<Merchandise> &merchendise);

    void clearCart();
    void setHasOngoingOrder(bool hasOngoingOrder);
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENT_H
