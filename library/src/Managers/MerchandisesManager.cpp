//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/MerchandisesManager.h"
#include "../../include/Repositories/MerchandisesRepository.h"
#include "../../include/Merchandises/Laptop.h"
#include "../../include/Merchandises/Smartphone.h"
#include <typeinfo>
#include <fstream>

using namespace std;

MerchandisesManager::MerchandisesManager(shared_ptr<MerchandisesRepository>& merchandiseRepository)
                    :merchandiseRepository(merchandiseRepository)
{}

void MerchandisesManager::createMerchandise(const shared_ptr<Merchandise> &merchandise)
{
    merchandiseRepository->create(merchandise);
}

void MerchandisesManager::removeMerchandise(const shared_ptr<Merchandise> &merchandise)
{
    merchandiseRepository->remove(merchandise);
}

void MerchandisesManager::resupplyMerchandise(const shared_ptr<Laptop> &laptop, const int &quantity)
{
    vector< shared_ptr<Laptop> > laptops = laptop->resupply(quantity);
    for(auto lap : laptops)
    {
        merchandiseRepository->create(lap);
    }
}

void MerchandisesManager::resupplyMerchandise(const shared_ptr<Smartphone> &smartphone, const int &quantity)
{
    vector< shared_ptr<Smartphone> > smartphones = smartphone->resupply(quantity);
    for(auto smart : smartphones)
    {
        merchandiseRepository->create(smart);
    }
}
void MerchandisesManager::pullLaptopSpecsFromFile()
{
    ifstream file;

    string name, processor, graphicCard, ram, discDrive, display, camera;
    float price;
    file.open ("laptopsData.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> name;
            file >> processor;
            file >> graphicCard;
            file >> ram;
            file >> discDrive;
            file >> display;
            file >> price;
            auto laptop = make_shared<Laptop>(name, price, processor,
                                              graphicCard, ram, discDrive, display);
            createMerchandise(laptop);
        }
    }
    file.close();
    //else
        //throw;
}

void MerchandisesManager::pullSmartphoneSpecsFromFile()
{
    ifstream file;

    string name, processor, graphicCard, ram, discDrive, display, camera;
    float price;
    file.open ("smartphonesData.txt", ios::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> name;
            file >> processor;
            file >> graphicCard;
            file >> ram;
            file >> discDrive;
            file >> display;
            file >> price;

            auto laptop = make_shared<Laptop>(name, price, processor,
                                              graphicCard, ram, discDrive, display);
            createMerchandise(laptop);
        }
    }
    file.close();
    //else
    //throw;
}

void MerchandisesManager::pushLaptopSpecsToFile()
{
    ofstream file;
    string classTypeName;
    file.open ("laptopsData.txt", ios::out);
    if (file.is_open())
    {
        auto merchandises = merchandiseRepository->getMerchandises();

        for(auto merchandise : merchandises)
        {
            classTypeName = typeid(merchandise).name();
            if(classTypeName == "Laptop")
                file << merchandise->loadSpecification() << endl;
        }
        file.close();
    }
}

void MerchandisesManager::pushSmartphoneSpecsToFile()
{
    ofstream file;
    string classTypeName;

    float price;
    file.open ("smartphonesData.txt", ios::out);
    if (file.is_open())
    {
        auto merchandises = merchandiseRepository->getMerchandises();

        for(auto merchandise : merchandises)
        {
            classTypeName = typeid(merchandise).name();
            if(classTypeName == "Smartphone")
                file << merchandise->loadSpecification() << endl;
        }
        file.close();
    }
}
