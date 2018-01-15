//
// Created by Bartek on 1/13/2018.
//

#include "../../include/Managers/MerchandisesManager.h"
#include "../../include/Repositories/MerchandisesRepository.h"
#include "../../include/Merchandises/Laptop.h"
#include "../../include/Merchandises/Smartphone.h"

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

    string merchandiseId, name, processor, graphicCard, ram, discDrive, display, camera;
    float price;
    file.open ("laptopsData.txt", ios::in);
    if (file.is_open())
    {
        file >> merchandiseId;
        file >> name;
        file >> processor;
        file >> graphicCard;
        file >> ram;
        file >> discDrive;
        file >> display;
        file >> price;

        auto laptop = make_shared<Laptop>(name, price , processor,
                                          graphicCard, ram, discDrive, display);
        createMerchandise(laptop);
        file.close();
    }
    //else
        //throw;
}

void MerchandisesManager::pullSmartphoneSpecsFromFile()
{
    ifstream file;

    string merchandiseId, name, processor, graphicCard, ram, discDrive, display, camera;
    float price;
    file.open("smartphonesData.txt", ios::in);
    if (file.is_open()) {
        file >> name;
        file >> processor;
        file >> display;
        file >> camera;
        file >> ram;
        file >> price;
    }
    //else
        //throw;
    auto smartphone = make_shared<Laptop>(name, price, processor, display, camera, ram);
    createMerchandise(smartphone);
}

void MerchandisesManager::pushSmartphoneSpecsToFile()
{
    ifstream file;

    string merchandiseId, name, processor, graphicCard, ram, discDrive, display, camera;
    float price;
    file.open ("smartphonesData.txt", ios::in);
    if (file.is_open())
    {
        file >> merchandiseId;
        file >> name;
        file >> processor;
        file >> graphicCard;
        file >> ram;
        file >> discDrive;
        file >> display;
        file >> price;

        auto laptop = make_shared<Laptop>(name, price , processor,
                                          graphicCard, ram, discDrive, display);
        createMerchandise(laptop);
        file.close();
    }
    //else
        //throw;
}

void MerchandisesManager::pushLaptopSpecsToFile()
{
    ofstream file;

    float price;
    file.open ("laptopsData.txt", ios::out);
    if (file.is_open())
    {
        auto laptops = merchandiseRepository->getMerchandises();
        for(auto laptop : laptops)
        {
            file << laptop->loadSpecification() << endl;
        }
        file.close();
    }

}


void MerchandisesManager::pushSmartphoneSpecsToFile()
{
    ofstream file;

    float price;
    file.open ("smartphonesData.txt", ios::out);
    if (file.is_open())
    {
        auto smartphones = merchandiseRepository->getMerchandises();
        for(auto smartphone : smartphones)
        {
            file << smartphone->loadSpecification() << endl;
        }
        file.close();
    }
}

