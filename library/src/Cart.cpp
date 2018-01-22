//
// Created by 4DAM on 13.01.2018.
//

#include "../include/Cart.h"
#include "../include/Merchandise.h"
#include "../include/Exceptions/CartException.h"

Cart::Cart(const int &maxCartCapacity)
     : maxCartCapacity(maxCartCapacity)
{}


const string Cart::getProductInfo() const
{
    stringstream info;
    info << "============Cart============" << endl;
    for (auto product : products)
    {
        info << product->getSpecification() << endl;
    }
    info << "============================" << endl;
    return info.str();
}

const float Cart::getAllProductsPrice() const
{
    float sum = 0;
    for (auto product : products)
    {
        sum += product->getPrice();
    }
    return sum;
}

const vector<shared_ptr<Merchandise>> &Cart::getProducts() const
{
    return products;
}


void Cart::addProduct(const shared_ptr<Merchandise> &product)
{
    if (maxCartCapacity <= products.size())
    {
        throw FULL_CART_EXCEPTION;
    }

    auto it = find(products.begin(),products.end(), product);
    if(it != products.end())
    {
        throw PRODUCT_ALREADY_IN_CART_EXCEPTION;
    }
    products.push_back(product);
}

void Cart::removeProduct(const shared_ptr<Merchandise> &product)
{
    auto it = find(products.begin(), products.end(), product);
    if(it == products.end())
    {
        throw NOT_IN_CART_EXCEPTION;
    }
    products.erase(it);
}

void Cart::clearCart()
{
    products.clear();
}

const int Cart::getProductsQuantity() const
{
    return products.size();
}
