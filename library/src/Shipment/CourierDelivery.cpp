//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Shipment/CourierDelivery.h"

CourierDelivery::CourierDelivery()
                :ShipmentType()
{
    shipmentPrice = 20.0;
}


void CourierDelivery::makeDiscount(int productsQuantity)
{
    shipmentPrice -= (productsQuantity / 3) * 0.2;
}

const string CourierDelivery::getShipmentTypeName()
{
    return "CourierDelivery";
}
