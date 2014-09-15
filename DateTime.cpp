#include "AllHeaders.h"

using namespace std;


DateTime::DateTime()
{
    dataiczas = time_t(time(NULL));
    humanDate="NULL";
 //   cout << "konstruktor domyslny DT "<< endl;
}

DateTime::DateTime(string log)
{
    dataiczas = epoch(log);
    humanDate = dataDlaLudzi(log);
 //   cout << "konstruktor DateTime z argumentem" << endl;
}

DateTime::~DateTime()
{
 //   cout << "Skasowano DateTime" << endl;
}

void DateTime::wyswietl()
{
    cout << "Data: " << humanDate << endl;
}
