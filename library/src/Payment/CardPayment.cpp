//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Payment/CardPayment.h"
#include "../../include/Exceptions/MerchandiseException.h"

CardPayment::CardPayment()
            : PaymentType()
{
    paymentPrice = 5.0;
}

float CardPayment::makeDiscount(const int &productsQuantity) const
{
    if (productsQuantity <= 0)
    {
        throw INVALID_QUANTITY_EXCEPTION;
    }
    return (paymentPrice - (productsQuantity * 2) / 10);
}

const string CardPayment::getPaymentTypeName() const
{
    return "CardPayment";
}

