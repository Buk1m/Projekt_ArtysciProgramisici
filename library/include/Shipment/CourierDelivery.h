//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_COURIERDELIVERY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_COURIERDELIVERY_H

#include "ShipmentType.h"

class CourierDelivery : public ShipmentType
{
public:
    CourierDelivery();
    ~CourierDelivery() = default;

    float makeDiscount(int productsQuantity);
    const string getShipmentTypeName();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_COURIERDELIVERY_H
