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
    ShipmentType();
    virtual ~ShipmentType();

    float getShipmentPrice() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_SHIPMENTTYPE_H
