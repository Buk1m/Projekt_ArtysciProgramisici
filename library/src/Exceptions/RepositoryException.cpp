//
// Created by Bartek on 1/15/2018.
//

#include "../../include/Exceptions/RepositoryException.h"


RepositoryException::RepositoryException(const string &message, const string &where, int line)
                    : logic_error(message),
                      where(where),
                      line(line)
{}

ObjectNotFoundException::ObjectNotFoundException(const string &where, int line)
                        : RepositoryException("Object does not exit in repository", where, line)
{}

std::__cxx11::basic_string<char> ObjectNotFoundException::description() const
{
    stringstream sout;
    sout << what()
         << " [" << where << " line " << line << "]:" << endl;
    return sout.str();;
}
