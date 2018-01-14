//
// Created by 4DAM on 14.01.2018.
//

#ifndef PROJEKT_ARTYSCIPROGRAMISICI_CLIENTEXCEPTION_H
#define PROJEKT_ARTYSCIPROGRAMISICI_CLIENTEXCEPTION_H

#include <iostream>
#include <stdexcept>

using namespace std;

class ClientException : public logic_error
{
public:
    ClientException(string message);
    ~ClientException() = default;
    string description();
};


#endif //PROJEKT_ARTYSCIPROGRAMISICI_CLIENTEXCEPTION_H
