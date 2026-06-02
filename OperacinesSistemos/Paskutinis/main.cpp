#include <iostream>

using namespace std;
bool yraMasyvas = false;

struct sarasas {
    int skaicius;
    sarasas *kitas;
};

sarasas *pradzia = nullptr, *pabaiga = nullptr, *elem = nullptr, *el, *pr;

struct naujasSarasas {
    int skaicius;
    naujasSarasas *kitas;
};
naujasSarasas *npradzia = nullptr, *npabaiga = nullptr, *nelem = nullptr, *nel, *npr;

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

int main() {
    return 0;
}
