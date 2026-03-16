#include <iostream>
using namespace std;
bool yraMasyvas = false;

struct sarasas {
    int skaicius;
    sarasas *kitas;
};

sarasas *pradzia, *pabaiga, *elem;

void masyvoSkaiciai(int koks) {
    sarasas *el = new sarasas;
    el->skaicius = koks;
    el->kitas = nullptr;
    pabaiga -> kitas = el;
    pabaiga = el;
}

void spausdintiMasyva() {
    sarasas *pr = pradzia;
    while (pr != nullptr) {
        cout << pr->skaicius << endl;
        pr = pr->kitas;
    }
}

void sukurtiMasyva() {
    int kartoti;
    int reiksme;
    cout << "Iveskite kiek bus elementu:" << endl;
    cin >> kartoti;
    for (int i = 0; i < kartoti; i++) {
        if (yraMasyvas == false && i == 0) {
            pradzia = NULL;
            pabaiga = NULL;
            elem = new sarasas();
            cout << "Ivesk " << i + 1 << " elelmenta:" << endl;
            cin >> reiksme;
            elem ->skaicius = reiksme;
            elem ->kitas = NULL;
            pradzia = pabaiga = elem;
            yraMasyvas = true;
        }
        else {
            cout << "Ivesk " << i + 1 << " elelmenta:" << endl;
            cin >> reiksme;
            masyvoSkaiciai(reiksme);
        }
    }
}

int sumaMasyve() {
    int suma = 0;
    sarasas *pr = pradzia;
    while (pr != nullptr) {
        if (pr->skaicius > 0) {
            suma += pr->skaicius;
        }
        pr = pr->kitas;
    }
    return suma;
}

void sandaugaMasyve() {
    int sandauga;
    sarasas *pr, *maz, *did;
    pr = pradzia;
    did = pradzia;
    maz = pradzia;
    int didziausias, maziausias, laikinas;
    didziausias = pr->skaicius;
    maziausias = pr->skaicius;
    while (pr != nullptr) {
        if (pr->skaicius < 0) {
            laikinas = pr->skaicius;
            laikinas = laikinas * -1;
        }
        else {
            laikinas = pr->skaicius;
        }
        if (laikinas < maziausias) {
            maz = pr;
            maziausias = laikinas;
        }
        if (laikinas > didziausias) {
            did = pr;
            didziausias = laikinas;
        }
        pr = pr->kitas;
    }
    pr = pradzia;
    sarasas *nuo, *iki;
    while (pr != nullptr) {
        if (pr == maz) {
            nuo = maz;
            iki = did;
            break;
        }
        if (pr == did) {
            nuo = did;
            iki = maz;
            break;
        }
        pr = pr->kitas;
    }
    if (nuo == iki) cout << "Sandauga negalima nes tarp maziausio: " << maz->skaicius << " ir didziausio: " << did->skaicius << " nera skaitmenu."<< endl;
    else if (nuo->kitas == iki) cout << "Sandauga negalima nes tarp maziausio: " << maz->skaicius << " ir didziausio: " << did->skaicius << " nera skaitmenu."<< endl;
    else if (nuo->kitas->kitas == iki) cout << "Sandauga negalima nes tarp maziausio: " << maz->skaicius << " ir didziausio: " << did->skaicius << " yra tik vienas skaitmuo: " << nuo->kitas->skaicius << endl;
    else if (nuo->kitas->kitas->kitas == iki) cout << "Sandauga = " << nuo->kitas->skaicius * nuo->kitas->kitas->skaicius << endl;
    else {
        pr = nuo -> kitas;
        sandauga = pr->skaicius;
        while (pr->kitas != iki) {
            pr = pr->kitas;
            sandauga = sandauga * pr -> skaicius;
        }
        cout << "Sandauga = " << sandauga << endl;
    }
}


void rusiuotiMasyva() {
    if (!yraMasyvas) return;
    sarasas *r, *rPabaiga, *did, *pr, *priesDid, *keliamas;
    r = nullptr;
    rPabaiga = nullptr;

    while (pradzia != nullptr) {
        did = pradzia;
        priesDid = nullptr;
        pr = pradzia;
        keliamas = nullptr;

        while (pr != nullptr) {
            if (pr->skaicius > did->skaicius) {
                did = pr;
                priesDid = keliamas;
            }
            keliamas = pr;
            pr = pr->kitas;
        }

        if (priesDid == nullptr) {
            pradzia = pradzia->kitas;
        } else {
            priesDid->kitas = did->kitas;
        }

        did->kitas = nullptr;
        if (r == nullptr) {
            r = did;
            rPabaiga = did;
        } else {
            rPabaiga->kitas = did;
            rPabaiga = did;
        }
    }

    pradzia = r;
    pabaiga = rPabaiga;
}

void pasirinkimuMeniu() {
    bool veikimas = true;
    int pasirinkta;
    while (veikimas) {
        cout << "Pasirinkite funkcija:\n"
                "0: Nutraukti programa\n"
                "1: Ivesti skaicius i masyva\n"
                "2: Teigiamu elementu sumos skaiciavimas\n"
                "3: Elementu tarp didziausio ir maziausio sandauga\n"
                "4: Spausdinti masyva\n"
                "5: Surusiuoti masyva mazejimo tvarka" << endl;
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
                cout << sumaMasyve() << endl;
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
                rusiuotiMasyva();
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