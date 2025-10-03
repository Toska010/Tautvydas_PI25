#include <iostream>
#include <string>

using namespace std;

// 1 uzduotis

string Vardas = "Tautvydas";
string Pavarde = "Bagdzius";
int Amzius = 24;
int Grupe = 1;
int Kursas = 1;
string Programa = "Sistemu programos";

// 2 uzduotis

string Pavadinimas2 = "Kauno Zalgiris";
int Metai2 = 1995;
string Savininkas = "Anonimas Anonimu";
string Arena = "Zalgirio";
int VietuSk = 5000;

// 3 uzduotis

string Marke = "Subaru";
string Modelis = "Forrester";
int Metai3 = 2016;
double Litrazas = 5.6;
string Spalva = "Balta";

// 4 uzduotis

int a = 13;
int b = 5;
double c = 17.5;

// 5 uzduotis

double aa = 0;
double bb = 0;
double cc = 0;
double dd = 0;
double ee = 0;

// 6 uzduotis

int aaa = 0;

int main()
{
    // 1 uzduotis

    cout << Vardas; cout << " ";
    cout << Pavarde; cout << " ";
    cout << Amzius; cout << " ";
    cout << Grupe; cout << " Grupe ";
    cout << Kursas; cout << " Kursas " << endl << endl;


    // 2 uzduotis

    cout << Pavadinimas2; cout << " ";
    cout << Metai2; cout << " ";
    cout << Savininkas; cout << " ";
    cout << Arena; cout << " stadijonas ";
    cout << VietuSk; cout << "vietu" << endl << endl;

    // 3 uzduotis

    cout << Marke; cout << " ";
    cout << Modelis; cout << " ";
    cout << Metai3; cout << " ";
    cout << Litrazas; cout << " ";
    cout << Spalva << endl << endl;

    // 4 uzduotis

    cout << a+b-c << endl;
    cout << 15/2+c << endl;
    cout << a/static_cast<double>(b)+2*c << endl;
    cout << 14%3+6.3+b/a << endl;
    cout << static_cast<int>(c)%5+a-b << endl;
    cout << 13.5/2+4.0*3.5+18 << endl << endl;

    // 5 uzduotis

    cout << "Ivesk 5 skaicius" << endl;
    cin >> aa; cin >> bb; cin >> cc; cin >> dd; cin >> ee;
    double ff = (aa+bb+cc+dd+ee)/5;
    cout << ff << endl << endl;

    // 6 uzduotis

    cout << "Ivesk dvzenkli skaiciu" << endl;
    cin >> aaa;
    int bbb = aaa%10;
    int ccc = (aaa-bbb)/10;
    int ddd = ccc+bbb;
    // Sudedamuju daliu skaiciavimai
    //cout << aaa; cout << "\t"; cout << bbb; cout << "\t"; cout << ccc << endl;
    cout << ddd << endl;


    return 0;
}
