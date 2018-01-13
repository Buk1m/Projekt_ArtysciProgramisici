//
// Created by Bartek on 1/13/2018.
//

#include "../include/Clientmanager.h"

Clientmanager::Clientmanager()
{}

void Clientmanager::createClient(shared_ptr<Client> client)
{
    clientRepository->create(client);
}

void Clientmanager::removeClient(shared_ptr<Client> client)
{
    clientRepository->remove(client);
}

