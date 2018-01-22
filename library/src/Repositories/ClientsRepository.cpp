//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Repositories/ClientsRepository.h"
#include "../../include/Client.h"
#include "../../include/Exceptions/RepositoryException.h"
#include <algorithm>

void ClientRepository::create(const shared_ptr<Client> &client)
{
    objects.push_back(client);
}

void ClientRepository::remove(const shared_ptr<Client> &client)
{
    auto it = find(objects.begin(), objects.end(), client);
    if(it == objects.end())
    {
       throw OBJECT_NOT_FOUND_EXCEPTION;
    }
    objects.erase(it);
}

const string ClientRepository::getAll() const
{
    stringstream info;
    info << "===== ClientRepository =====\n";
    for(auto client : objects)
    {
       info << client->getInfoAboutClient();
    }
    info << "============================" << endl;
    return info.str();
}

unsigned long ClientRepository::getRepositorySize() const
{
    return objects.size();
}

