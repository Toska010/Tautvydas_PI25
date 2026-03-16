#include <iostream>
using namespace std;
bool yraMasyvas = false;

struct sarasas {
    int skaicius;
    sarasas *kitas;
};

sarasas *pradzia = nullptr, *pabaiga = nullptr, *elem = nullptr, *el, *pr;

void masyvoSkaiciai(int koks) {
    el = new sarasas;
    el->skaicius = koks;
    el->kitas = nullptr;

    if (!pradzia) pradzia = pabaiga = el;
    else {
        pabaiga->kitas = el;
        pabaiga = el;
    }
}

void spausdintiMasyva() {
    pr = pradzia;
    while (pr != nullptr) {
        cout << pr->skaicius << " ";
        pr = pr->kitas;
    }
    cout << endl;
}

void sukurtiMasyva() {
    int kiek, reiksme;
    cout << "Iveskite kiek elementu bus: ";
    cin >> kiek;

    for (int i = 0; i < kiek; i++) {
        cout << "Iveskite " << i+1 << " elementa: ";
        cin >> reiksme;

        if (!yraMasyvas) {
            pradzia = pabaiga = nullptr;
            yraMasyvas = true;
        }
        masyvoSkaiciai(reiksme);
    }
}

void sandaugaMasyve() {
    if (!yraMasyvas) {
        cout << "Masyvas tuscias!" << endl;
        return;
    }

    int sandauga = 1;
    bool rastas = false;

    pr = pradzia;
    while (pr != nullptr) {
        if (pr->skaicius < 0) {
            sandauga *= pr->skaicius;
            rastas = true;
        }
        pr = pr->kitas;
    }

    if (!rastas) cout << "Nera neigiamu elementu!" << endl;
    else cout << "Neigiamu elementu sandauga = " << sandauga << endl;
}

int sumaMasyve() {
    if (!yraMasyvas) return 0;

    int didSk = pradzia->skaicius;
    pr = pradzia;

    while (pr != nullptr) {
        if (pr->skaicius > didSk) didSk = pr->skaicius;
        pr = pr->kitas;
    }

    int suma = 0;
    pr = pradzia;
    while (pr != nullptr && pr->skaicius != didSk) {
        if (pr->skaicius > 0)
            suma += pr->skaicius;
        pr = pr->kitas;
    }
    return suma;
}

void apverstiMasyva() {
    if (!yraMasyvas) return;
    sarasas *pries = nullptr, *dabar = pradzia, *kitas = nullptr;
    pabaiga = pradzia;
    while (dabar != nullptr) {
        kitas = dabar->kitas;
        dabar->kitas = pries;
        pries = dabar;
        dabar = kitas;
    }
    pradzia = pries;
}

void pasirinkimuMeniu() {
    bool veikimas = true;
    int pasirinkta;
    while (veikimas) {
        cout << "Pasirinkite funkcija:\n"
                "0: Nutraukti programa\n"
                "1: Ivesti skaicius i masyva\n"
                "2: Teigiamu suma iki pirmo max\n"
                "3: Neigiamu elementu sandauga\n"
                "4: Spausdinti masyva\n"
                "5: Apversti masyva\n";
        cin >> pasirinkta;
        switch (pasirinkta) {
            case 0: {
                veikimas = false;
                cout << "Programa nutraukiama!" << endl;
                break;
            }
            case 1: {
                sukurtiMasyva();
                break;
            }
            case 2: {
                cout << "Suma: " << sumaMasyve() << endl;
                break;
            }
            case 3: {
                sandaugaMasyve();
                break;
            }
            case 4: {
                spausdintiMasyva();
                break;
            }
            case 5: {
                apverstiMasyva();
                break;
            }
            default: {
                cout << "Netinkamai pasirinkta funkcija!" << endl;
                break;
            }
        }
    }
}

int main() {
    pasirinkimuMeniu();
    return 0;
}