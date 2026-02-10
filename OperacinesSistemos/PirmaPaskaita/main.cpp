#include <iostream>

using namespace std;

int dydis = 0;

int main() {
    cout << "Ivesk masyvo dydi" << endl;
    cin >> dydis;
    int masyvas[dydis];
    for (int i = 0; i < dydis; i++) {
        cout << "Ivesk " << i + 1 << " elementa:" << endl;
        cin >> masyvas[i];
    }
    int neigiami = 0;
    for (int i = 0; i < dydis; i++) {
        if (masyvas[i] < 0) {
            neigiami = neigiami + masyvas[i];
        }
    }
    cout << "Neigiamu elementu suma: " << neigiami << endl;
    int laikinasMaz = masyvas[0];
    int laikinasDid = masyvas[0];
    for (int i = 0; i < dydis; i++) {
        if (masyvas[i] < laikinasMaz) {
            laikinasMaz = masyvas[i];
        }
        if (masyvas[i] > laikinasDid) {
            laikinasDid = masyvas[i];
        }
    }
    int sandauga = laikinasMaz * laikinasDid;
    cout << "Sandauga didziausio ir maziausio elementu: " << sandauga << endl;
    int uzlaikymas = 0;
    for (int i = 0; i < dydis; i++) {
        for (int j = 1; j < dydis; j++) {
            if (masyvas[j] < masyvas[j-1]) {
                uzlaikymas = masyvas[j-1];
                masyvas[j-1] = masyvas[j];
                masyvas[j] = uzlaikymas;
            }
        }
    }
    cout << "Surusiuotas masyvas:" << endl;
    for (int i = 0; i < dydis; i++) {
        cout << masyvas[i] << " ";
    }
    cout << endl;
    // 2 Uzduotis
    cout << "Didziausias elementas: " << masyvas[dydis - 1] << endl;
    int suma = 0;
    for (int i = 0; i < dydis; i++) {
        suma = suma + masyvas[i];
    }
    cout << "Suma elementu: " << suma << endl;
    cout << "Ivesk intervalo pradzia: " << endl;
    int pradzia;
    cin >> pradzia;
    cout << "Ivesk intervalo pabaiga: " << endl;
    int pabaiga;
    cin >> pabaiga;
    for (int i = dydis - 1; i >= 0; i--) {
        if (masyvas[i] > pradzia & masyvas[i] < pabaiga) {
            for (int j = i; j < dydis; j++) {
                if (j == dydis - 1) {
                    masyvas[j] = 0;
                }
                else {
                    masyvas[j] = masyvas[j+1];
                }
            }
        }
    }
    cout << "Masyvas: " << endl;
    for (int i = 0; i < dydis; i++) {
        cout << masyvas[i] << " ";
    }
    cout << endl;
    // 3 uzduotis
    /*bool ciklas = true;
    int dydis2;
    while (ciklas == true) {
        cout << "Ivesk masyvo dydi: " << endl;
        cin >> dydis2;
        if (dydis2 > 0) {
            if (dydis2 % 2 == 0) {
                ciklas = false;
                break;
            }
        }
    }
    int masyvas2[dydis2];
    for (int i = 0; i < dydis2; i++) {
        cout << "Ivesk " << i + 1 << " elementa:" << endl;
    }
    */


    return 0;
}
