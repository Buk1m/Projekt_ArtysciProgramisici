//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Payment/CashPayment.h"

CashPayment::CashPayment()
            :PaymentType()
{
    paymentPrice = 0;
}

float CashPayment::makeDiscount(const int &productsQuantity) const
{
    return 0.0;
}

const string CashPayment::getPaymentTypeName() const
{
    return "CashPayment";
}
