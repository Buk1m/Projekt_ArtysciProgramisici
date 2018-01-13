//
// Created by Bartek on 1/13/2018.
//

#include "../include/ClientRepository.h"
#include <algorithm>

ClientRepository::ClientRepository()
{}

void ClientRepository::create(shared_ptr<Client> client)
{
    clients.push_back(client);
}

void ClientRepository::remove(shared_ptr<Client> client)
{
    auto it = find(clients.begin(), clients.end(), client);
    clients.erase(it);
}

void ClientRepository::update(shared_ptr<Client> client, string update)
{

}

string ClientRepository::getAll()
{
    stringstream info;
    info << "=== ClientRepository ===\n";
    for (auto it:clients)
    {
        info << it->getInfoAboutClient();
    }
    info << "========================" << endl;
    return info.str();
}

namespace kajdshfk
{


}