//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H
#define PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H

#include <iostream>
#include <memory>
#include "../Merchandise.h"

using namespace std;


class Laptop : public Merchandise
{
private:
    string processor;
    string graphicCard;
    string ram;
    string discDrive;
    string display;

public:
    explicit Laptop(const string &name, const float &price, const string &processor,
                    const string &graphicCard, const string &ram,
                    const string &discDrive, const string &display);
    explicit Laptop(const Laptop* laptop);
    ~Laptop() = default;

    string loadSpecification() const override;
    string getSpecification() const override;
    vector<shared_ptr<Laptop>> resupply(const int &quantity);
    const string getMerchandiseType() const override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H
