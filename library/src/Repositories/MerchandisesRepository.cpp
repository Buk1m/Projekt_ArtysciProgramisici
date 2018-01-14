//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../../include/Repositories/MerchandisesRepository.h"
#include "../../include/Merchandise.h"

MerchandisesRepository::MerchandisesRepository()
{}

void MerchandisesRepository::create(const shared_ptr<Merchandise> &merchandise)
{
    objects.push_back(merchandise);
}

void MerchandisesRepository::remove(const shared_ptr<Merchandise> &merchandise)
{
    auto it = find(objects.begin(), objects.end(), merchandise);
    objects.erase(it);
}

const string MerchandisesRepository::getAll() const
{
    stringstream info;
    info << "== MerchandisesRepository ==\n";
    for (auto merchandise : objects)
    {
        info << merchandise->getSpecification();
    }
    info << "============================" << endl;
    return info.str();
}
