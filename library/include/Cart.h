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
    int maxCartCapacity;

public:
    explicit Cart(const int &maxCartCapacity);
    ~Cart() = default;

    const string getProductInfo() const;
    const float getAllProductsPrice() const;
    const vector<shared_ptr<Merchandise>> &getProducts() const;
    const int getProductsQuantity() const;

    void addProduct(const shared_ptr<Merchandise> &product);
    void removeProduct(const shared_ptr<Merchandise> &product);
    void clearCart();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CART_H
