#include <iostream>

using namespace std;
bool yraSarasasDvik = false;
bool yraSarasasV = false;

struct sarasasDvik {
    int skaicius;
    sarasasDvik *kitas;
    sarasasDvik *ankstesnis;
};
struct sarasasV {
    int skaicius;
    sarasasV *kitas;
};

sarasasDvik *pradziaD, *pabaigaD, *elemD, *elemPriesD;
sarasasV *pradziaV, *pabaigaV, *elemV;

void opcijuMeniu(int opcija) {
    while (true) {
        switch (opcija) {
        case 0: {false; break;}
        case 1: {perkeltiSkaicius; break;}
        case 2: {iterptiAtsitiktinius; break;}
        case 3: {naikinamasStekasAtvaizduojant; break;}
        default: {cout << "Tokios opcijos nera!" << endl; break;}
        }
    }

}

int atsitiktiniaiSkaiciai() {
    int atsitiktinisSk = rand() % 100;
    int arBusNeigiamas = rand() % 100;
    if (arBusNeigiamas > 49) {
        atsitiktinisSk = atsitiktinisSk * -1;
    }
    return atsitiktinisSk;
}

void vienkryptisSarasas(int koks) {
    elemV = new sarasasV;
    elemV -> skaicius = koks;
    elemV -> kitas = nullptr;
    pabaigaV -> kitas = elemV;
    pabaigaV = elemV;
}

void skaiciaiSarasuiDvik(int koks) {
    elemPriesD = elemD;
    elemD = new sarasasDvik;
    elemD -> skaicius = koks;
    elemD -> kitas = nullptr;
    elemD -> ankstesnis = elemPriesD;
    pabaigaD -> kitas = elemD;
    pabaigaD = elemD;
}

void iVienkryptiSarasa(int reiksme) {
    if (yraSarasasV == false) {
        pradziaV = NULL;
        pabaigaD = NULL;
        elemV = new sarasasV();
        elemV ->skaicius = reiksme;
        elemV ->kitas = NULL;
        pradziaV = pabaigaV = elemV;
        yraSarasasV = true;
    }
    else {
        vienkryptisSarasas(reiksme);
    }
}

void sukurtiSarasaDvik() {
    int kartoti;
    int reiksme;
    cout << "Iveskite kiek bus elementu:" << endl;
    cin >> kartoti;
    for (int i = 0; i < kartoti; i++) {
        if (yraSarasasDvik == false && i == 0) {
            pradziaD = NULL;
            pabaigaD = NULL;
            elemD = new sarasasDvik();
            cout << "Ivesk " << i + 1 << " elelmenta:" << endl;
            cin >> reiksme;
            elemD ->skaicius = reiksme;
            elemD ->kitas = NULL;
            elemD ->ankstesnis = NULL;
            pradziaD = pabaigaD = elemD;
            yraSarasasDvik = true;
        }
        else {
            cout << "Ivesk " << i + 1 << " elelmenta:" << endl;
            cin >> reiksme;
            skaiciaiSarasuiDvik(reiksme);
        }
    }
}

int main() {
    while (true) {
        cout << atsitiktiniaiSkaiciai() << endl;
    }
    return 0;
}
