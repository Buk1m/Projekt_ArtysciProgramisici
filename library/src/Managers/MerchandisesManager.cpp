//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/MerchandisesManager.h"
#include "../../include/Repositories/MerchandisesRepository.h"
#include "../../include/Merchandises/Laptop.h"
#include "../../include/Merchandises/Smartphone.h"
#include "../../include/Exceptions/MerchandiseException.h"

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

    file.open ("laptopsData.txt");
    if (file.is_open())
    {
        readLaptopDataAndCreateObjects(file);
        file.close();
    }
    else
        throw FILE_OPENING_EXCEPTION;
}

void MerchandisesManager::pullSmartphoneSpecsFromFile()
{
    ifstream file;

    file.open("smartphonesData.txt");
    if (file.is_open())
    {
        readSmartphoneDataAndCreateObjects(file);
        file.close();
    }
    else
        throw FILE_OPENING_EXCEPTION;


}

void MerchandisesManager::pushSmartphoneSpecsToFile()
{
    ofstream file;
    file.open ("smartphonesData.txt", ios::trunc);
    if (file.is_open())
    {
        loadMerchandiseData(file, "Smartphone");
        file.close();
    }
    else
        throw FILE_OPENING_EXCEPTION;
}

void MerchandisesManager::pushLaptopSpecsToFile()
{
    ofstream file;
    file.open ("laptopsData.txt", ios::trunc);
    if (file.is_open())
    {
        loadMerchandiseData(file, "Laptop");
        file.close();
    }
    else
        throw FILE_OPENING_EXCEPTION;
}




unsigned long MerchandisesManager::getMerchandiseRepositorySize() const
{
    return merchandiseRepository->getRepositorySize();
}

bool MerchandisesManager::compareMerchandiseType(shared_ptr<Merchandise> merchandise, string merchType)
{
    if(merchandise->getMerchandiseType() == merchType)
        return true;
    else
        return false;
}

void MerchandisesManager::loadMerchandiseData(ofstream &file, string merchType)
{
    auto merchandises = merchandiseRepository->getMerchandises();
    for(auto merchandise : merchandises)
    {
        if( compareMerchandiseType(merchandise, merchType) )
            file << merchandise->loadSpecification();
    }
}

void MerchandisesManager::readSmartphoneDataAndCreateObjects(ifstream &file)
{
    string name, processor, display, camera, ram;
    float price;

    while (!file.eof())
    {
        file >> name;
        file >> processor;
        file >> display;
        file >> camera;
        file >> ram;
        file >> price;

        auto smartphone = make_shared<Smartphone>(name, price, processor, display, camera, ram);
        createMerchandise(smartphone);
    }
}

void MerchandisesManager::readLaptopDataAndCreateObjects(ifstream &file)
{
    string name, processor, graphicCard, ram, discDrive, display;
    float price;

    while (!file.eof())
    {
        file >> name;
        file >> processor;
        file >> graphicCard;
        file >> ram;
        file >> discDrive;
        file >> display;
        file >> price;

        auto laptop = make_shared<Laptop>(name, price, processor, graphicCard, ram, discDrive, display);
        createMerchandise(laptop);
    }
}
