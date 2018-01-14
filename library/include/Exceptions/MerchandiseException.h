//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEEXCEPTION_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEEXCEPTION_H

#include <iostream>
#include <stdexcept>

using namespace std;

class MerchandiseException : public logic_error
{
public:
    MerchandiseException(string message);
    ~MerchandiseException() = default;
    string description();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEEXCEPTION_H
