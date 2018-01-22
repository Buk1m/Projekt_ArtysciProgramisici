//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/ClientsManager.h"

ClientsManager::ClientsManager(shared_ptr<ClientRepository> &clientRepository)
               :clientRepository(clientRepository)
{}

void ClientsManager::createClient(const shared_ptr<Client> &client)
{
    clientRepository->create(client);
}

void ClientsManager::removeClient(const shared_ptr<Client> &client)
{
    clientRepository->remove(client);
}

unsigned long ClientsManager::getClientRepositorySize()
{
    return clientRepository->getRepositorySize();
}



