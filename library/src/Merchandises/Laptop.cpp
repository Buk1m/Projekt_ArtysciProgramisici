//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Merchandises/Laptop.h"
#include <sstream>

Laptop::Laptop(const string &name, float price, int quantity, const string &processor,
               const string &graphicCard, const string &ram,
               const string &discDrive, const string &display)
       : Merchandise(name, price, quantity),
         processor(processor),
         graphicCard(graphicCard),
         ram(ram),
         discDrive(discDrive),
         display(display)
{}

string Laptop::getSpecification() const
{
    stringstream info;
    info << "---------- Laptop ---------- " << endl
         << "Id: " << merchandiseId << endl
         << "Name: " << name << endl
         << "Processor: " << processor << endl
         << "GraphicCard: " << graphicCard << endl
         << "Ram: " << ram << endl
         << "DiscDrivem: " << discDrive << endl
         << "Display: " << display << endl
         << "Price: " << price << " PLN" << endl;
    return info.str();
}
