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
public:
    explicit ClientRepository() = default;
    ~ClientRepository() = default;

    void create(const shared_ptr<Client> client) override;
    void remove(const shared_ptr<Client> client) override;
    unsigned long getRepositorySize() const override;
    const string getAll() const override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTREPOSITORY_H
