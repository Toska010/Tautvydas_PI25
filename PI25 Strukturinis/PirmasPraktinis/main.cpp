#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool ratas = true;

string kursaiPavadinimai[3] = {"Didziosios Britanijos svaras","Jungtiniu Amerikos valstiju doleris","Indijos rupija"};
string kursaiTrumpiniai[3] = {"GBP","USD","INR"};
string funkcijos[4] = {"Nutraukti programa","Palyginti","Pirkti","Parduoti"};
string poPasirinkimo[4] = {"Pasirinkote nutraukti programa!","palyginti","pirkti","parduoti"};

double kursai[3][3] {
    {0.8729, 1.792, 104.6918},
    {0.8600, 1.1460, 101.3862},
    {0.9220, 1 / 1.2340, 1 / 107.8546}
};

int pasirinkimas[2];

double rezultatas, kiekis;

int main()
{
    cout << fixed << showpoint << setprecision(2) << endl;
    while(ratas == true) {
        cout << "Pasirinkite funkcija:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << i << ": " << funkcijos[i] << endl;
        }
        cin >> pasirinkimas[0];
        if(pasirinkimas[0] != 0) {
            cout << "Kokia valiuta norite " << poPasirinkimo[pasirinkimas[0]] << ":" << endl;
            for(int i = 0; i < 3; i++) {
                cout << i + 1 << ": " << kursaiTrumpiniai[i] << " " << kursaiPavadinimai[i] << endl;
            }
            cin >> pasirinkimas[1];
            if(pasirinkimas[0] != 0 && pasirinkimas[0] != 3) {
                cout << "1 EUR = " << kursai[pasirinkimas[0] - 1][pasirinkimas[1] - 1] << " " << kursaiTrumpiniai[pasirinkimas[1] - 1] << endl;
            }
            else {
                cout << "1 " << kursaiTrumpiniai[pasirinkimas[1] - 1] << " = " << kursai[pasirinkimas[0] - 1][pasirinkimas[1] - 1] << " EUR" << endl;
            }
            cout << "Iveskite norima " << poPasirinkimo[pasirinkimas[0]] << " kieki:" << endl;
            cin >> kiekis;
            rezultatas = kursai[pasirinkimas[0] - 1][pasirinkimas[1] - 1] * kiekis;
            if(pasirinkimas[0] == 1 || pasirinkimas[0] == 2) {
                cout << kiekis << " EUR = " << rezultatas << " " << kursaiTrumpiniai[pasirinkimas[1] - 1] << endl;
            }
            else {
                cout << kiekis << " " << kursaiTrumpiniai[pasirinkimas[1] - 1] << " = " << rezultatas << " EUR" << endl;
            }
        }
        else {
            cout << poPasirinkimo[pasirinkimas[0]] << endl;
            ratas = false;
        }
    }
}
