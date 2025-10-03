#include <iostream>
using namespace std;
#include <string>

int main() {

    // Pirma uzduotis

    string vardas = "Tautvydas";
    string pavarde = "Bagdzius";
    int amzius = 25;
    string grupe = "PI25";
    int kursas = 1;
    string studijuProgramosPavadinimas = "Programu sistemos";
    cout << "Vardas: " << vardas << endl;
    cout << "Pavarde: " << pavarde << endl;
    cout << "Amzius: " << amzius << endl;
    cout << "Grupe: " << grupe << endl;
    cout << "Kursas: " << kursas << endl;
    cout << "StudijuProgramosPavadinimas: " << studijuProgramosPavadinimas << endl;

    // Antra uzduotis

    string klubas = "Banga";
    int metaiIkurimo = 1966;
    string savininkas = "Rimantas Mikalauskas";
    string arena = "Gargzdu miesto stadionas";
    int vietuSkaicius = 2300;
    cout << "Klubas: " << klubas << endl;
    cout << "Ikurimo metai: " << metaiIkurimo << endl;
    cout << "Savininkas: " << savininkas << endl;
    cout << "Arena: " << arena << endl;
    cout << "Vietu skaicius: " << vietuSkaicius << endl;

    // Trecia uzduotis

    string marke = "Subaru";
    string modelis = "Forester";
    int pagaminimoMatai = 2014;
    float litrazas = 2.0;
    string spalva = "baltos";
    cout << "Automobilis " << marke << " " << modelis << " yra pagamintas " << pagaminimoMatai << " metais. Jo motoras " << litrazas <<" litrazo. Automobilis yra " << spalva << " spalvos." << endl;

    // Ketvirta uzduotis

    int a, b;
    float c;
    a = 13;
    b = 5;
    c = 17.5;
    cout << a + b - c << endl;
    cout << 15 / 2 + c << endl; // klaida
    cout << a / static_cast<double>(b) + 2 * c << endl;
    cout << 14 % 3 +6.3 + b / a << endl;
    cout << static_cast<int>(c) % 5 + a - b << endl;
    cout << 13.5 / 2 + 4.0 * 3.5 + 18 << endl;

    // Penkta uzduotis

    float pirmasSk, antrasSk, treciasSk, ketvirtasSk, penkasSk, sumaSk;
    cout << "Ivesk penkis skaicius: " << endl;
    cin >> pirmasSk >> antrasSk >> treciasSk >> ketvirtasSk >> penkasSk;
    sumaSk = (pirmasSk + antrasSk + treciasSk + ketvirtasSk + penkasSk) / 5;
    cout << "vidurkis: " << sumaSk << endl;

    // Sesta uzduotis

    int skaicius1, skaicius2, skaicius3, atsakymas;
    cout << "Ivesk dvizenkli skaiciu: " << endl;
    cin >> skaicius1;
    skaicius2 = skaicius1 / 10;
    skaicius3 = skaicius1 % 10;
    atsakymas = skaicius2 + skaicius3;
    cout << atsakymas << endl;
    return 0;
}
