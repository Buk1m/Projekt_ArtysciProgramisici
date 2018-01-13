//
// Created by 4DAM on 13.01.2018.
//

#include "../include/Cart.h"
//#include "../include/Merchandise.h"

Cart::Cart() {}

Cart::~Cart() {}

//gettery==============================================================
string Cart::getProductInfo() const
{
    stringstream info;
    info << "=================Cart=================" << endl;
    for(auto product : products)
    {
        //info << product->toString() << endl;
    }
    return info.str();
}

float Cart::getAllProductsPrice() const
{
    float sum = 0;
    for(auto product : products)
    {
        //sum += product->getPrice();
    }
    return sum;
}

vector<shared_ptr<Merchandise>> Cart::getProducts() const
{
    //return vector<shared_ptr<Merchandise>>;
}


//settery==============================================================
void Cart::addProduct(const shared_ptr<Merchandise> &product)
{
    products.push_back(product);
}

void Cart::removeProduct(const shared_ptr<Merchandise> &product)
{
    auto it = find(products.begin(), products.end(), product);
    products.erase(it);
}

void Cart::clearCart()
{
    products.clear();
}
