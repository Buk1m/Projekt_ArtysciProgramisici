//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_PROCESSOR_H
#define PROJEKT_ARTYSCIPROGRAMISICI_PROCESSOR_H

#include <iostream>
#include "../Merchandise.h"

using namespace std;

class Processor : public Merchandise
{
private:
    string generation;
    string clockSpeed;

public:
    Processor(const string &name, float price, int quantity,
              const string &generation, const string &clockSpeed);
    ~Processor() = default;

    string getSpecification() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_PROCESSOR_H
