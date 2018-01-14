//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Exceptions/OrderException.h"

OrderException::OrderException(string message)
              : logic_error(message)
{}

string OrderException::description()
{
    return std::__cxx11::string();
}
