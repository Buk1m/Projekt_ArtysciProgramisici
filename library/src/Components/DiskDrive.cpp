//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Components/DiskDrive.h"
#include <sstream>

DiskDrive::DiskDrive(const string &name, float price, int quantity,
                     const string &diskType, const string &capacity)
          : Merchandise(name, price, quantity),
            diskType(diskType),
            capacity(capacity)
{}

string DiskDrive::getSpecification() const
{
    stringstream specification;
    specification << "Disk Drive" << endl
                  << "DiskType : " << diskType << " " << name << endl
                  << "Capacity : " << capacity << "Gb" << endl
                  << "Price : " << price << "PLN" << endl
                  << "Quantity : " << quantity << endl;
    return specification.str();
}
