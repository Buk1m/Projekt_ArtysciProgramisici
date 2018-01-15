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
#define PRODUCT_NOT_AVAILABLE_EXCEPTION ProductNotAvialable(__FILE__, __LINE__)

using namespace std;

class CartException : public logic_error
{
protected:
    string where;
    int line;
public:
    CartException(const string &where, int line, const string message);

    virtual ~CartException() = default;

    virtual string description() const = 0;
};


class FullCartException : public CartException
{
public:
    FullCartException(const string &where, int line);

    ~FullCartException() = default;

    string description() const;
};


class NotInCartException : public CartException
{
public:
    NotInCartException(const string &where, int line);

    ~NotInCartException() = default;

    string description() const;
};

class ProductNotAvialable : public CartException
{
public:
    ProductNotAvialable(const string &where, int line);

    ~ProductNotAvialable() = default;

    string description() const;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_CARTEXCEPTION_H
