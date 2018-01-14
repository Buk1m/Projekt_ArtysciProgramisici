//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Components/Display.h"
#include <sstream>

Display::Display(const string &name, float price, int quantity, const string &inches,
                 const string &frequency, const string &panelTechnology)
        : Merchandise(name, price, quantity),
          inches(inches),
          frequency(frequency),
          panelTechnology(panelTechnology)
{}

string Display::getSpecification() const
{
    stringstream specification;
    specification << "Display" << endl
                  << name << endl
                  << "Size : " << inches << " inches" << endl
                  << "Frequency : " << frequency << " Hz" << endl
                  << "PanelTechnology : " << panelTechnology << endl
                  << "Price : " << price << " PLN" << endl
                  << "Quantity : " << quantity << endl;
    return specification.str();
}

