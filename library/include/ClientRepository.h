//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H

#include "Repository.h"
#include "Client.h"

class ClientRepository
        : public Repository
{
private:
    vector<shared_ptr<Client>> clients;

public:
    ClientRepository();

    ~ClientRepository() = default;

    void create(shared_ptr<Client> client);
    void remove(shared_ptr<Client> client);
    void update(shared_ptr<Client> client, string update);
    string getAll();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H
