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
    Laptop(const string &name, float price, int quantity, const string &processor,
           const string &graphicCard, const string &ram,
           const string &discDrive, const string &display);
    ~Laptop() = default;

    string getSpecification() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H
