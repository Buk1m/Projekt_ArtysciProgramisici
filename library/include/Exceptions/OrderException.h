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
protected:
    string where;
    int line;
public:
    OrderException(const string &message, const string &where, int line);

    virtual ~OrderException() = default;

    virtual string description() const = 0;
};


class CartIsEmptyExcepton : public OrderException
{
public:
    CartIsEmptyExcepton(const string &where, int line);
    ~CartIsEmptyExcepton() = default;
    string description() const;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDEREXCEPTION_H
