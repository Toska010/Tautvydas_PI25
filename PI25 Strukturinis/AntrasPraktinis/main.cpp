#include <iostream>
#include <string>

using namespace std;

string varduMasyvas[100];
int pazymiuMasyvas[100][10];
int mokiniuKiekis = 0;
int pildymasIki;
int pasirinkimas = 5;
int pasirinkimas2;
int uzlaikymas;
int main() {

    while (pasirinkimas != 0) {
        cout << "Pairinkite funkcija:\n1: Ivesti mokinio varda ir jo pazymius.\n2: Perziureti visu arba konkretaus mokinio pazymius.\n3: Atnaujinti konkretu pazymi mokyniui.\n4: Pasalinti mokini is saraso.\n0:Iseiti is programos." << endl;
        cin >> pasirinkimas;
        if (pasirinkimas > 4 || pasirinkimas < 0) {
            cout << "Netinkamas pasirinkimas" << endl;
        }
        if (pasirinkimas == 0) {
            break;
        }
        switch (pasirinkimas) {
            case 1: {
                cout << "Kiek mokiniu planuoji ivesti:" << endl;
                cin >> pildymasIki;
                mokiniuKiekis = mokiniuKiekis + pildymasIki;
                for (int i; pildymasIki > mokiniuKiekis + pildymasIki; i++) {
                    cout << "Ivesk varda: ";
                    cin >> varduMasyvas[i];
                    cout << "11: Baigti ivadima!"<< endl;
                    for (int j = 0; j < 10; j++) {
                        cout << "Ivesk " << j + 1 << " pazymi: ";
                        cin >> uzlaikymas;
                        if (uzlaikymas == 11) {
                            break;
                        }
                        else {
                            pazymiuMasyvas[i][j] = uzlaikymas;
                        }
                    }
                }
                break;
            }
            case 2: {
                cout << "Pasirinkite kieno pazymius norite perziureti:\n1: Visu.\n2: Konkretaus mokinio.\n0: Iseiti" << endl;
                cin >> pasirinkimas2;
                if (pasirinkimas2 == 0) {
                    break;
                }
                if (pasirinkimas2 == 1) {
                    for (int i = 0; i < mokiniuKiekis; i++) {
                        cout << varduMasyvas[i] << ": ";
                        for (int j = 0; j < 10; j++) {
                            cout << pazymiuMasyvas[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            default: {
                break;
            }
        }
    }
}
