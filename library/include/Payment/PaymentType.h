//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_PAYMENT_H
#define PROJEKT_ARTYSCIPROGRAMISICI_PAYMENT_H

#include <iostream>
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid_io.hpp"

using namespace std;
using namespace boost::uuids;


class PaymentType
{
protected:
    const uuid paymentId;
    float paymentPrice;

public:
    explicit PaymentType();
    virtual ~PaymentType() = default;

    const float getPaymentPrice() const;
    virtual float makeDiscount(const int &productsQuantity) const = 0;
    virtual const string getPaymentTypeName() const = 0;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_PAYMENT_H
