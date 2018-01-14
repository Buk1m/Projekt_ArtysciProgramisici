//
// Created by Bartek on 1/13/2018.
//

#include "../include/ClientsRepository.h"
#include "../include/Client.h"
#include <algorithm>

ClientRepository::ClientRepository() {}

void ClientRepository::create(const shared_ptr<Client> &client)
{
    clients.push_back(client);
}

void ClientRepository::remove(const shared_ptr<Client> &client)
{
    auto it = find(clients.begin(), clients.end(), client);
    clients.erase(it);
}

const string ClientRepository::getAll() const
{
    stringstream info;
    info << "=== ClientRepository ===\n";


    //for (auto it:clients)
    for(int i=0;i<2;i++)
    {

       info << clients[i]->getInfoAboutClient();
    }
    info << "========================" << endl;
    return info.str();
}

