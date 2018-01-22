//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_SELFPICKUP_H
#define PROJEKT_ARTYSCIPROGRAMISICI_SELFPICKUP_H

#include "ShipmentType.h"


class SelfPickup : public ShipmentType
{
public:
    explicit SelfPickup();
    ~SelfPickup() = default;

    float makeDiscount(const int &productsQuantity) const override;
    const string getShipmentTypeName() const override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_SELFPICKUP_H
