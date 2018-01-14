//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Payment/CardPayment.h"

CardPayment::CardPayment()
            :PaymentType()
{
    paymentPrice = 5.0;
}

void CardPayment::makeDiscount(int productsQuantity)
{
    paymentPrice -= (productsQuantity / 2) * 0.1;
}

const string CardPayment::getPaymentTypeName()
{
    return "CardPayment";
}

