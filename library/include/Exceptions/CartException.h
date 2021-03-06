//
// Created by Bartek on 1/14/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CARTEXCEPTION_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CARTEXCEPTION_H

#include <iostream>
#include <stdexcept>
#include <sstream>

#define FULL_CART_EXCEPTION FullCartException(__FILE__, __LINE__)
#define NOT_IN_CART_EXCEPTION NotInCartException(__FILE__, __LINE__)
#define PRODUCT_ALREADY_IN_CART_EXCEPTION ProductAlreadyInCartException(__FILE__, __LINE__)

using namespace std;

class CartException : public logic_error
{
protected:
    string where;
    int line;
public:
    explicit CartException(const string &where, int line, const string message);
    virtual ~CartException() = default;

    virtual string description() const = 0;
};


class FullCartException : public CartException
{
public:
    explicit FullCartException(const string &where, int line);
    ~FullCartException() = default;

    string description() const override;
};


class NotInCartException : public CartException
{
public:
    explicit NotInCartException(const string &where, int line);
    ~NotInCartException() = default;

    string description() const override;
};

class ProductAlreadyInCartException : public CartException
{
public:
    explicit ProductAlreadyInCartException(const string &where, int line);
    ~ProductAlreadyInCartException() = default;

    string description() const override;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_CARTEXCEPTION_H
