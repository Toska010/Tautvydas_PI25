#include <iostream>
#include <fstream>
#include <iomanip>

const int MasyvuDydis = 124;
int Ratas;
int Plotis = 65;
int Pasirinkimas;
float Pvm;
float GalutineSuma;

using namespace std;

struct StrukturaMeniu {
    float Kainos;
    string Pavadinimai;
    int KiekisUzsakymui;
    float Suma;
}Meniu[MasyvuDydis];
void Failai_I_Masyvus() {
    Ratas = 0;
    ifstream KainuFailas;
    ifstream PatiekaluFailas;
    KainuFailas.open("Kainos.txt");
    PatiekaluFailas.open("Patiekalai.txt");
    while (!KainuFailas.eof() && !PatiekaluFailas.eof()) {
        KainuFailas >> Meniu[Ratas].Kainos;
        getline(PatiekaluFailas, Meniu[Ratas].Pavadinimai);
        Ratas++;
    }
    KainuFailas.close();
    PatiekaluFailas.close();
}
void Patiekalai_Bruksniai_Kainos(int Pradzia, int KartojimasIki, int Poslinkis) {
    char BuferisIlgiui[MasyvuDydis];
    for (int i = Pradzia; i < KartojimasIki; i++) {
        int SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", Meniu[i].Kainos);
        cout << Meniu[i].Pavadinimai << " ";
        int Linija = Meniu[i].Pavadinimai.length() + SumosIlgis + Poslinkis;
        for (int i = 0; i < Plotis - (Linija + 2); i++) {
            cout << "-";
        }
        cout << " " << fixed << setprecision(2) << Meniu[i].Kainos << endl;
    }
}
void PvmEilute() {


}
void MeniuAtvaizdavimas() {
    Failai_I_Masyvus();
    for (int i = 0; i < Plotis; i++) {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < (Plotis - 5) / 2; i++) {
        cout << " ";
    }
    cout <<  "MENIU" << endl;
    for (int i = 0; i < Plotis; i++) {
        cout << "-";
    }
    cout << endl << endl;
    Patiekalai_Bruksniai_Kainos(0, Ratas, 0);
    cout << endl;
}
void Uzsakymas() {
    Pvm = 0;
    GalutineSuma = 0;
    cout << "Noredami uzsisakyti pasirinkite patiekala irasydami numeri nurodyta pries ji ir iveskite kieki" << endl;
    cout << "0:  Iseiti" << endl;
    for (int i = 0; i < Ratas; i++) {
        cout << i + 1 << ":  ";
        Patiekalai_Bruksniai_Kainos(i, i+1, 3);
    }
    cout << Ratas + 1 << ":  Panaikinti uzsakyma" << endl;
    cout << Ratas + 2 << ": Priminti uzsakyma" << endl;
    int Kiekis;
    int Preke;
    while (true) {
        cin >> Preke;
        if (Preke > 0 && Preke <= Ratas) {
            cin >> Kiekis;
            if (Kiekis < 0) {
                cout << "Mes neperkam patiekalu!" << endl;
            }
            else if (Kiekis >= 0) {
                Meniu[Preke - 1].KiekisUzsakymui = Meniu[Preke - 1].KiekisUzsakymui + Kiekis;
                cout << Preke << ": " << Meniu[Preke - 1].Pavadinimai << " " << Meniu[Preke - 1].KiekisUzsakymui << " vnt" << endl;
            }
        }
        else if (Preke == 0) {
            cin.ignore(Plotis,'\n');
            for (int i = 0; i < Ratas; i++) {
                Meniu[i].Suma = float(Meniu[i].KiekisUzsakymui) * Meniu[i].Kainos;
                Pvm = Pvm + Meniu[i].Suma * 0.21;
                GalutineSuma = GalutineSuma + Meniu[i].Suma * 1.21;
            }
            break;
        }
        else if (Preke == Ratas + 1) {
            cin.ignore(Plotis,'\n');
            for (int i = 0; i < Ratas; i++) {
                Meniu[i].KiekisUzsakymui = 0;
            }

        }
        else if (Preke == Ratas + 2) {
            cin.ignore(Plotis,'\n');
            for (int i = 0; i < Ratas; i++) {
                cout << i + 1 << ": " << Meniu[i].KiekisUzsakymui << " "  << Meniu[i].Pavadinimai << endl;
            }
        }
        else {
            cout << "Tokio pasirinkimo nera!" << endl;
        }
    }
}
/**/
void Kvitas() {
    ofstream Cekis;
    Cekis.open("Kvitas.txt");
    Cekis << "";
    Cekis.close();
    Cekis.open("Kvitas.txt",ios::app);
    char BuferisIlgiui[MasyvuDydis];
    for (int i = 0; i < Ratas; i++) {
        if (Meniu[i].Suma > 0) {
            int SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", Meniu[i].Suma);
            int KiekioIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%d", Meniu[i].KiekisUzsakymui);
            int Tarpas = Meniu[i].Pavadinimai.length() + SumosIlgis + KiekioIlgis;
            cout << Meniu[i].KiekisUzsakymui << " " << Meniu[i].Pavadinimai << " ";
            Cekis << Meniu[i].KiekisUzsakymui << " " << Meniu[i].Pavadinimai << " ";
            for (int j = 0; j < Plotis - (3 + Tarpas); j++) {
                cout << "-";
                if (j+1 < Plotis - (4 + Tarpas)) {
                    Cekis << "_";
                }
            }
            cout << " " << fixed << setprecision(2) << Meniu[i].Suma << endl;
            Cekis << " " << fixed << setprecision(2) << Meniu[i].Suma << " €" << endl;
        }
    }
    int SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", Pvm);
    cout << "Pvm 21%: ";
    Cekis << "Pvm 21%: ";
    for (int i = 0; i < Plotis - (10 + SumosIlgis); i++) {
        cout << "-";
        if (i + 1 < Plotis - (11 + SumosIlgis)) {
            Cekis << "_";
        }
    }
    cout << fixed << setprecision(2) << " " << Pvm << endl;
    Cekis << fixed << setprecision(2) << " " << Pvm << " €" << endl;

    SumosIlgis = snprintf(BuferisIlgiui, sizeof(BuferisIlgiui), "%.2f", GalutineSuma);
    cout << "Viso: ";
    Cekis << "Viso: ";
    for (int i = 0; i < Plotis - (7 + SumosIlgis); i++) {
        cout << "-";
        if (i+1 < Plotis - (8 + SumosIlgis)) {
            Cekis << "_";
        }
    }
    cout << fixed << setprecision(2) << " " << GalutineSuma << endl << endl;
    Cekis << fixed << setprecision(2) << " " << GalutineSuma << " €" << endl;
    Cekis.close();
}


int main() {
    Failai_I_Masyvus();
    while (true) {
        cout << "Pasirinkite funkcija:\n1: MENIU\t2: PATEIKTI UZSAKYMA\t3: KVITAS\t4: ISEITI" << endl;
        cin >> Pasirinkimas;
        switch (Pasirinkimas) {
            case 1: {
                MeniuAtvaizdavimas();
                break;
            }
            case 2: {
                Uzsakymas();
                break;
            }
            case 3: {
                Kvitas();
                break;
            }
            case 4: {
                break;
            }
        }
        if (Pasirinkimas == 4) {
            break;
        }
    }
    return 0;
}
