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
    ~ClientRepository() = default;

    void create(const shared_ptr<Client> &client);
    void remove(const shared_ptr<Client> &client);
    const string getAll() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H
