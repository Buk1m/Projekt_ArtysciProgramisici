//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_DISCDRIVE_H
#define PROJEKT_ARTYSCIPROGRAMISICI_DISCDRIVE_H

#include <iostream>
#include "../Merchandise.h"

using namespace std;


class DiskDrive : public Merchandise
{
private:
    string diskType;
    string capacity;
public:
    DiskDrive(const string &name, float price, int quantity,
              const string &diskType, const string &capacity);
    ~DiskDrive() = default;

    string getSpecification() const;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_DISCDRIVE_H
