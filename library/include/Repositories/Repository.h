//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename objectType> class Repository
{
protected:
    vector< shared_ptr<objectType> > objects;
public:
    //konstruktory
    Repository(){}

    //destruktory
    virtual ~Repository(){}

    //metody
    virtual void    create(const shared_ptr<objectType> &object) = 0;
    virtual void    remove(const shared_ptr<objectType> &object) = 0;
    virtual const string  getAll() const = 0;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H