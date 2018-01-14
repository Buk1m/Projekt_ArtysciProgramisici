//
// Created by 4DAM on 13.01.2018.
//

#include <sstream>
#include "../include/Merchandise.h"
#include "boost/uuid/uuid_io.hpp"

Merchandise::Merchandise(const string &name, const float &price)
           : merchandiseId(boost::uuids::random_generator()()),
             name(name),
             price(price)
{}

float Merchandise::getPrice() const
{
    return price;
}



