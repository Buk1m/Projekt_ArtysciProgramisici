//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CLIENTMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CLIENTMANAGER_H

#include <memory>
#include "../Repositories/ClientsRepository.h"

using namespace std;

class Client;

class ClientsManager
{
private:
    shared_ptr<ClientRepository> clientRepository;
public:
    explicit ClientsManager(shared_ptr<ClientRepository> clientRepository);
    ~ClientsManager() = default;

    void createClient(const shared_ptr<Client> &client);
    void removeClient(const shared_ptr<Client> &client);
    unsigned long getClientRepositorySize();


};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTMANAGER_H
