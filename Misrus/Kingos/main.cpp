#include <iostream>

using namespace std;

string vardas[100];
int pazimiai[100][10];
int ivesti = 0;

int main() {
    while (true) {
        int programa;
        cout << "Pasirink veiksma" << endl;
        cout << "1 Ivesti mokini ir pazymius" << endl;
        cout << "2 Paziureti visu pazymius" << endl;
        cout << "3 Pataisyti pazimi" << endl;
        cout << "4 Pasalinti mokini" << endl;
        cin >> programa;
        switch (programa) {
            case 1: {
                cout << "Ivesk mokinio varda" << endl;
                cin >> vardas[ivesti];
                for (int i = 0; i <= 9; i++) {
                    cout << "ivesk " << i << " pazimi" << endl;
                    cin >> pazimiai[ivesti][i];
                }
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Ivyko klaida!" << endl;
                break;
            }
        }
    }
}
