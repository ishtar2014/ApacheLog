#include "AllHeaders.h"

using namespace std;
/*
string wczytajDane()

{
    string linia;
    ifstream Logs;                  //otwieranie pliku do odczytu
    Logs.open("Logs.txt");
    while(Logs.peek() !=EOF)        //dopoki nie napotkamy konca pliku
    {
        getline(Logs, linia);
        cout << linia << endl;

    }
    return linia;
}
*/
void stworzLogi(string log)
{


}
/*
vector<string> dzielNaLogi(string log)
{
    vector<string> wektor;
    uint a =0;
    uint b = 0;
    for(;;)
    {
        b = log.find ('\n', a);
        if(b==string::npos)
        {
            wektor.push_back(log.substr(a));
            return wektor;
        }

        wektor.push_back(log.substr(a, b-a));
        a = b+1;
    }
    return wektor;
}
*/

string znajdzBajty(string log)
{
    string byte("");
    string::size_type a=0, b=0;
    for(string::size_type i = 0; i<log.size(); i++)
    {
        a = log.find(' ', b);
        b = log.find(' ', a+1);
        if(i==8)
        {
            byte += log.substr(a+1, b-a-1);
            return byte;
        }
        a=b+1;
    }
    return byte;
}

int bajtNaInt(string byte)
{
    return atoi(byte.c_str());
}

int wyciagnijBajty(string log)
{
    return bajtNaInt(znajdzBajty(log));
}

vector<string> wytnijIP(string log)
{
    vector<string> ip;
    vector<char> delimeter;
    delimeter.push_back(2);
    delimeter.push_back('.');
    delimeter.push_back(' ');
    string::size_type a=0, b=0;
    char delimeter1 = 0, delimeter2 = 0;
    for(int i = 0; i<4; i++)
    {
        if(i==0) {delimeter1 = 0; delimeter2=1;}
        if(i==1 || i == 2) {delimeter1 = 1; delimeter2=1;}
        if(i==3) {delimeter1 = 1; delimeter2 = 2;}
        a = log.find(delimeter.at(delimeter1), b);
        b = log.find(delimeter.at(delimeter2), a+1);
        if(b==string::npos)
        {
            ip.push_back(log.substr(a));
            return ip;
        }
        ip.push_back(log.substr(a+1, b-a-1));
        a=b+1;
    }
    return ip;
}

vector<int> stworzInt(vector<string> stringip)
{
    vector<int> ip;
    for(string::size_type i =0; i<stringip.size(); i++)
    {
        ip.push_back(atoi(stringip.at(i).c_str()));
    }
    return ip;
}

vector<int> stworzIP(string log)
{
    return stworzInt(wytnijIP(log));
}



vector<string> wytnijDate(string log)
{
    vector<string> data;
    vector<char> delimeter;
    delimeter.push_back('[');
    delimeter.push_back('/');
    delimeter.push_back(':');
    delimeter.push_back(' ');
    string::size_type a=0,b=0;

    int delimeter1 = 0, delimeter2 = 0;
    for(int i = 0; i<6; i++)
    {
        if(i==0) {delimeter1=0; delimeter2=1;}                       ///Znajduje tekst pomiedzy [ a / i wrzuca do wektora
        else if(i==1) {delimeter1=1; delimeter2=1;}                  ///Znajduje tekst pomiedzy / a / i wrzuca do wektora
        else if(i==2) {delimeter1=1; delimeter2=2;}                  ///Znajduje tekst pomiedzy / a : i wrzuca do wektora
        else if(i==3 || i == 4) {delimeter1=2; delimeter2=2;}
        else if(i==5) {delimeter1=2; delimeter2=3;}

        a = log.find(delimeter.at(delimeter1), b);
        b = log.find(delimeter.at(delimeter2), a+1);
        if(b==string::npos)
        {
            data.push_back(log.substr(a));
            return data;
        }
        data.push_back(log.substr(a+1, b-a-1));
        a=b+1;

    }
    return data;
}

string dataDlaLudzi(string log)
{
    string data;
    string::size_type a=0,b=0;
    a = log.find('[', b);
    b = log.find(' ', a+1);
    if(b==string::npos)
    {
        data+=(log.substr(a));
        return data;
    }
    data+=(log.substr(a+1, b-a-1));
    return data;
}

int miesiacNaLiczbe(string s)
{
    map<string, int> miesiac;
    miesiac ["Jan"] = 1;
    miesiac ["Feb"] = 2;
    miesiac ["Mar"] = 3;
    miesiac ["Apr"] = 4;
    miesiac ["May"] = 5;
    miesiac ["Jun"] = 6;
    miesiac ["Jul"] = 7;
    miesiac ["Aug"] = 8;
    miesiac ["Sep"] = 9;
    miesiac ["Oct"] = 10;
    miesiac ["Nov"] = 11;
    miesiac ["Dec"] = 12;

    return miesiac[s];
}

int naStructTM(vector<string> data)     ///przyjmij string i przeksztalc na strukture tm
{

    tm time;
    time.tm_sec = atoi(data.at(5).c_str());
    time.tm_min = atoi(data.at(4).c_str());
    time.tm_hour = atoi(data.at(3).c_str());
    time.tm_mday = atoi(data.at(0).c_str());
    time.tm_mon = miesiacNaLiczbe(data.at(1));
    time.tm_mon -=1;
    time.tm_year = atoi(data.at(2).c_str());
    time.tm_year -= 1900;

    return mktime(&time);
}

int epoch(string a)
{
    return naStructTM(wytnijDate(a));
}
