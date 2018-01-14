//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H

#include "Merchandise.h"
#include "MerchandisesRepository.h"

class MerchandisesManager
{
private:
    shared_ptr<MerchandisesRepository> merchandiseRepository;
public:
    MerchandisesManager() = default;

    ~MerchandisesManager() = default;

    void createMerchandise(const shared_ptr<Merchandise> &merchandise);

    void removeMerchandise(const shared_ptr<Merchandise> &merchandise);
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H
