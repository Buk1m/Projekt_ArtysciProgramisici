//
// Created by 4DAM on 13.01.2018.
//
//())===================D~~~~~~~~
#ifndef PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H

#include <iostream>
#include <vector>
#include <memory>
//())===================D~~~~~~~~
using namespace std;
//())===================D~~~~~~~~
template <typename objectType, typename parametr> class Repository
{
protected:
    vector< unique_ptr<objectType> > objects;
public:
    //konstruktory
    //())===================D~~~~~~~~
    Repository();

    //destruktory
    virtual ~Repository();
    //())===================D~~~~~~~~

    //metody
    virtual void    Create(unique_ptr<objectType> object) = 0;
    virtual void    Remove(unique_ptr<objectType> object) = 0;
    virtual void    Update(unique_ptr<objectType> object, parametr update) = 0;
    //())===================D~~~~~~~~
    virtual string  GetAll() = 0;
    virtual int     Find(unique_ptr<objectType> object) = 0;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H
//())===================D~~~~~~~~

//())===================D~~~~~~~~
//())===================D~~~~~~~~