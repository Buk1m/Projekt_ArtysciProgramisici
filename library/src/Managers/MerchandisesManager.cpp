//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/MerchandisesManager.h"

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



