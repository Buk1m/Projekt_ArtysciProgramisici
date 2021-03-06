//
// Created by Bartek on 1/13/2018.
//

#include <sstream>
#include <algorithm>
#include "../../include/Repositories/MerchandisesRepository.h"
#include "../../include/Merchandise.h"
#include "../../include/Exceptions/RepositoryException.h"

void MerchandisesRepository::create(const shared_ptr<Merchandise> &merchandise)
{
    objects.push_back(merchandise);
}

void MerchandisesRepository::remove(const shared_ptr<Merchandise> &merchandise)
{
    auto it = find(objects.begin(), objects.end(), merchandise);
    if(it == objects.end())
    {
       throw OBJECT_NOT_FOUND_EXCEPTION;
    }
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

const vector<shared_ptr<Merchandise>> MerchandisesRepository::getMerchandises() const
{
    return objects;
}

unsigned long MerchandisesRepository::getRepositorySize() const
{
    return objects.size();
}