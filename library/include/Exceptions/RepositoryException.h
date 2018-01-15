//
// Created by Bartek on 1/15/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORYEXCEPTION_H
#define PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORYEXCEPTION_H
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

#define OBJECT_NOT_FOUND_EXCEPTION ObjectNotFoundException(__FILE__, __LINE__)

using namespace std;

class RepositoryException : public logic_error
{
protected:
    string where;
    int line;
public:
    RepositoryException(const string &message, const string &where, int line);
    virtual ~RepositoryException() = default;

    virtual string description() const = 0;
};


class ObjectNotFoundException : public RepositoryException
{
public:
    ObjectNotFoundException(const string &where, int line);

    ~ObjectNotFoundException() = default;

    string description() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORYEXCEPTION_H
