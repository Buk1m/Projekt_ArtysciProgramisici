//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Shipment/ShipmentType.h"

ShipmentType::ShipmentType()
             : shipmentId(boost::uuids::random_generator()())
{}

const float ShipmentType::getShipmentPrice() const
{
    return shipmentPrice;
}
