//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include "../include/Client.h"
#include "../include/Merchandise.h"
#include "../include/Cart.h"

Client::Client(const string &firstName, const string &lastName, const string &login, const string &password,
               const string &e_mail, const shared_ptr<Address> &clientAddress, const shared_ptr<Address> &deliveryAddress)
        : firstName(firstName),
          lastName(lastName),
          password(password),
          login(login),
          e_mail(e_mail),
          deliveryAddress(deliveryAddress),
          clientAddress(clientAddress),
          hasOngoingOrder(false)
{
    cart = make_shared<Cart>(3);

    random_generator generateID;
    personalID = generateID();

    time_zone_ptr zone(new posix_time_zone("UTC+01:00:00"));
    ptime currentTime = second_clock::local_time();
    registerDate = make_shared<local_date_time>(currentTime, zone);
}

const uuid Client::getPersonalID() const
{
    return personalID;
}

const string Client::getFirstName() const
{
    return firstName;
}

const string Client::getLastName() const
{
    return lastName;
}

const string Client::getE_mail() const
{
    return e_mail;
}

const string Client::getProductsCart() const
{
    return cart->getProductInfo();
}

const string Client::getAddress() const
{
    return clientAddress->getAddressInfo();
}

const string Client::getDeliveryAddress() const
{
    return deliveryAddress->getAddressInfo();
}

bool Client::isHasOngoingOrder() const
{
    return hasOngoingOrder;
}

void Client::updateInfo(const string &firstName, const string &lastName, const string &e_mail)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->e_mail = e_mail;
}

void Client::updateLoginAndPassword(const string &login, const string &password)
{
    this->login = login;
    this->password = password;
}

void Client::addToCart(const shared_ptr<Merchandise> &product)
{
    cart->addProduct(product);
}

void Client::removeFromCart(const shared_ptr<Merchandise> &product)
{
    cart->removeProduct(product);
}

void Client::setHasOngoingOrder(bool hasOngoingOrder)
{
    Client::hasOngoingOrder = hasOngoingOrder;
}

const shared_ptr<Cart>& Client::getClientCart() const
{
    return cart;
}

void Client::clearCart()
{
    cart->clearCart();
}

bool Client::checkPassword(const string &password) const
{
    if(this->password == password)
        return true;
    else
        return false;
}

bool Client::checkLogin(const string &login) const
{
    if(this->login == login)
        return true;
    else
        return false;
}

const string Client::getInfoAboutClient() const
{
    stringstream info;
    info << "---------- Client ----------"
         << "\nId: " << personalID
         << "\nFirst name: " << firstName
         << "\nLast name: " << lastName
         << "\nRegister date: " << registerDate
         << "\nEmail: " << e_mail
         << "\nAddress: " << clientAddress->getAddressInfo()
         << endl;
    return info.str();
}
