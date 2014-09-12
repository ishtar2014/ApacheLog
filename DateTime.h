#pragma once
#include "AllHeaders.h"

using namespace std;


class DateTime
{
protected:
    int dataiczas;
public:
    DateTime();
    DateTime(string dit);
    virtual ~DateTime();

    ///Metody:
    virtual void wyswietl();
};

