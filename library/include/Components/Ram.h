//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_RAM_H
#define PROJEKT_ARTYSCIPROGRAMISICI_RAM_H

#include <iostream>
#include "../Merchandise.h"

using namespace std;

class Ram : public  Merchandise
{
private:
    string capacity;
    string latency;
    string memorySpeed;

public:
    Ram(const string &name, float price, int quantity, const string &capacity,
        const string &latency, const string &memorySpeed);
    ~Ram() = default;

    string getSpecification() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_RAM_H
