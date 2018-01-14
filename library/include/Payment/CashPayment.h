//
// Created by 4DAM on 13.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CASHPAYMENT_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CASHPAYMENT_H

#include "PaymentType.h"

class CashPayment : public PaymentType
{
public:
    CashPayment();
     ~CashPayment() = default;

    void makeDiscount(int productsQuantity) {};
    const string getPaymentTypeName();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CASHPAYMENT_H
