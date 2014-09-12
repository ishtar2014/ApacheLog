#include "AllHeaders.h"

using namespace std;


DateTime::DateTime()
{
    dataiczas = time_t(time(NULL));
}

DateTime::DateTime(string dit)
{
    int c1 = epoch(dit);
    dataiczas = c1;
}

DateTime::~DateTime()
{
    cout << "Skasowano DateTime" << endl;
}

void DateTime::wyswietl()
{
    cout << "Data: " << dataiczas << endl;
}
