#include <iostream>

using namespace std;
bool programosVeikimas = true;
bool yraStekas = false;
bool salintiPenkis = false;
bool yraVienkryptis = false;
int elementuSteke = 0;
int elemenuSarase = 0;
bool boolState = false;

struct stekas {
    int skaicius;
    stekas* kitas;
};
stekas *elem, *pradzia, *pabaiga, *ankstesnis;
struct sarasasV {
    int skaicius;
    sarasasV* kitas;
};
sarasasV *elemV, *pradziaV, *pabaigaV, *ankstesnisV;
void skaiciuotiElementus() {
    int kiek = 0;
    if (pradzia == nullptr) {
        yraStekas = false;
        elementuSteke = 0;
    }
    else {
        yraStekas = true;
    }
    if (pradziaV != nullptr) {
        yraVienkryptis = true;
    }
    else {
        yraVienkryptis = false;
        elemenuSarase = 0;
    }
    if (yraStekas == true) {
        elem = pradzia;
        kiek = 1;
        while (elem  != pabaiga) {
            kiek = kiek + 1;
            elem = elem->kitas;
        }
    }
    elementuSteke = kiek;
    kiek = 0;
    if (yraVienkryptis == true) {
        elemV = pradziaV;
        kiek = 1;
        while (elemV != pabaigaV) {
            kiek = kiek + 1;
            elemV = elemV->kitas;
        }
    }
    elemenuSarase = kiek;
    if (elementuSteke > 4) {
        salintiPenkis = true;
    }
    else {
        salintiPenkis = false;
    }
    if (elemenuSarase > 0) {
        yraVienkryptis = true;
    }
    else {
        yraVienkryptis = false;
    }
}
void stekoIvestis() {
    int kiekIves;
    int koksSk;
    cout << "Kiek elementu norite ivesti?" << endl;
    cin >> kiekIves;
    for (int i = 0; i < kiekIves; i++) {
        cout << "Iveskite " << i + 1 << " elementa:" << endl;
        cin >> koksSk;
        if (yraStekas == false) {
            elem = new stekas;
            pradzia = pabaiga = ankstesnis = elem;
            elem -> skaicius = koksSk;
            elem -> kitas = nullptr;
            skaiciuotiElementus();
        }
        else {
            elem = new stekas;
            elem -> skaicius = koksSk;
            ankstesnis -> kitas = elem;
            pabaiga = elem;
            ankstesnis = pabaiga;
            skaiciuotiElementus();
        }
    }
    skaiciuotiElementus();
}
void stekoSalinimas() {}
void penkiuSalinimas() {
    for (int i = 1; i <= 5; i++) {
        if (yraVienkryptis == false) {
            elemV = new sarasasV;
            pradziaV = elemV;
            pabaigaV = elemV;
            elem = pradzia;
            elemV -> skaicius = elem -> skaicius;
            elemV -> kitas = pradziaV;
            pradzia = pradzia -> kitas;
            delete elem;
            elem = nullptr;
            yraVienkryptis = true;
        }
        else {
            elemV = new sarasasV;
            elem = pradzia;
            elemV -> skaicius = elem -> skaicius;
            pradzia = pradzia -> kitas;
            delete elem;
            elem = nullptr;
            pabaigaV -> kitas = elemV;
            pabaigaV = elemV;
            elemV -> kitas = pradziaV;
        }
    }
    if (elementuSteke == 5) {
        pradzia = nullptr;
        pabaiga = nullptr;
        elem = nullptr;
    }
    skaiciuotiElementus();
    if (boolState == true) {
        cout << "Salinimas baigtas, skaiciuojami elementai" << endl;
        cout << "\nprogramosVeikimas: " << programosVeikimas << "\nyraStekas: " << yraStekas << "\nsalintiPenkis: " << salintiPenkis << "\nyraVienkryptis: " << yraVienkryptis << "\nboolState: " << boolState << endl;
    }
}
void sarasoPrintas() {
    elemV = pradziaV;
    int kelintas = 1;
    while (elemV != pabaigaV) {
        cout << kelintas << ": " << elemV -> skaicius << endl;
        kelintas++;
        elemV = elemV -> kitas;
    }
    cout << kelintas << ": " << elemV -> skaicius << endl;
}
void sukeistiElementus() {
    skaiciuotiElementus();
    elemV = pradziaV;
    for (int i = 0; i < elemenuSarase; i++) {
        if (elemV -> skaicius > 0) {
            cout << "_____ Pries keitima _____" << endl;
            ankstesnisV = elemV;
            sarasoPrintas();
            elemV = ankstesnisV;
            ankstesnisV = new sarasasV;
            ankstesnisV -> skaicius = elemV -> skaicius;
            elemV -> skaicius = pabaigaV -> skaicius;
            pabaigaV -> skaicius = ankstesnisV -> skaicius;
            delete ankstesnisV;
            ankstesnisV = nullptr;
            cout << "_______ Po keitimo ______" << endl;
            sarasoPrintas();
            cout << "_________________________" << endl;
            break;
        }
        else {
            if (i == elemenuSarase - 1) {
                cout << "Nera teigiamo elemento!" << endl;
                sarasoPrintas();
            }
        }
        elemV = elemV -> kitas;
    }
    skaiciuotiElementus();
}
void salintiSarasa() {
    skaiciuotiElementus();
    for (int i = 0; i < elemenuSarase; i++) {
        elemV = pradziaV;
        cout << i + 1 << ": " << elemV -> skaicius << endl;
        pradziaV = elemV -> kitas;
        delete elemV;
        elemV = nullptr;
    }
    pabaigaV = nullptr;
    pradziaV = nullptr;
    elemV = nullptr;
    yraVienkryptis = false;
    skaiciuotiElementus();
}
void opcijosAprasas() {
    cout << "Pasirinkite funkcija:\n"
            "0: Nutraukti programa\n"
            "1: Ivesti skaicius i steka\n";
    if (salintiPenkis == true) {
        cout << "2: Pasalinti 5 elementus is saraso perkeliant juos i ciklini vienkrypti sarasa\n";
    }
    if (yraVienkryptis == true) {
        cout << "3: Sukeisti cikliniame sarase pirma teigiama elementa su paskutiniu\n"//Dar reik atvaizduot pirmini ir sukeista
        "4: Pasalinti visus elementus is vienkrypcio saraso" << endl;
    }
    if (boolState == true) {
        cout << "\nprogramosVeikimas: " << programosVeikimas << "\nyraStekas: " << yraStekas << "\nsalintiPenkis: " << salintiPenkis << "\nyraVienkryptis: " << yraVienkryptis << "\nboolState: " << boolState << endl;
    }
}

void opcijuMeniiu() {
    int pasirinkta;
    while (programosVeikimas == true) {
        opcijosAprasas();
        cin >> pasirinkta;
        if (pasirinkta == 123) {
            if (boolState == false) {
                boolState = true;
            }
            else {
                boolState = false;
            }
        }
        else {
            switch (pasirinkta) {
                case 0: {
                    cout << "Programa nutraukta!" << endl;
                    programosVeikimas = false;
                    break;
                }
                case 1: {
                    stekoIvestis();
                    break;
                }
            }
            if (salintiPenkis == true) {
                switch (pasirinkta) {
                    case 2: {
                        penkiuSalinimas();
                        break;
                    }
                }
            }
            if (yraVienkryptis == true) {
                switch (pasirinkta) {
                    case 3: {
                        sukeistiElementus();
                        break;
                    }
                    case 4: {
                        salintiSarasa();
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    opcijuMeniiu();
}