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
    explicit Smartphone(const string &name, const float &price, const string &processor,
                        const string &display, const string &camera, const string &ram);
    explicit Smartphone(const shared_ptr<Smartphone> &smartphone);
    explicit Smartphone(const Smartphone* smartphone);
    ~Smartphone() = default;

    string getSpecification() const override;
    string loadSpecification() const override;
    vector<shared_ptr<Smartphone>> resupply(const int &quantity);
    const string getMerchandiseType() const override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_SMARTPHONE_H
