#pragma once
#include "AllHeaders.h"

using namespace std;


class DateTime
{
protected:
    int dataiczas;
public:
    DateTime();
    DateTime(string log);
    ~DateTime();

    ///Metody:
    virtual void wyswietl();
};

