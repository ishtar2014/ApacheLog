#include "AllHeaders.h"

using namespace std;
int ileLogow; //zmienna zliczajaca ile jest linii logow zczytanych z pliku

vector<string> wczytajDane()

{
    vector<string>linieLogow;
    string linia;
    ifstream Logs;
                     //otwieranie pliku do odczytu
    Logs.open("Logs.txt");
    while(Logs.peek() !=EOF)        //dopoki nie napotkamy konca pliku
    {
        getline(Logs, linia);
        //cout << linia << endl;
        linieLogow.push_back(linia);
        ileLogow++;

    }
    return linieLogow;
}


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

string znajdzPrzegladarke(string log)
{
    string brow("");
    int mo=0, ch =0, op =0, ie=0 ;

    mo = log.find("Mozilla", 0);
    ch = log.find("Chrome", 0);
    op = log.find("Opera", 0);
    ie = log.find("Internet Explorer", 0);

  //  cout <<"mo= " <<  mo << "\tch= " << ch <<"\top= " << op << "\tie = "<< ie<< endl;

    if( mo >= 1) { return brow = "Mozilla";}
    else if(ch >= 1 ) { return brow= "Chrome";}
    else if( op >= 1) {return brow= "Opera";}
    else if( ie >= 1) { return brow= "IE";}
    else return brow = "Other";
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

vector<uint8_t> stworzInt(vector<string> stringip) //zmienia stringi ip na inty)
{
    vector<uint8_t> ip;
    for(string::size_type i =0; i<stringip.size(); i++)
    {
        ip.push_back(atoi(stringip.at(i).c_str()));
    }
    return ip;
}

vector<uint8_t> stworzIP(string log)
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
