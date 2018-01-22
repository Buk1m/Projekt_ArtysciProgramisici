//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CARDPAYMENT_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CARDPAYMENT_H

#include "PaymentType.h"


class CardPayment : public PaymentType
{
public:
    explicit CardPayment();
    ~CardPayment() = default;

    float makeDiscount(const int &productsQuantity) const override;
    const string getPaymentTypeName() const override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CARDPAYMENT_H
