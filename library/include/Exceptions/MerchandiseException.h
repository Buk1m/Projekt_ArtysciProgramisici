//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEEXCEPTION_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEEXCEPTION_H

#include <iostream>
#include <stdexcept>

#define FILE_OPENING_EXCEPTION FileOpeningException(__FILE__,__LINE__)
#define INVALID_QUANTITY_EXCEPTION InvalidQuantityException(__FILE__, __LINE__)

using namespace std;

class MerchandiseException : public logic_error
{
protected:
    string where;
    int line;
public:
    MerchandiseException(const string &message, const string &where, int line);

    virtual ~MerchandiseException() = default;

    virtual string description() const = 0;
};

class InvalidQuantityException : public MerchandiseException
{
public:
    InvalidQuantityException(const string &where, int line);

    ~InvalidQuantityException() = default;

    string description() const;
};

class FileOpeningException : public MerchandiseException
{
public:
    FileOpeningException(const string &where, int line);

    ~FileOpeningException() = default;

    string description() const;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEEXCEPTION_H
