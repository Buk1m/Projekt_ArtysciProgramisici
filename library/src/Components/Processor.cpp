//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Components/Processor.h"
#include <sstream>

Processor::Processor(const string &name, float price, int quantity,
                     const string &generation, const string &clockSpeed)
          : Merchandise(name, price, quantity),
            generation(generation),
            clockSpeed(clockSpeed)
{}

string Processor::getSpecification() const
{
    stringstream specification;
    specification << "Processor" << endl
                  << name << endl
                  << "Generation : " << generation << endl
                  << "ClockSpeed : " << clockSpeed << " GHz" << endl
                  << "Price : " << price << " PLN" << endl
                  << "Quantity : " << quantity << endl;
    return specification.str();
}