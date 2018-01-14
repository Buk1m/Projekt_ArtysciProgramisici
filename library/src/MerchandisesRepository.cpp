//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../include/MerchandisesRepository.h"
#include "../include/Merchandise.h"

MerchandisesRepository::MerchandisesRepository()
{}

void MerchandisesRepository::create(shared_ptr<Merchandise> merchandise)
{
    merchandises.push_back(merchandise);
}

void MerchandisesRepository::remove(shared_ptr<Merchandise> merchandise)
{
    auto it = find(merchandises.begin(), merchandises.end(), merchandise);
    merchandises.erase(it);
}

string MerchandisesRepository::getAll()
{
    stringstream info;
    info << "=== MerchandisesRepository ===\n";
    for (auto it : merchandises)
    {
        info << it->getSpecification();
    }
    info << "=============================" << endl;
    return info.str();
}
