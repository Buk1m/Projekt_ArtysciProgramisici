//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Exceptions/MerchandiseException.h"

MerchandiseException::MerchandiseException(string message)
                    : logic_error(message)
{}

string MerchandiseException::description()
{
    return std::__cxx11::string();
}
