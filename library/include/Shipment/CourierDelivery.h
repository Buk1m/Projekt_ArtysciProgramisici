//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_COURIERDELIVERY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_COURIERDELIVERY_H

#include "ShipmentType.h"

class CourierDelivery : public ShipmentType
{
public:
    explicit CourierDelivery();
    ~CourierDelivery() = default;

    float makeDiscount(int productsQuantity) override;
    const string getShipmentTypeName() override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_COURIERDELIVERY_H
