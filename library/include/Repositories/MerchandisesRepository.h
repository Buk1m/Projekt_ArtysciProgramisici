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
    explicit MerchandisesRepository() = default;
    ~MerchandisesRepository() = default;

    void create(const shared_ptr<Merchandise> merchandise) override;
    void remove(const shared_ptr<Merchandise> merchandise) override;
    const vector<shared_ptr<Merchandise>> getMerchandises() const;
    unsigned long getRepositorySize() const override;
    const string getAll() const override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISEREPOSITORY_H
