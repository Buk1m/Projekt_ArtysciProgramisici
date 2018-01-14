//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H

#include <iostream>
#include <memory>
#include <vector>

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"

using namespace std;
using namespace boost::uuids;

class Merchandise
{
protected:
    uuid merchandiseId;
    string name;
    float price;
    int quantity;

public:
    Merchandise(const string &name, const float &price, const int &quantity);
    virtual ~Merchandise();

    string getSpecification() const;
    float getPrice() const;
    int getQuantity() const;
    string getInfoAboutMerchandise() const;

    void resupply(const int &quantity);
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H
