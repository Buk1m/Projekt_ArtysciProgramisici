//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Exceptions/ClientException.h"

ClientException::ClientException(string message)
               : logic_error(message)
{}

string ClientException::description()
{
    return std::__cxx11::string();
}
