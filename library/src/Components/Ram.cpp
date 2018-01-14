//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Components/Ram.h"
#include <sstream>

Ram::Ram(const string &name, float price, int quantity, const string &capacity,
         const string &latency, const string &memorySpeed)
   : Merchandise(name, price, quantity),
     capacity(capacity),
     latency(latency),
     memorySpeed(memorySpeed)
{}


string Ram::getSpecification() const
{
    stringstream specification;
    specification << "Ram" << endl
                  << name << endl
                  << "Capacity : " << capacity << "Gb" <<endl
                  << "MemorySpeed : " << memorySpeed << "MHz" << endl
                  << "Latency : " << latency  << endl
                  << "Price : " << price << " PLN" << endl
                  << "Quantity : " << quantity << endl;
    return specification.str();
}
