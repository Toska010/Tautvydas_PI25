#include <iostream>
#include <string>

using namespace std;

int funkcijuKiekis = 5;

struct sarasas {
    int info;
    sarasas *kitas;
};
sarasas *pradzia, *pabaiga, *elem;
bool arYraMasyvas = false;

void masyvoPabaigon(int elementas) {
    sarasas *el = new sarasas();
    el->info = elementas;
    el->kitas = nullptr;
    pabaiga -> kitas = el;
    pabaiga = el;
}

int vartotojasLauzo(string tikrinsim) {
    int tinka = stoi(tikrinsim);
    for (int i = 0; i <= funkcijuKiekis; i++) {
        if (i == tinka) {
            return i;
        }
    }
    return funkcijuKiekis;
}

void masyvoSukurimas() {
    pradzia = NULL;
    pabaiga = NULL;
    elem = new sarasas();
    elem -> kitas = NULL;
    pradzia = pabaiga = elem;
}

void masyvas() {
    if (arYraMasyvas == false) {
        masyvoSukurimas();
        arYraMasyvas = true;
    }
    int elementas, busElemntu;
    cout << "Kiek norite ivesti elementu?" << endl;
    cin >> busElemntu;
    for (int i = 0; i < busElemntu; i++) {
        cout << "Iveskite " << i+1 << ": ";
        cin >> elementas;
        masyvoPabaigon(elementas);
    }
}

void spausdinti() {
    sarasas *pr = pradzia;
    while (pr != nullptr) {
        cout << pr -> info << endl;
        pr = pr -> kitas;
    }
}

void pasirinkimuMeniu() {
    bool ratas = true;
    string pasirinkimas;
    while (ratas) {
        cout << "Pasirinkite funkcija:\n0: Nutraukti programa\n1: Sukurti, papildyti masyva\n2: Suskaiciuoti teigiamu elementu suma\n3: Sandauga tarp didziausio ir maziausio elementu\n4: Spausdinti masyva" << endl;
        cin >> pasirinkimas;
        int toliau = vartotojasLauzo(pasirinkimas);
        switch (toliau) {
            case 0: {ratas = false; break;}
            case 1: {masyvas(); break;}
            //case 2: {suma; break}
            //case 3: {sandauga; break}
            case 4: {spausdinti(); break;}
            case 5: {cout << "Netinkamas funkcijos pasirinkimas!" << endl; break;}
        }
    }
}



int main() {
    pasirinkimuMeniu();
    return 0;
}
