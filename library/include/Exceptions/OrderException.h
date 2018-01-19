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
    explicit OrderException(const string &message, const string &where, int line);
    virtual ~OrderException() = default;

    virtual string description() const = 0;
};


class CartIsEmptyExcepton : public OrderException
{
public:
    explicit CartIsEmptyExcepton(const string &where, int line);
    ~CartIsEmptyExcepton() override = default;

     string description() const override;
};


class OrderLimitException : public OrderException
{
public:
    explicit OrderLimitException(const string &where, int line);
    ~OrderLimitException() override = default;

   string description() const override;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDEREXCEPTION_H
