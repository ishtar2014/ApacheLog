#pragma once
#include "AllHeaders.h"

using namespace std;
///TWORZENIE LOGOW - sprawdzic i poprawic
//string wczytajDane();
void stworzLogi();
//vector <string> dzielNaLogi(string log);            ///dzieli na poszczegolne logi

///WYCIAGANIE LICZBY BAJTOW I PRZEGLADARKI
string znajdzBajty(string log);
int bajtNaInt(string log);
int wyciagnijBajty(string log);

string znajdzPrzegladarke(string log);


///TWORZENIE IP
vector<string> wytnijIP(string log);                ///wycina ip ze stringa
vector<int> stworzInt(vector<string> stringip);      ///przeksztalca string ip na int
vector<int> stworzIP(string log);

///TWORZENIE DATY
int miesiacNaLiczbe(string s);          ///zmiana slowa miesiaca na liczbe
int naStructTM(vector<string> data);    ///robi strukture tm i przeksztalca na int
vector<string> wytnijDate(string log);
int epoch(string a);
string dataDlaLudzi(string log);
