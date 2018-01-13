//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H

#include "Repository.h"

class Client;

class ClientRepository
        : public Repository<Client>
{
private:
    vector<shared_ptr<Client>> clients;

public:
    ClientRepository();
    virtual ~ClientRepository();

    void create(shared_ptr<Client> client);
    void remove(shared_ptr<Client> client);
    string getAll();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H
