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
<<<<<<< HEAD
    ~Repository();
=======
    virtual ~Repository(){}
>>>>>>> f89b14d8a56692bbe209b01c1c8e51cd61ad6482

    //metody
    virtual void    create(shared_ptr<objectType> object) = 0;
    virtual void    remove(shared_ptr<objectType> object) = 0;
    virtual string  getAll() = 0;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_REPOSITORY_H
