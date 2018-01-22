//
// Created by 4DAM on 14.01.2018.
//

#include <sstream>
#include "../../include/Exceptions/OrderException.h"


OrderException::OrderException(const string &message, const string &where, int line)
               : logic_error(message),
                 where(where),
                 line(line)
{}

CartIsEmptyException::CartIsEmptyException(const string &where, int line)
                     : OrderException("Cart is empty.", where, line)
{}

string CartIsEmptyException::description() const
{
    stringstream sout;
    sout << what() << "Cannot make order from empy cart. Add some products first."
         << " [" << where << " line "  << line << "]:" << endl;
    return sout.str();
}

OrderLimitException::OrderLimitException(const string &where, int line)
                    : OrderException("Orders limit exceeded.", where, line)
{}

string OrderLimitException::description() const
{
    stringstream sout;
    sout << what() << "Client can have up to 1 order at a time."
         << " [" << where << " line " << line << "]:" << endl;
    return sout.str();
}
