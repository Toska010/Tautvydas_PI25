#include <iostream>
#include <string>
using namespace std;
int tarpuSkaicius = 0;
bool yraSarasas = false;
struct sarasas {
    char simbolis;
    sarasas* kitas;
    sarasas* ankstesnis;
};
sarasas *elem = nullptr, *naujas = nullptr, *pradzia = nullptr, *pabaiga = nullptr;
void sarasui(char zenklas) {
    if (yraSarasas == false) {
        elem = new sarasas;
        pradzia = elem;
        pabaiga = elem;
        elem -> ankstesnis = elem;
        elem -> kitas = elem;
        elem -> simbolis = zenklas;
        elem = nullptr;
        yraSarasas = true;
    }
    else {
        naujas = new sarasas;
        elem = pabaiga;
        elem -> kitas = naujas;
        naujas -> ankstesnis = elem;
        pradzia -> ankstesnis = naujas;
        naujas -> kitas = pradzia;
        pabaiga = naujas;
        elem = naujas;
        naujas = nullptr;
        elem -> simbolis = zenklas;
        elem = nullptr;
    }
}//DONE
void pries_Sarasui() {
    bool veikimas = true;
    cout << "Iveskite simbolius sarasui\n"
            "noredami nutraukti ivedima iveskite 0 (nuli)" << endl;
    string uzlaikymas;
    while (veikimas == true) {
        getline(cin, uzlaikymas);
        for (char zenklas : uzlaikymas) {
            if (zenklas == '0') {
                veikimas = false;
                break;
            }
            else {
                sarasui(zenklas);
            }
        }
    }
}//DONE
void saraso_spausdinimas() {
    elem = pradzia;
    do {
        cout << elem -> simbolis;
        elem = elem -> kitas;
    } while (elem != pradzia);
    elem = nullptr;
    cout << endl;
}//DONE
void skaiciuojam() {
    if (!yraSarasas) {
        return;
    }
    elem = pradzia;
    int dabartiniaiTarpai = 0;
    tarpuSkaicius = 0;
    do {
        if (elem -> simbolis == ' ') {
            dabartiniaiTarpai++;
            if (dabartiniaiTarpai > tarpuSkaicius) {
                tarpuSkaicius = dabartiniaiTarpai;
            }
        } else {
            dabartiniaiTarpai = 0;
        }
        elem = elem -> kitas;
    } while (elem != pradzia);

    cout << "Daugiausia is eiles tarpu: " << tarpuSkaicius << endl;

}
void aprasymas_meniu() {
    cout << "Pasirinkite funkcija:\n"
            "0: Nutraukti programa\n"
            "1: Iterpti simbolius\n"
            "2: Rasti daugiausiai pasikartojanciu is eiles tarpu kieki\n"
            "3: Spausdinti simboliu sarasa" << endl;
}//DONE
void opcijos_meniu() {
    bool veikiam = true;
    int pasirinkimas;
    int krize = 0;
    while (veikiam == true && krize < 5) {
        aprasymas_meniu();
        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case 0: {
                veikiam = false;
                break;
            }
            case 1: {
                pries_Sarasui();
                break;
            }
            case 2: {
                skaiciuojam();
                break;
            }
            case 3: {
                saraso_spausdinimas();
                break;
            }
            default: {
                cout << "Tokio pasirinkimo " << pasirinkimas << "nera!" << endl;
                krize++;
                break;
            }
        }
    }
}
int main()
{
    opcijos_meniu();
}
