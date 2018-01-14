//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Merchandises/Smartphone.h"
#include <sstream>

Smartphone::Smartphone(const string &name, const float &price, const int &quantity, const string &processor,
                       const string &display, const string &camera, const string &ram)
        : Merchandise(name, price, quantity),
          processor(processor),
          display(display),
          camera(camera),
          ram(ram)
{}

string Smartphone::getSpecification() const
{
    stringstream info;
    info << "-------- Smartphone -------- " << endl
         << "Id: " << merchandiseId << endl
         << "Name: " << name << endl
         << "Processor: " << processor << endl
         << "Display: " << display << endl
         << "Camera: " << camera << endl
         << "Ram: " << ram << endl
         << "Price: " << price << " PLN" << endl;
    return info.str();
}
