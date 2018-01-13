//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CLIENTMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CLIENTMANAGER_H

#include <memory>
#include "ClientRepository.h"

using namespace std;

class Client;

class Clientmanager
{
private:
    shared_ptr<ClientRepository> clientRepository;
public:
    Clientmanager();

    ~Clientmanager() = default;

    void createClient(shared_ptr<Client> client);

    void removeClient(shared_ptr<Client> client);
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTMANAGER_H
