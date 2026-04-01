#include <iostream>

using namespace std;
bool yraStartas = false;
bool yraSarasasDvik = false;
bool yraSarasasV = false;
bool pasirinktasElementas = false;
bool trfalse = false;
const int atsitiktiniuSkKiekis = 5;
int elementuKiekis;
struct sarasasDvik {
    int id;
    int skaicius;
    sarasasDvik *kitas;
    sarasasDvik *ankstesnis;
};
sarasasDvik *pradziaD = nullptr, *pabaigaD = nullptr, *elemD = nullptr, *zymeklis, *zymPrad, *zymPabaig, *trintukas, *iterpimas, *didziausias;
struct sarasasV {
    int skaicius;
    sarasasV *kitas;
};
sarasasV *pradziaV, *pabaigaV, *elemV;
int atsitiktiniaiSkaiciai() {
    int atsitiktinisSk = rand() % 100;
    int arBusNeigiamas = rand() % 100;
    if (arBusNeigiamas > 49) {
        atsitiktinisSk = atsitiktinisSk * -1;
    }
    return atsitiktinisSk;
}
void rastiDidziausia() {
    cout << "Didziausias skaicius: ";
    elemD = pradziaD;
    didziausias = pradziaD;
    while (elemD != pabaigaD) {
        if (elemD -> skaicius > didziausias -> skaicius) {
            didziausias = elemD;
        }
        elemD = elemD -> kitas;
    }
    if (elemD -> skaicius > didziausias -> skaicius) {
        didziausias = elemD;
    }
    cout << didziausias -> skaicius << endl;
}
void sujungtiNuja(int pasirinktasElelmentas, int piresPo) {
    switch (pasirinktasElelmentas) {
        case 0: {
            if (pradziaD == nullptr && pabaigaD == nullptr) {
                pradziaD = nullptr; pabaigaD = nullptr; elemD = nullptr;
                pradziaD = zymPrad;
                pabaigaD = zymPabaig;
                pabaigaD -> kitas = pradziaD;
                pradziaD -> ankstesnis = pabaigaD;
            }
            else {
                switch (piresPo) {
                    case 0: {
                        pabaigaD -> kitas = zymPrad;
                        zymPrad -> ankstesnis = pabaigaD;
                        zymPabaig -> kitas = pradziaD;
                        pradziaD -> ankstesnis = zymPabaig;
                        pabaigaD = pradziaD -> ankstesnis;
                        zymPabaig = nullptr;
                        zymPrad = nullptr;
                        break;
                    }
                    case 1: {
                        pabaigaD -> kitas = zymPrad;
                        zymPrad -> ankstesnis = pabaigaD;
                        zymPabaig -> kitas = pradziaD;
                        pradziaD -> ankstesnis = zymPabaig;
                        pradziaD = pabaigaD -> kitas;
                        zymPabaig = nullptr;
                        zymPrad = nullptr;
                        break;
                    }
                }
            }
            break;
        }
        case 1: {
            if (pradziaD == nullptr && pabaigaD == nullptr) {
                pradziaD = nullptr; pabaigaD = nullptr; elemD = nullptr;
                pradziaD = zymPrad;
                pabaigaD = zymPabaig;
                pabaigaD -> kitas = pradziaD;
                pradziaD -> ankstesnis = pabaigaD;
            }
            else {
                switch (piresPo) {
                    case 0: {
                        zymPabaig -> kitas = iterpimas -> kitas;
                        iterpimas -> kitas -> ankstesnis = zymPabaig;
                        iterpimas -> kitas = zymPrad;
                        zymPrad -> ankstesnis = iterpimas;
                        zymPabaig = nullptr;
                        zymPrad = nullptr;
                        break;
                    }
                    case 1: {
                        zymPrad -> ankstesnis = iterpimas -> ankstesnis;
                        iterpimas -> ankstesnis -> kitas = zymPrad;
                        zymPabaig -> kitas = iterpimas;
                        iterpimas -> ankstesnis = zymPabaig;
                        zymPabaig = nullptr;
                        zymPrad = nullptr;
                        break;
                    }
                }
            }
            break;
        }
    }
}
void sutvarkytID() {
    elemD = pradziaD;
    elemD -> id = 1;
    while (elemD != pabaigaD) {
        elemD -> kitas -> id = elemD -> id + 1;
        elemD = elemD -> kitas;
    }
    elementuKiekis = elemD -> id;
}
void skaicuIrasymas(int arTiesiai) {
        if (yraStartas == false) {
        zymeklis = new sarasasDvik;
        zymeklis -> kitas = nullptr;
        zymeklis -> ankstesnis = nullptr;
        zymPrad = zymPabaig = zymeklis;
        yraStartas = true;
        }
        else {
            zymeklis = new sarasasDvik;
            if (arTiesiai == 1) {
                zymPabaig -> kitas = zymeklis;
                zymeklis -> ankstesnis = zymPabaig;
            zymeklis -> kitas = nullptr;
            zymPabaig = zymeklis;
        }
        else if (arTiesiai == 2) {
            zymPrad -> ankstesnis = zymeklis;
            zymeklis -> kitas = zymPrad;
            zymeklis -> ankstesnis = nullptr;
            zymPrad = zymeklis;
        }
    }
}
void ivestiSkaicius(int arTiesiai, int arAtsitiktinis, int pasirinktasElementas,int priesPo) {
        if (arAtsitiktinis == 1) {
            for (int i = 0; i < atsitiktiniuSkKiekis; i++) {
                skaicuIrasymas(arTiesiai);
                zymeklis -> skaicius = atsitiktiniaiSkaiciai();
            }
            if (yraSarasasDvik == false) {
                pradziaD = nullptr;
                pabaigaD = nullptr;
                elemD = nullptr;
            }
            sujungtiNuja(pasirinktasElementas,priesPo);
            yraSarasasDvik = true;
        }
    if (arAtsitiktinis == 0) {
        cout << "Kiek elementu norite ivesti?" << endl;
        int kiekisElem;
        int ivestasElem;
        cin >> kiekisElem;
        for (int i = 0; i < kiekisElem; i++) {
            cout << "Ivesk " << i + 1 << " elementa:" << endl;
            cin >> ivestasElem;
            skaicuIrasymas(arTiesiai);
            zymeklis -> skaicius = ivestasElem;
            yraSarasasDvik = true;
        }
        if (yraSarasasDvik == false) {
            pradziaD = nullptr;
            pabaigaD = nullptr;
            elemD = nullptr;
        }
        sujungtiNuja(pasirinktasElementas,priesPo);
    }
    yraStartas = false;
}
void pasirinkimasOpciju() {
    cout << "Pasirinkite funkcija:\n"
            "0: Nutraukti programa\n"
            "1: Ivesti skaicius i saraso gala\n"
            "2: Ivesti skaicius i saraso prieki (apverstas)\n"
            "3: Ivesti " << atsitiktiniuSkKiekis << " atsitiktinius skaicius i saraso gala\n"
            "4: Ivesti " << atsitiktiniuSkKiekis << " atsitiktinius skaicius i saraso prieki (apverstas)\n";
    if (yraSarasasDvik == true) {
        cout << "5: rasti didziausia\n"
                "6: pasirinkti elementa\n"
                "7: perkelti nelyginius skaicius i steka\n"
                "8: spausdinti sarasa nuo pradzios\n"
                "9: spausdinti sarasa nuo pabaigos\n";
    }
    if (yraSarasasV == true) {
        cout << "10: spausdinti ir naikinti steko elementus\n";
    }
    if (pasirinktasElementas ==  true) {
        cout << "11: Ivesti skaicius uz elemento\n"
                "12: Ivesti skaicius pries elementa (apverstas)\n"
                "13: Ivesti " << atsitiktiniuSkKiekis << " atsitiktinius skaicius uz elemento\n"
                "14: Ivesti " << atsitiktiniuSkKiekis << " atsitiktinius skaicius pries elementa (apverstas)\n";
    }
    if (trfalse == true) {
        cout << "Stratas: " << yraStartas << "\nSarasasD: " << yraSarasasDvik << "\nSarasasV: " << yraSarasasV << "\nPasirinktas elementas: " << pasirinktasElementas << endl;
    }
}
void ieskomNelyginio() {
    if (elemD -> skaicius % 2 != 0) {
        if (iterpimas == elemD) {iterpimas = nullptr; pasirinktasElementas = false;}
            if (yraSarasasV == false) {
                elemV = new sarasasV;
                pradziaV = pabaigaV = elemV;
                elemV -> skaicius = elemD -> skaicius;
                elemV -> kitas = nullptr;
                if (elemD == pabaigaD) {
                    if (elemD == pabaigaD && elemD == pradziaD){pradziaD = nullptr; pabaigaD = nullptr; yraSarasasDvik = false;}
                    pabaigaD = elemD -> ankstesnis;
                }
                else if (elemD == pradziaD) {
                    if (elemD == pabaigaD && elemD == pradziaD){pradziaD = nullptr; pabaigaD = nullptr; yraSarasasDvik = false;}
                    pradziaD = elemD -> kitas;
                }
                elemD -> ankstesnis -> kitas = elemD -> kitas;
                elemD -> kitas -> ankstesnis = elemD -> ankstesnis;
                trintukas = elemD;
                elemD = elemD -> kitas;
                delete trintukas;
                yraSarasasV = true;
            }
            else {
                elemV = new sarasasV;
                elemV -> skaicius = elemD -> skaicius;
                pabaigaV -> kitas = elemV;
                pabaigaV = elemV;
                elemV -> kitas = nullptr;
                if (pabaigaD == elemD) {
                    if (elemD == pabaigaD && elemD == pradziaD){pradziaD = nullptr; pabaigaD = nullptr; yraSarasasDvik = false;}
                    pabaigaD = elemD -> ankstesnis;
                }
                if (pradziaD == elemD) {
                    if (elemD == pabaigaD && elemD == pradziaD){pradziaD = nullptr; pabaigaD = nullptr; yraSarasasDvik = false;}
                    pradziaD = elemD -> kitas;
                }
                elemD -> ankstesnis -> kitas = elemD -> kitas;
                elemD -> kitas -> ankstesnis = elemD -> ankstesnis;
                trintukas = elemD;
                elemD = elemD -> kitas;
                delete trintukas;
            }
        }
        else {
            elemD = elemD -> kitas;
        }
    if(pabaigaD == nullptr && pradziaD == nullptr){elemD = nullptr;}
}
void spausdintiSarasa(int kryptis) {
    switch (kryptis) {
        case 1: {
            for (elemD = pradziaD; elemD != pabaigaD; elemD = elemD -> kitas) {
                cout << elemD -> id << ": " <<  elemD -> skaicius << endl;
            }
            if (elemD == pabaigaD) {cout << elemD -> id << ": " <<  elemD -> skaicius << endl;}
            break;
        }
        case 2: {
            for (elemD = pabaigaD; elemD != pradziaD; elemD = elemD -> ankstesnis) {
                cout << elemD -> id << ": " <<  elemD -> skaicius << endl;
            }
            if (elemD == pradziaD) {cout << elemD -> id << ": " <<  elemD -> skaicius << endl;}
            break;
        }
    }
}
void pasirinktiElementa() {
    spausdintiSarasa(1);
    cout << "Pasirinkite elementa ivesdami jo id numeri:" << endl;
    int norimas;
    cin >> norimas;
    for (elemD = pradziaD; elemD -> id != norimas; elemD = elemD -> kitas) {
    }
    iterpimas = elemD;
    pasirinktasElementas = true;
}
void perkeltiNelyginius() {
    elemD = pradziaD;
    while (elemD -> id < elementuKiekis) {
        ieskomNelyginio();
    }
    ieskomNelyginio();
}
void spausdintiSteka() {
    elemV = pradziaV;
    while (elemV != nullptr) {
        cout << elemV -> skaicius << endl;
        if (elemV == pabaigaV) {
            delete pabaigaV;
            pabaigaV = nullptr;
            pradziaV = nullptr;
            elemV = nullptr;
            yraSarasasV = false;
        }
        else {
            elemV = elemV -> kitas;
            delete pradziaV;
            pradziaV = nullptr;
            pradziaV = elemV;
        }
    }
}
void opcijuMeniu() {
    bool varom = true;
    while (varom == true) {
        int pasirinkta;
        pasirinkimasOpciju();
        cin >> pasirinkta;
        if (pasirinkta == 555){if (trfalse == true){trfalse = false;} else {trfalse = true;}}
        else if (pasirinkta >= 0 && pasirinkta <= 4) {
            switch (pasirinkta) {
                case 0: {cout << "Programa nutraukta!" << endl; varom = false; break;}
                case 1: {ivestiSkaicius(pasirinkta, 0,0,0); break;}
                case 2: {ivestiSkaicius(pasirinkta, 0,0,1); break;}
                case 3: {ivestiSkaicius(pasirinkta-2, 1,0,0); break;}
                case 4: {ivestiSkaicius(pasirinkta-2, 1,0,1); break;}
            }
        }
        else if (pasirinkta >= 5 && pasirinkta <= 9) {
            if (yraSarasasDvik == true) {
                switch (pasirinkta) {
                    case 5: {rastiDidziausia(); break;}
                    case 6: {pasirinktiElementa(); break;}
                    case 7: {perkeltiNelyginius(); break;}
                    case 8: {spausdintiSarasa(pasirinkta-6); break;}
                    case 9: {spausdintiSarasa(pasirinkta-6); break;}
                }
            }
        }
        else if (pasirinkta == 10) {
            if (yraSarasasV == true) {
                switch (pasirinkta) {
                    case 10: {spausdintiSteka(); break;
                    }
                }
            }
        }
        else if (pasirinkta >= 11 && pasirinkta <= 14) {
            if (pasirinktasElementas == true) {
                switch (pasirinkta) {
                    case 11: {ivestiSkaicius(pasirinkta-9,0,1,0); break;}
                    case 12: {ivestiSkaicius(pasirinkta-9,0,1,1); break;}
                    case 13: {ivestiSkaicius(pasirinkta-11,1,1,0); break;}
                    case 14: {ivestiSkaicius(pasirinkta-11,1,1,1); break;}
                }
            }
        }
        else {
            cout << "Netinkamai pasirinkta funkcija!" << endl;
        }
        if (yraSarasasDvik == true) {
            sutvarkytID();
        }
    }
}
int main() {
    opcijuMeniu();
}
