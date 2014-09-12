#include "AllHeaders.h"

using namespace std;

LogRow::LogRow()
{

}

LogRow::LogRow( string d,                   ///skladowe daty i czasu
                vector<int> ip,             ///skladowe IP
                browser p, int32_t id   )  ///przegladarka i ilosc danych
{
    DateTime data(d);
    przegladarka = p;
    iloscDanych=id;
    IP.oktet[0] = ip.at(0);
    IP.oktet[1] = ip.at(1);
    IP.oktet[2] = ip.at(2);
    IP.oktet[3] = ip.at(3);
}   ///przyporzadkowuje elementy adresu ip do tablicy

LogRow::~LogRow()
{

}

void LogRow::wyswietl(){}            ///Wyswietlanie calego loga w terminalu
void LogRow::ileKlientow(){}         ///Ile roznych klientow odwiedzilo strone
void LogRow::ileOdwiedzin(){}       ///Ile bylo odwiedzin w zadanym pkt czasu
void LogRow::maxOdwiedzin(){}        ///w jakim przedziale godzin bylo najwiecej odwiedzin
void LogRow::maxPobran(){}           ///w jakim przedziale godzin bylo najwiecej pobran
void LogRow::bestPrzegladarka(){}    ///najpopularniejsza przegladarka

