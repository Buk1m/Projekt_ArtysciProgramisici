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


class CartIsEmptyException : public OrderException
{
public:
    explicit CartIsEmptyException(const string &where, int line);
    ~CartIsEmptyException() override = default;

     string description() const override;
};


class OrderLimitException : public OrderException
{
public:
    explicit OrderLimitException(const string &where, int line);
    ~OrderLimitException() override = default;

   string description() const override;
};

/*class NoOrderAlreadyMade : public OrderException
{
public:
    explicit NoOrderAlreadyMade(const string &where, int line);
    ~NoOrderAlreadyMade() override = default;

    string description() const override;
};*/

#endif //PROJEKT_ARTYSCIPROGRAMISICI_ORDEREXCEPTION_H
