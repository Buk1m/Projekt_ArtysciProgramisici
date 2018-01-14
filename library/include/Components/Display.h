//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_DISPLAY_H
#define PROJEKT_ARTYSCIPROGRAMISICI_DISPLAY_H

#include <iostream>
#include "../Merchandise.h"

using namespace std;

class Display : public Merchandise
{
private:
    string inches;
    string frequency;
    string panelTechnology;
public:
    Display(const string &name, float price, int quantity, const string &inches, const string &frequency,
            const string &panelTechnology);
    ~Display() = default;

    string getSpecification() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_DISPLAY_H
