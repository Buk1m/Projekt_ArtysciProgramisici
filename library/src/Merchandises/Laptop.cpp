//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Merchandises/Laptop.h"
#include "../../include/Exceptions/MerchandiseException.h"
#include <sstream>


Laptop::Laptop(const string &name, float price, const string &processor,
               const string &graphicCard, const string &ram,
               const string &discDrive, const string &display)
       : Merchandise(name, price),
         processor(processor),
         graphicCard(graphicCard),
         ram(ram),
         discDrive(discDrive),
         display(display)
{}

Laptop::Laptop(const shared_ptr<Laptop> &laptop)
        : Merchandise(laptop->name, laptop->price),
          processor(laptop->processor),
          graphicCard(laptop->graphicCard),
          ram(laptop->ram),
          discDrive(laptop->discDrive),
          display(laptop->display)
{}


Laptop::Laptop(const Laptop* laptop)
        : Merchandise(laptop->name, laptop->price),
          processor(laptop->processor),
          graphicCard(laptop->graphicCard),
          ram(laptop->ram),
          discDrive(laptop->discDrive),
          display(laptop->display)
{}

string Laptop::getSpecification() const
{
    stringstream info;
    info << "-----------Laptop-----------" << endl
         << "Id: " << merchandiseId << endl
         << "Name: " << name << endl
         << "Processor: " << processor << endl
         << "GraphicCard: " << graphicCard << endl
         << "Ram: " << ram << endl
         << "DiscDrive: " << discDrive << endl
         << "Display: " << display << endl
         << "Price: " << price << " PLN" << endl
         << "Availability: " << getAvailability() << endl;
    return info.str();
}

vector<shared_ptr<Laptop>> Laptop::resupply(const int &quantity)
{
    if(quantity < 0)
    {
        throw INVALID_QUANTITY_EXCEPTION;
    }
    vector<shared_ptr<Laptop>> laptops;
    for(int i=0; i<quantity; i++)
    {
        auto product = make_shared<Laptop>(this);
        laptops.push_back(product);
    }
    return laptops;
}

string Laptop::loadSpecification() const
{
    stringstream info;
    info << endl
         << name << endl
         << processor << endl
         << graphicCard << endl
         << ram << endl
         << discDrive << endl
         << display << endl
         << price;
    return info.str();
}

const string Laptop::getMerchandiseType() const
{
    return "Laptop";
}