//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Components/GraphicCard.h"
#include <sstream>

GraphicCard::GraphicCard(const string &name, float price, int quantity, const string &vRam,
                         const string &coreClockSpeed, const string &memorySpeed)
             : Merchandise(name, price, quantity),
               vRam(vRam),
               coreClockSpeed(coreClockSpeed),
               memorySpeed(memorySpeed)
{}

string GraphicCard::getSpecification() const
{
    stringstream specification;
    specification << "GraphicCard" << endl
                  << name << endl
                  << "VRam : " << vRam << " Gb" << endl
                  << "CoreClockSpeed : " << coreClockSpeed << " MHz" << endl
                  << "MemorySpeed : " << memorySpeed << " MHz" << endl
                  << "Price : " << price << " PLN" << endl
                  << "Quantity : " << quantity << endl;
    return specification.str();
}