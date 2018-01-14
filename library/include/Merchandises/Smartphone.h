//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_SMARTPHONE_H
#define PROJEKT_ARTYSCIPROGRAMISICI_SMARTPHONE_H

#include <iostream>
#include <memory>
#include "../Merchandise.h"

using namespace std;

class Smartphone : public Merchandise
{
private:
    string processor;
    string display;
    string camera;
    string ram;
public:
    Smartphone(const string &name, const float &price, const string &processor,
               const string &display, const string &camera, const string &ram);
    Smartphone(const shared_ptr<Smartphone> &smartphone);
    Smartphone(const Smartphone* smartphone);
    ~Smartphone() = default;

    string getSpecification() const;
    vector<shared_ptr<Smartphone>> resupply(const int &quantity);
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_SMARTPHONE_H
