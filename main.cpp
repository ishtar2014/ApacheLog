#include "AllHeaders.h"

using namespace std;

int main()
{
    string a_log1("192.77.247.23 - - [08/Sep/2014:00:09:16 +0200] \"GET /logs/access_log HTTP/1.1\" 200 184 \"http://boston.comites-it.org/\"\"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.31 (KHTML, like Gecko) Chrome/26.0.1410.64 Safari/537.31\"");
    string a_log2("204.13.200.240 - - [08/Sep/2014:00:07:09 +0200] \"GET /logs/access_log HTTP/1.1\" 200 - \"-\" \"curl/7.15.5 (x86_64-redhat-linux-gnu) libcurl/7.15.5 OpenSSL/0.9.8b zlib/1.2.3 libidn/0.6.5\"");
    string a_log3("46.33.247.139 - - [08/Sep/2014:00:28:57 +0200] \"GET /logs/access_log HTTP/1.0\" 200 2900 \"http://tamoxifen.onlc.fr/\" \"Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0)\"");

    vector<string>logi = wczytajDane();
    //cout << logi.at(1) << endl;
    //cout << ileLogow<< endl;


    //string s = znajdzPrzegladarke(logi.at(0));
    //cout << s << endl;

    DateTime dit(logi.at(2));
    dit.wyswietl();

    cout << "\n\n log row: \n" << endl;
    //LogRow l(logi.at(2));
   // l.wyswietl();

    //cout << "\033[031m \nApache log \nby M. Lamorska, M. Lysek, A. Sadowska \033[0m" << endl;
    return 0;
}
