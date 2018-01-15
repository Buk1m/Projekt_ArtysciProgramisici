//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/MerchandisesManager.h"
#include "../../include/Merchandises/Laptop.h"
#include "../../include/Merchandises/Smartphone.h"

MerchandisesManager::MerchandisesManager(shared_ptr<MerchandisesRepository> merchandiseRepository)
                    :merchandiseRepository(merchandiseRepository)
{}

void MerchandisesManager::createMerchandise(const shared_ptr<Merchandise> &merchandise)
{
    merchandiseRepository->create(merchandise);
}

void MerchandisesManager::removeMerchandise(const shared_ptr<Merchandise> &merchandise)
{
    merchandiseRepository->remove(merchandise);
}

void MerchandisesManager::resupplyMerchandise(const shared_ptr<Laptop> &laptop)
{
    vector< shared_ptr<Laptop> > laptops = laptop->resupply(2);
    for(auto lap : laptops)
    {
        merchandiseRepository->create(lap);
    }
}

void MerchandisesManager::resupplyMerchandise(const shared_ptr<Smartphone> &smartphone)
{
    vector< shared_ptr<Smartphone> > smartphones = smartphone->resupply(2);
    for(auto smart : smartphones)
    {
        merchandiseRepository->create(smart);
    }
}

