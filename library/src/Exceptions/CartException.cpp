//
// Created by Bartek on 1/14/2018.
//

#include "../../include/Exceptions/CartException.h"


CartException::CartException(const string &where, int line, const string message)
              : where(where),
                line(line),
                logic_error(message)
{}

FullCartException::FullCartException(const string &where, int line)
                  : CartException(where, line, "Cart capacity exceeded.")
{}

string FullCartException::description() const
{
    stringstream sout;
    sout << what() << "Max Cart capacity is 3." << " [" << where << " line " << line << "]:" << endl;
    return sout.str();
}

NotInCartException::NotInCartException(const string &where, int line)
                   : CartException(where, line, "Product not found.")
{}

string NotInCartException::description() const
{
    stringstream sout;
    sout << what() << "Product you want to delete is not existing in Client's cart."
         << " [" << where << " line " << line << "]:" << endl;
    return sout.str();
}

ProductAlreadyInCartException::ProductAlreadyInCartException(const string &where, int line)
                              : CartException(where, line, "Product alredy exist in cart.")
{}

string ProductAlreadyInCartException::description() const
{
    stringstream sout;
    sout << what() << "Only one position of the same product allowed."
         << " [" << where << " line " << line << "]:" << endl;
    return sout.str();
}
