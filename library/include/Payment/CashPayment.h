//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CASHPAYMENT_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CASHPAYMENT_H

#include "PaymentType.h"

class CashPayment : public PaymentType
{
public:
    explicit CashPayment();
     ~CashPayment() = default;

    float makeDiscount(int productsQuantity) override;
    const string getPaymentTypeName() override;
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CASHPAYMENT_H
