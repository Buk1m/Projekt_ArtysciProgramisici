//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEREPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEREPOSITORY_H

#include "Repository.h"

class Merchandise;

class MerchandisesRepository
        : public Repository<Merchandise>
{
private:
    vector<shared_ptr<Merchandise>> merchandises;
public:
    MerchandisesRepository();

    ~MerchandisesRepository() = default;

    void create(shared_ptr<Merchandise> merchandise);

    void remove(shared_ptr<Merchandise> merchandise);

    string getAll();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEREPOSITORY_H
