//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Shipment/CourierDelivery.h"
#include "../../include/Exceptions/MerchandiseException.h"

CourierDelivery::CourierDelivery()
                :ShipmentType()
{
    shipmentPrice = 20.0;
}


float CourierDelivery::makeDiscount(int productsQuantity)
{
    if (productsQuantity < 0)
    {
        throw INVALID_QUANTITY_EXCEPTION;
    }

    return (shipmentPrice - (productsQuantity * 3) / 5);
}

const string CourierDelivery::getShipmentTypeName()
{
    return "CourierDelivery";
}
