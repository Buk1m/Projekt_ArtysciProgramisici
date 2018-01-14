//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_SELFPICKUP_H
#define PROJEKT_ARTYSCIPROGRAMISICI_SELFPICKUP_H

#include "ShipmentType.h"

class SelfPickup : public ShipmentType
{
public:
    SelfPickup();
    ~SelfPickup() = default;

    void makeDiscount(int productsQuantity) {};
    const string getShipmentTypeName();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_SELFPICKUP_H
