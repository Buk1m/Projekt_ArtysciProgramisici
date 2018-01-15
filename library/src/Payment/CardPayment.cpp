//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Payment/CardPayment.h"

CardPayment::CardPayment()
            :PaymentType()
{
    paymentPrice = 5.0;
}

float CardPayment::makeDiscount(int productsQuantity)
{
    return (paymentPrice - (productsQuantity * 2) / 10);
}

const string CardPayment::getPaymentTypeName()
{
    return "CardPayment";
}

