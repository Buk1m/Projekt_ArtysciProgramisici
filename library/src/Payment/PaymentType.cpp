//
// Created by 4DAM on 13.01.2018.
//

#include "../../include/Payment/PaymentType.h"

PaymentType::PaymentType()
            : paymentId(boost::uuids::random_generator()())
{}

const float PaymentType::getPaymentPrice() const
{
    return paymentPrice;
}
