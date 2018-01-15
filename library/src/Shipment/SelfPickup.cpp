//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Shipment/SelfPickup.h"

SelfPickup::SelfPickup()
           :ShipmentType()
{
    shipmentPrice = 0.0;
}

float SelfPickup::makeDiscount(int productsQuantity)
{
    return 0.0;
}

const string SelfPickup::getShipmentTypeName()
{
    return "SelfPickup";
}
