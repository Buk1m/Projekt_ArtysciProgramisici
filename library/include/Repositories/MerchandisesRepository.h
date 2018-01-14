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
public:
    MerchandisesRepository();

    ~MerchandisesRepository() = default;

    void create(const shared_ptr<Merchandise> &merchandise);

    void remove(const shared_ptr<Merchandise> &merchandise);

    const string getAll() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEREPOSITORY_H
