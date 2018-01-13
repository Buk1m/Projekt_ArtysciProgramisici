//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CART_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CART_H

#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Merchandise;



class Cart
{
private:
    vector<shared_ptr<Merchandise>> products;

public:
    Cart();
    ~Cart();

public:
    //getters
    string getProductInfo() const;
    float getAllProductsPrice() const;
    vector<shared_ptr<Merchandise>> getProducts() const;

    //setters
    void addProduct(const shared_ptr<Merchandise> &product);
    void removeProduct(const shared_ptr<Merchandise> &product);

    //methods
    void clearCart();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CART_H
