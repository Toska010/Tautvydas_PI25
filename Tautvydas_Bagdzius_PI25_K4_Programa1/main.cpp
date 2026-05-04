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
}
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
}
int skaiciuotiBalansa(medis* virsus) {
    if (virsus == nullptr) {
        return 0;
    }
    else {
        return aukstis(virsus -> desine) - aukstis (virsus -> kaire);
    }
}
medis* iterpti_iMedi(medis* virsus, int perduotas) {
    if (virsus == nullptr) {
        return naujas_elementasMedzio(perduotas);
    }
    if (virsus -> kaire == nullptr) {
        virsus -> kaire = naujas_elementasMedzio(perduotas);
        return virsus;
    }
    if (virsus -> desine == nullptr) {
        virsus -> desine = naujas_elementasMedzio(perduotas);
        return virsus;
    }
    iterpti_iMedi(virsus -> kaire, perduotas);
    return virsus;
}
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
}
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
}
void spausdinti_Medi(){}
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
    bool yraIeskomas = false;
    while (trintukas != nullptr) {
        if (trintukas -> skaicius == skaicius) {
            yraIeskomas = true;
            if (trintukas == pradzia) {
                if (trintukas -> kitas != nullptr) {
                    pradzia = trintukas -> kitas;
                    delete trintukas;
                    break;
                }
                else {
                    delete trintukas;
                    pradzia = nullptr;
                    pabaiga = nullptr;
                    trintukas = nullptr;
                    elem = nullptr;
                    break;
                }
            }
            else {
                elem = pradzia;
                while (elem -> kitas != trintukas) {
                    elem = elem -> kitas;
                }
                if (trintukas -> kitas == nullptr) {
                    elem -> kitas = nullptr;
                }
                else {
                    elem -> kitas = trintukas -> kitas;
                }
            }
        }
        trintukas = trintukas -> kitas;
    }
    if (yraIeskomas == true) {
        cout << "Skaicius " << skaicius << " pasalintas." << endl;
    }
    else {
        cout << "Skaicius " << skaicius << " nerastas!" << endl;
    }
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
void perkelti_Elementus(){}


int main() {
    return 0;
}