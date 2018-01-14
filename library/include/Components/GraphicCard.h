//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_GRAPHICCARD_H
#define PROJEKT_ARTYSCIPROGRAMISICI_GRAPHICCARD_H

#include <iostream>
#include "../Merchandise.h"

using namespace std;

class GraphicCard : public Merchandise
{
private:
    string vRam;
    string coreClockSpeed;
    string memorySpeed;

public:
    GraphicCard(const string &name, float price, int quantity, const string &vRam,
                const string &coreClockSpeed, const string &memorySpeed);
    ~GraphicCard() = default;

    string getSpecification() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_GRAPHICCARD_H
