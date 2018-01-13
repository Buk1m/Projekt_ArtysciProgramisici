//
// Created by 4DAM on 13.01.2018.
//

#include <sstream>
#include "../include/Merchandise.h"
#include "boost/uuid/uuid_io.hpp"

Merchandise::Merchandise(const string &name, float price, int quantity)
           : merchandiseId(boost::uuids::random_generator()()),
             name(name),
             price(price),
             quantity(quantity)
{}

Merchandise::~Merchandise() {}


string Merchandise::getSpecification() const
{
    return std::__cxx11::string();
}

float Merchandise::getPrice() const
{
    return price;
}

int Merchandise::getQuantity() const
{
    return quantity;
}

void Merchandise::resupply(const int &quantity)
{
    this->quantity += quantity;
}

string Merchandise::getInfoAboutMerchandise() const
{
    stringstream info;
    info << "--- Merchandise --- "
         << "id:" << merchandiseId
         << "\nname:" << name
         << "\nprice:" << price
         << "\nquantity:" << quantity
         << endl;
    return info.str();
}
