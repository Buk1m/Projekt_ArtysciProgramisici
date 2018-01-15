//
// Created by 4DAM on 14.01.2018.
//

#include <sstream>
#include "../../include/Exceptions/MerchandiseException.h"


MerchandiseException::MerchandiseException(const string &message, const string &where, int line) : logic_error(message),
                                                                                                   where(where),
                                                                                                   line(line)
{}

InvalidQuantityException::InvalidQuantityException(const string &where, int line) : MerchandiseException(
        "Invalid Quantity.",
        where,
        line)
{}

string InvalidQuantityException::description() const
{
    stringstream sout;
    sout << what() << "Quantity should be positive int."
         << " [" << where << " line " << line << "]:" << endl;
    return sout.str();
}

FileOpeningException::FileOpeningException(const string &where, int line) : MerchandiseException(
        "Failed to open file.", where, line)
{}

string FileOpeningException::description() const
{
    stringstream sout;
    sout << what() << "Could not open file."
         << " [" << where << " line " << line << "]:" << endl;
    return sout.str();;
}
