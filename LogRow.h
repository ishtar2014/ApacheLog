#pragma once
#include "AllHeaders.h"

using namespace std;

enum browser {None, Mozilla, Chrome, Opera, InternetExplorer, Other};

union AdresIP
{
    uint8_t oktet[4];
    uint32_t ip;
};

class LogRow
{
private:
    AdresIP IP;
    DateTime czas;
    browser przegladarka;
    int32_t iloscDanych;

public:
    ///KONSTRUKCJA/DEKONSTRUKCJA
    LogRow();
    LogRow( string dit,                     ///skladowe daty
            vector<int> ip,                 ///skladowe IP
            browser p, int32_t id   );      ///przegladarka i ilosc danych

    ~LogRow();

    ///METODY
    void wyswietl();            ///Wyswietlanie calego loga w terminalu
    void ileKlientow();         ///Ile roznych klientow odwiedzilo strone
    void ileOdwiedzin();        ///Ile bylo odwiedzin w zadanym pkt czasu
    void maxOdwiedzin();        ///w jakim przedziale godzin bylo najwiecej odwiedzin
    void maxPobran();           ///w jakim przedziale godzin bylo najwiecej pobran
    void bestPrzegladarka();    ///najpopularniejsza przegladarka

};



