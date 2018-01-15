//
// Created by Bartek on 1/13/2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H
#define PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H

#include "../Merchandise.h"
#include "../Repositories/MerchandisesRepository.h"
#include <fstream>

using namespace std;

class Laptop;
class Smartphone;

class MerchandisesManager
{
private:
    shared_ptr<MerchandisesRepository> merchandiseRepository;

public:
    MerchandisesManager(shared_ptr<MerchandisesRepository>& merchandiseRepository);
    ~MerchandisesManager() = default;

    void createMerchandise(const shared_ptr<Merchandise> &merchandise);
    void removeMerchandise(const shared_ptr<Merchandise> &merchandise);

    void resupplyMerchandise(const shared_ptr<Laptop> &laptop, const int &quantity);
    void resupplyMerchandise(const shared_ptr<Smartphone> &smartphone, const int &quantity);

    void pullLaptopSpecsFromFile();
    void pullSmartphoneSpecsFromFile();
    void pushSmartphoneSpecsToFile();
    void pushLaptopSpecsToFile();

    unsigned long getMerchandiseRepositorySize() const;
};

#endif //PROJEKT_ARTYSCIPROGRAMISICI_MERCHANDISESMANAGER_H
