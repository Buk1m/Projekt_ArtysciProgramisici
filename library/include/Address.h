//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_ADDRESS_H
#define PROJEKT_ARTYSCIPROGRAMISICI_ADDRESS_H

#include <string>
using namespace std;

class Address
{
private:
    string street;
    string number;
public:
    Address(const string &street, const string &number);

    ~Address() = default;

    const string getAddressInfo() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_ADDRESS_H
