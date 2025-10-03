#include <iostream>
#include <string>
using namespace std;

bool ratas = true;

string kursaiPavadinimai[3] = {"Didziosios Britanijos svaras","Jungtiniu Amerikos valstiju doleris","Indijos rupija"};
string kursaiTrumpiniai[3] = {"GBP","USD","INR"};
string funkcijos[4] = {"Nutraukti programa","Palyginti","Pirkti","Parduoti"};
string poPasirinkimo[4] = {"Pasirinkote nutraukti programa!","palyginti","pirkti","parduoti"};

double kursai[3][3] {
    {0.8729, 1.792, 104.6918},
    {0.8600, 1.1460, 101.3862},
    {0.9220, 1.2340, 107.8546}
};

int pasirinkimas[2];

double rezultatas, kiekis;

int main()
{
    while(ratas == true) {
        cout << "Pasirinkite funkcija:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << i << ": " << funkcijos[i] << endl;
        }
        cin >> pasirinkimas[0];
        if(pasirinkimas[0] != 0) {
            cout << "Kokia valiuta norite " << poPasirinkimo[pasirinkimas[0]] << endl;
            for(int i = 0; i < 3; i++) {
                cout << i + 1 << ": " << kursaiTrumpiniai[i] << " " << kursaiPavadinimai[i] << endl;
            }
            cin >> pasirinkimas[1];
            cout << "Iveskite norima " << poPasirinkimo[pasirinkimas[0]] << " kieki:" << endl;
            cin >> kiekis;
            rezultatas = kursai[pasirinkimas[0] - 1][pasirinkimas[1] - 1] * kiekis;
            cout << rezultatas << endl;
        }
        else {
            cout << poPasirinkimo[pasirinkimas[0]] << endl;
            ratas = false;
        }
    }
}

// Valiutos keityklos užduotis
// Parašykite programą, kuri keičia valiutą į kitą pasirinktą valiutą.
// Valiutos keityklos programėlė turi tris pasirinkimus:

// Valiutos kurso palyginimas su kita valiuta. (2 taškai)
// Galimybė įsigyti valiutos (t. y. pirkti valiutą). (2 taškai)
// Galimybė parduoti valiutą (t. y. parduoti valiutą). (2 taškai)

// Vartotojas pasirenka:

// kokią pasirinkimą naudos (palyginti, pirkti ar parduoti);
// valiutą;
// įveda valiutos kiekį, kurį nori pirkti arba parduoti.
// Po paskaičiavimų vartotojas ekrane turi pamatyti, kokį kiekį gaus valiutos. (2 taškai)

// Skaičiai turi būti apvalinti šimtųjų tikslumu. (1 taškas)

// Užduotį atlikite iki spalio 9 d. Kodas turi būti patalpintas į GitHub’ą, atlikti mažiausiai tris atnaujinimus (git add ., git commit, git push). (1 taškas)

// Papildoma informacija
// Programėlė gali konvertuoti keturias valiutas:

// Eurą (EUR)
// Didžiosios Britanijos svarą (GBP)
// Jungtinių Amerikos Valstijų dolerį (USD)
// Indijos rupiją (INR)
// Valiutų konvertavimo pavyzdžiai
// Svarbu: kaina nurodyta, kiek už 1 eurą gauname pasirinktos valiutos.

// Pvz.:

// jeigu vartotojas nori nusipirkti Didžiosios Britanijos svarų ir duoda 1 €, jis gaus 0,86 £,
// jeigu vartotojas nori parduoti 1 £, jis gaus 0,922 €.
