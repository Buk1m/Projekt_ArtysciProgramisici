//
// Created by 4DAM on 13.01.2018.
//

#include "../include/ShipmentType.h"

ShipmentType::ShipmentType()
            : shipmentId(boost::uuids::random_generator()())
{}

ShipmentType::~ShipmentType() {}

float ShipmentType::getShipmentPrice() const
{
    return shipmentPrice;
}
