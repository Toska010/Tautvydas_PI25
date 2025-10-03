#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int valiutuKiekis = 3;
int funkcijosSuValiutomis = 3;

void skaiciuokle(float valiuta, int opcija, string trumpinys) {
    if (opcija == 1) {
        cout << "1 (EUR) = " << valiuta << " " << trumpinys << endl;
    }
    else if (opcija == 2) {
        cout << "1 " << trumpinys << " = " << valiuta << " (EUR)" << endl;
    }
    else if (opcija == 3) {
        cout << "1 (EUR) = " << valiuta << " " << trumpinys << endl;
    }
}

int main() {
    int jungiklis1 = 0;
    int jungiklis2 = 0;
    string valiutos[2][valiutuKiekis] = {
        {"(GBP) Didziosios Britanijos svara", "(USD) Jungtiniu Amerikos Valstiju doleri", "(INR) Indijos rupija"},
        {"(GBP)", "(USD)", "(INR)"}
    };
    string veiksmas[funkcijosSuValiutomis] = {"Pirkti", "Parduoti", "Palyginti"};
    float kursas[valiutuKiekis][funkcijosSuValiutomis];
    kursas[0][0] = 0.8600; kursas[0][1] = 0.9220; kursas[0][2] = 0.8729; // GBP
    kursas[1][0] = 1.1460; kursas[1][1] = 1.2340; kursas[1][2] = 1.1793;// USD
    kursas[2][0] = 101.3862; kursas[2][1] = 107.8546; kursas[2][2] = 104.6918;// INR


    while (true) { //while true pradzia


        cout << "Pasirinkite valiuta: " << endl;
        for (int i = 0; i < valiutuKiekis; i++) {
            cout << i + 1 << ": " << valiutos[0][i] << endl;
        }
        cout << "0: Iseiti is programos" << endl;
        cin >> jungiklis1;
        if (jungiklis1 != 0) {
            cout << "Pasirinkite funkcija: \n 1: Pirkti \n 2: Parduoti \n 3: Palyginti \n 0: Iseiti is programos" << endl;
            cin >> jungiklis2;
            if(jungiklis2 != 0) {
                if (jungiklis1 > 0 && jungiklis2 > 0) {
                    if(jungiklis1 < 4 && jungiklis2 < 4) {
                        skaiciuokle(kursas[jungiklis1 - 1][jungiklis2 - 1], jungiklis2, valiutos[1][jungiklis1 - 1]);
                    }
                }
            }
            else cout << "Pasirinkote nutraukti programa!" << endl;
        }
        else cout << "Pasirinkote nutraukti programa!" << endl;
    } // while true pabaiga
    return 0;
}
