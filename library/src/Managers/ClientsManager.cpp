//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/ClientsManager.h"

Clientmanager::Clientmanager()
{}

void Clientmanager::createClient(const shared_ptr<Client> &client)
{
    clientRepository->create(client);
}

void Clientmanager::removeClient(const shared_ptr<Client> &client)
{
    clientRepository->remove(client);
}

