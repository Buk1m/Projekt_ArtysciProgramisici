//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_SHIPMENTTYPE_H
#define PROJEKT_ARTYSCIPROGRAMISICI_SHIPMENTTYPE_H

#include <iostream>
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"

using namespace std;
using namespace boost::uuids;


class ShipmentType
{
protected:
    const uuid shipmentId;
    float shipmentPrice;

public:
    explicit ShipmentType();
    virtual ~ShipmentType() = default;

    const float getShipmentPrice() const;
    virtual float makeDiscount(const int &productsQuantity) const = 0;
    virtual const string getShipmentTypeName() const = 0;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_SHIPMENTTYPE_H
