//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Shipment/CourierDelivery.h"

CourierDelivery::CourierDelivery()
                :ShipmentType()
{
    shipmentPrice = 20.0;
}


float CourierDelivery::makeDiscount(int productsQuantity)
{
    return (shipmentPrice - (productsQuantity * 3) / 5);
}

const string CourierDelivery::getShipmentTypeName()
{
    return "CourierDelivery";
}
