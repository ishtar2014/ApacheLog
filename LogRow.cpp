#include "AllHeaders.h"

using namespace std;

LogRow::LogRow()
{
    cout << "Konstruktor domyslny jest pusty!" << endl;
}

//LogRow::LogRow( string log)
//{
//    ip = stworzIP(log);
//    czas = DateTime(log);
//    przegladarka = znajdzPrzegladarke(log);
//    iloscDanych = wyciagnijBajty(log);
//    cout << "Konsturktor LogRow" << endl;
//
//}

LogRow :: LogRow(string d, vector <int> ip, string p, int32_t id)
{
    DateTime data(d);
    przegladarka = p;
    iloscDanych = id;
    IP.oktet[0] = ip.at(0);
    IP.oktet[1] = ip.at(1);
    IP.oktet[2] = ip.at(2);
    IP.oktet[3] = ip.at(3);
}

LogRow::~LogRow()
{
 cout << "dekonstuktor LogRow" << endl;
}

//void LogRow::wyswietl()            ///Wyswietlanie calego loga w terminalu
//{
//    cout<< "IP: " << ip<< endl;
//    cout<< "Czas: ";
//    czas.wyswietl();//DateTime::wyswietl() ;//<< endl;
//    cout<< "Przegladarka: "<< przegladarka << endl;
//    cout<< "Ilosc danych: " << iloscDanych<< endl;
//}
void LogRow::ileKlientow(){}         ///Ile roznych klientow odwiedzilo strone
void LogRow::ileOdwiedzin(){}       ///Ile bylo odwiedzin w zadanym pkt czasu
void LogRow::maxOdwiedzin(){}        ///w jakim przedziale godzin bylo najwiecej odwiedzin
void LogRow::maxPobran(){}           ///w jakim przedziale godzin bylo najwiecej pobran
void LogRow::bestPrzegladarka(){}    ///najpopularniejsza przegladarka

