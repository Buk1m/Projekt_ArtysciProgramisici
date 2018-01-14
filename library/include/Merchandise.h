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

public:
    Merchandise(const string &name, const float &price);

    virtual ~Merchandise() = default;

    virtual string getSpecification() const = 0;
    float getPrice() const;
/*    virtual vector<shared_ptr<Merchandise>>& resupply(const shared_ptr<Merchandise> &merchandise,
                                                      const int &quantity) = 0;*/
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISE_H
