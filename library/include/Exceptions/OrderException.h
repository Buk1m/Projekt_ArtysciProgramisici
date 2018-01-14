//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ORDEREXCEPTION_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ORDEREXCEPTION_H

#include <iostream>
#include <stdexcept>

using namespace std;

class OrderException : public logic_error
{
public:
    OrderException(string message);
    ~OrderException() = default;
    string description();
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDEREXCEPTION_H
