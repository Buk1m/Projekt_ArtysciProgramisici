//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H

#include "../Merchandise.h"
#include "../Repositories/MerchandisesRepository.h"

class Laptop;
class Smartphone;

class MerchandisesManager
{
private:
    shared_ptr<MerchandisesRepository> merchandiseRepository;

public:
    MerchandisesManager(shared_ptr<MerchandisesRepository> merchandiseRepository);
    ~MerchandisesManager() = default;

    void createMerchandise(const shared_ptr<Merchandise> &merchandise);
    void resupplyMerchandise(const shared_ptr<Laptop> &laptop);
    void resupplyMerchandise(const shared_ptr<Smartphone> &smartphone);
    void removeMerchandise(const shared_ptr<Merchandise> &merchandise);
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H
