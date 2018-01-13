//
// Created by Bartek on 1/13/2018.
//

#include "../include/Address.h"

Address::Address(const string &street, const string &number) : street(street), number(number)
{}

const string Address::getAddress() const
{
    return street + " " + number;
}
