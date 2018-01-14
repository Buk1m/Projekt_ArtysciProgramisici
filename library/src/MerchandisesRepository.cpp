//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../include/MerchandisesRepository.h"
#include "../include/Merchandise.h"

MerchandisesRepository::MerchandisesRepository()
{}

void MerchandisesRepository::create(const shared_ptr<Merchandise> &merchandise)
{
    merchandises.push_back(merchandise);
}

void MerchandisesRepository::remove(const shared_ptr<Merchandise> &merchandise)
{
    auto it = find(merchandises.begin(), merchandises.end(), merchandise);
    merchandises.erase(it);
}

const string MerchandisesRepository::getAll() const
{
    stringstream info;
    info << "=== MerchandisesRepository ===\n";
    for (auto it:merchandises)
    {
        info << it->getInfoAboutMerchandise();
    }
    info << "=============================" << endl;
    return info.str();
}
