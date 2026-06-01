#include <iostream>
using namespace std;
bool yraMasyvas = false;
struct sarasas {
    int skaicius;
    sarasas *kitas;
};
sarasas *pradzia = nullptr, *pabaiga = nullptr, *elem = nullptr, *trintukas = nullptr;
struct medis {
    int skaicius;
    int balansas;
    medis *kaire;
    medis *desine;
};
medis *virsus = nullptr, *el = nullptr;
medis* naujas_elementasMedzio(int perkeltas) {
    el = new medis;
    el -> balansas = 0;
    el -> skaicius = perkeltas;
    el -> kaire = nullptr;
    el -> desine = nullptr;
    return el;
}//DONE
int aukstis (medis* virsus) {
    if (virsus == nullptr) {
        return 0;
    }
    else {
        int kaire = aukstis(virsus -> kaire);
        int desine = aukstis(virsus -> desine);
        if (kaire > desine) {
            return 1 + kaire;
        }
        else {
            return 1 + desine;
        }
    }
}//DONE
int skaiciuotiBalansa(medis* virsus) {
    if (virsus == nullptr) {
        return 0;
    }
    else {
        return aukstis(virsus -> desine) - aukstis (virsus -> kaire);
    }
}//DONE
medis* desinen(medis* virsus) {
    if (virsus == NULL || virsus->kaire == NULL) {
        return virsus;
    }
    medis* elem = virsus->kaire;
    medis* elem2 = elem->desine;
    elem->desine = virsus;
    virsus->kaire = elem2;
    // skaiciujam svori saknu
    virsus->balansas = skaiciuotiBalansa(virsus);
    elem->balansas = skaiciuotiBalansa(elem);
    return elem;
}//DONE
medis* kairen(medis* virsus) {
    if (virsus == NULL || virsus->desine == NULL) {
        return virsus;
    }
    medis* elem = virsus->desine;
    medis* elem2 = elem->kaire;
    elem->kaire = virsus;
    virsus->desine = elem2;
    // skaiciujam svori saknu
    virsus->balansas = skaiciuotiBalansa(virsus);
    elem->balansas = skaiciuotiBalansa(elem);
    return elem;
}//DONE
medis* iterpti_iMedi(medis* virsus, int perduotas) {
    if (virsus == nullptr) {
        return naujas_elementasMedzio(perduotas);
    }
    if (perduotas < virsus -> skaicius) {
        virsus -> kaire = iterpti_iMedi(virsus -> kaire, perduotas);
    }
    else {
        virsus -> desine = iterpti_iMedi(virsus -> desine, perduotas);
    }
    virsus -> balansas = skaiciuotiBalansa(virsus);
    if (virsus -> balansas < -1) {
        if (perduotas < virsus -> kaire -> skaicius) {
            return desinen(virsus);
        }
    }
    else {
        virsus -> kaire = kairen(virsus -> kaire);
        return desinen(virsus);
    }
    if (virsus -> balansas > 1) {
        if (perduotas >= virsus -> desine -> skaicius) {
            return kairen(virsus);
        }
        else {
            virsus -> desine = desinen(virsus -> desine);
            return kairen(virsus);
        }
    }
    return virsus;
}//DONE
void spausdinti_Medi_Kartojimas(medis* virsus) {
    if (virsus == nullptr) return;
    spausdinti_Medi_Kartojimas(virsus->kaire);
    cout << virsus->skaicius << " ";
    spausdinti_Medi_Kartojimas(virsus->desine);
}//DONE
void spausdinti_Medi() {
    if (virsus == nullptr) {
        cout << "Medis tuscias." << endl;
        return;
    }
    spausdinti_Medi_Kartojimas(virsus);
    cout << endl;
}//DONE
void vienkryptis_Sarasas(int sk) {
    if (yraMasyvas == false) {
        elem = new sarasas();
        elem -> skaicius = sk;
        elem -> kitas = nullptr;
        pradzia = elem;
        pabaiga = elem;
        yraMasyvas = true;
    }
    else {
        elem = new sarasas();
        elem -> skaicius = sk;
        elem -> kitas = nullptr;
        pabaiga -> kitas = elem;
        pabaiga = elem;
    }
}//DONE
void iterpti_Elementa() {
    cout << "Iveskite skaiciu: " << endl;
    int skaicius;
    cin >> skaicius;
    vienkryptis_Sarasas(skaicius);
}//DONE
void pasalinti_Elementa() {

    cout << "Iveskite skaiciu salinimui: " << endl;
    int skaicius;
    cin >> skaicius;
    trintukas = pradzia;
    elem = nullptr;
    while (trintukas != nullptr && trintukas -> skaicius != skaicius) {
        elem = trintukas;
        trintukas = trintukas -> kitas;
    }
    if (trintukas == nullptr) {
        cout << "Skaicius " << skaicius << " nerastas!" << endl;
        return;
    }
    if (elem == nullptr) {
        pradzia = trintukas -> kitas;
    } else {
        elem -> kitas = trintukas -> kitas;
    }
    if (trintukas == pabaiga) {
        pabaiga = elem;
    }
    delete trintukas;
    if (pradzia == nullptr) {
        pabaiga = nullptr;
        yraMasyvas = false;
    }
    cout << "Skaicius " << skaicius << " pasalintas." << endl;
}//DONE
void spausdinti_Sarasa() {
    elem = pradzia;
    while (elem != nullptr) {
        cout << elem -> skaicius << endl;
        elem = elem -> kitas;
    }
}//DONE
void rasti_Skaiciu() {
    cout << "Iveskite ieskoma skaiciu: " << endl;
    int skaicius;
    cin >> skaicius;
    elem = pradzia;
    bool yraIeskomas = false;
    while (elem != nullptr) {
        if (elem -> skaicius == skaicius) {
            yraIeskomas = true;
            break;
        }
        elem = elem -> kitas;
    }
    if (yraIeskomas == true) {
        cout << "Skaicius " << skaicius << " yra sarase." <<  endl;
    }
    else {
        cout << "Skaicius " << skaicius << " nerastas!" <<  endl;
    }
}//DONE
void perkelti_Elementus() {
    elem = pradzia;
    while (elem != nullptr) {
        virsus = iterpti_iMedi(virsus, elem -> skaicius);
        trintukas = elem;
        elem = elem -> kitas;
        delete trintukas;
    }
    pradzia = nullptr;
    pabaiga = nullptr;
    elem = nullptr;
    trintukas = nullptr;
    yraMasyvas = false;
    cout << "Visi saraso elementai perkelti i AVL medi." << endl;

}//DONE
void aprasymas_meniu() {
    cout << "Pasirinkite funkcija:\n"
            "0: Nutraukti programa\n"
            "1: Iterpti skaiciu i sarasa\n"
            "2: Pasalinti skaiciu is saraso\n"
            "3: Spausdinti sarasa\n"
            "4: Rasti skaiciu sarase\n"
            "5: Perkelti saraso skaicius i AVL medi\n"
            "6: Spausdinti AVL medi" << endl;
}
void pasirinkta_meniu() {
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
                iterpti_Elementa();
                break;
            }
            case 2: {
                pasalinti_Elementa();
                break;
            }
            case 3: {
                spausdinti_Sarasa();
                break;
            }
            case 4: {
                rasti_Skaiciu();
                break;
            }
            case 5: {
                perkelti_Elementus();
                break;
            }
            case 6: {
                spausdinti_Medi();
                break;
            }
            default: {
                cout << "Tokio pasirinkimo " << pasirinkimas << " nera!" << endl;
                krize ++;
            }
        }
    }
}
int main() {
    pasirinkta_meniu();
}