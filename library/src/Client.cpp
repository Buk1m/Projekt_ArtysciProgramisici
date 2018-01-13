//
// Created by Bartek on 1/13/2018.
//

#include <memory>
#include <boost/uuid/uuid.hpp>
#include "../include/Client.h"

Client::Client(const string &firstName, const string &lastName, const string &password, const string &login,
               const string &e_mail) : firstName(firstName), lastName(lastName), password(password), login(login),
                                       e_mail(e_mail)
{
    cart = make_shared<Cart>();

    random_generator generateID;
    personalID = generateID();

    time_zone_ptr zone(new posix_time_zone("UTC+01:00:00"));
    ptime now = second_clock::local_time();
    registerDate = make_shared<local_date_time>(now, zone);

}

const uuid Client::getPersonalID() const
{
    return personalID;
}

const string &Client::getFirstName() const
{
    return firstName;
}

const string &Client::getLastName() const
{
    return lastName;
}

shared_ptr<Cart> Client::getProductsCart() const
{
    return nullptr;
}

const string Client::getAddress() const
{
    return clientAddress->getAddress();
}

const string Client::getDeliveryAddress() const
{
    return deliveryAddress->getAddress();
}

void Client::updateInfo(string firstName, string lastName, string e_mail)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->e_mail = e_mail;
}

void Client::updateLoginAndPassword(string login, string password)
{
    this->login = login;
    this->password = password;
}

void Client::addToCart(shared_ptr<Merchandise> product, int amount)
{
    cart->addProduct(Merchandise
    merchendise);
}

void Client::removeFromCart(shared_ptr<Merchandise> merchendise)
{
    cart->removeProduct(Merchandise
    merchandise);
}

const string Client::getClientOrders() const
{
    return ordersManager.getAllClientOrders(shared_ptr<Client>
    client);
}

void Client::reviceOrder() const
{
    return laptopOrder.endOrder();
}

bool Client::makePaymant()
{
    try
    {
        laptopOrder.state = paid;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

const string Client::getInfoAboutClient() const
{
    stringstream info;
    info << "--- Client --- "
         << "First name:" << firstName
         << "\nLast name:" << lastName
         << "\nemail:" << e_mail
         << "\naddress:" << clientAddress->getAddress()
         << endl;
    return info.str();
}