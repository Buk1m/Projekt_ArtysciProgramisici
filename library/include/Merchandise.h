//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H

#include <iostream>
#include <memory>
#include <vector>

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

using namespace std;
using namespace boost::uuids;

class Merchandise
{
protected:
    uuid merchandiseId;
    string name;
    float price;
    bool availability;

public:
    explicit Merchandise(const string &name, const float &price);
    virtual ~Merchandise() = default;

    virtual string loadSpecification() const = 0;
    virtual string getSpecification() const = 0;
    float getPrice() const;
    void setAvailability(bool availability);
    const string getAvailability() const;
    virtual const string getMerchandiseType() const = 0;

    bool isAvailable() const;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H
