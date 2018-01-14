//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H
#define PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H

#include <iostream>
#include <memory>
#include "../Merchandise.h"

using namespace std;

class Processor;
class GraphicCard;
class Ram;
class DiskDrive;
class Display;


class Laptop : public Merchandise
{
private:
    shared_ptr<Processor> processor;
    shared_ptr<GraphicCard> graphicCard;
    shared_ptr<Ram> ram;
    shared_ptr<DiskDrive> discDrive;
    shared_ptr<Display> display;

public:
    string LaptopInfo() const;

    Laptop(const string &name, float price, int quantity, const shared_ptr<Processor> &processor,
           const shared_ptr<GraphicCard> &graphicCard, const shared_ptr<Ram> &ram,
           const shared_ptr<DiskDrive> &discDrive, const shared_ptr<Display> &display);

    ~Laptop() = default;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_LAPTOP_H
