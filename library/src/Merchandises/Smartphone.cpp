//
// Created by 4DAM on 14.01.2018.
//

#include "../../include/Merchandises/Smartphone.h"
#include <sstream>

Smartphone::Smartphone(const string &name, const float &price, const string &processor,
                       const string &display, const string &camera, const string &ram)
        : Merchandise(name, price),
          processor(processor),
          display(display),
          camera(camera),
          ram(ram)
{}

Smartphone::Smartphone(const Smartphone* smartphone)
        : Merchandise(smartphone->name, smartphone->price),
          processor(smartphone->processor),
          camera(smartphone->camera),
          ram(smartphone->ram),
          display(smartphone->display)
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

vector<shared_ptr<Smartphone>> Smartphone::resupply(const int &quantity)
{
    vector<shared_ptr<Smartphone>> smartphones;
    for(int i=0; i<quantity; i++)
    {
        //auto product = make_shared<Smartphone>(this);
        //smartphones.push_back(product);
        smartphones.push_back(make_shared<Smartphone>(this));
    }
    return smartphones;
}

