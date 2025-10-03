#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
float KAINA;
int Ratas;
int Pasirinkimas;
string PATIEKALAS;

class meniuList {
public:
    string meniuItem;
    float meniuPrice;
    void getData(string Patiekalas, float Islaidos) {
        meniuItem = Patiekalas;
        meniuPrice = Islaidos;
        Ratas++;
    }

    void showMeniu() {
        cout << fixed << setprecision(2);
        cout << left << setw(50) << meniuItem << right << meniuPrice << "€" << endl;
    }
};

meniuList meniu[124];

void MasyvaiIsFailu() {
    Ratas = 0;
    ifstream KainuFailas;
    ifstream PatiekaluFailas;
    KainuFailas.open("Kainos.txt");
    PatiekaluFailas.open("Patiekalai.txt");
    while(!KainuFailas.eof() && !PatiekaluFailas.eof()) {
        KainuFailas >> KAINA;
        getline(PatiekaluFailas, PATIEKALAS);
        meniu[Ratas].getData(PATIEKALAS, KAINA);
    }
    KainuFailas.close();
    PatiekaluFailas.close();

}

void MeniuPapildymas(string Pavadinimas, float Kaina) {
    ofstream KainuFailas;
    ofstream PatiekaluFailas;
    KainuFailas.open("Kainos.txt", ios::app);
    PatiekaluFailas.open("Patiekalai.txt", ios::app);
    KainuFailas << endl << Kaina;
    PatiekaluFailas << endl << Pavadinimas;
    PatiekaluFailas.close();
    KainuFailas.close();
}

void IssauktiMeniuParodyma() {
    MasyvaiIsFailu();
    for (int i = 0; i < Ratas; i++) {
            meniu[i].showMeniu();
        }
    cout << endl;
}

void Uzsakymas() {

    ofstream Cekis;
    Cekis.open("Cekis.txt");
    Cekis << "";
    Cekis.close();

    int Ivestis;
    int SkirtinguPrekiu = 0;
    float BendraSuma = 0;
    IssauktiMeniuParodyma();
    float KiekisUzsakymui[Ratas];

    for (int i = 0; i < Ratas; i++) {
        cout << "Iveskitie kiek noretumete: " << meniu[i].meniuItem << endl;
        cin >> Ivestis;
        KiekisUzsakymui[i] = Ivestis;
        cout << int(KiekisUzsakymui[i]) << endl;
    }

    for (int i = 0; i < Ratas; i++) {
        if (KiekisUzsakymui[i] > 0) {
            cout << int(KiekisUzsakymui[i]) << ".2" << endl;
            SkirtinguPrekiu++;
        }
    }

    float Sumos[SkirtinguPrekiu];
    for (int i = 0; i < Ratas; i++) {
        cout << int(KiekisUzsakymui[i]) << ".3" << endl;
        if (KiekisUzsakymui[i] >= 1) {
            Sumos[i] = meniu[i].meniuPrice * KiekisUzsakymui[i];
            BendraSuma = BendraSuma + Sumos[i];
        }
        cout << int(KiekisUzsakymui[i]) << ".4" << endl;
    }
    ofstream Cekis1;
    Cekis1.open("Cekis.txt", ios::app);

    for (int i = 0; i < Ratas; i++) {
        cout << KiekisUzsakymui[i] << ".5" << endl;
        if (KiekisUzsakymui[i] >= 1) {
            Cekis1 << "Kiekis: " << int(KiekisUzsakymui[i]) << " " << left << setw(50) << meniu[i].meniuItem << fixed << setprecision(2) << Sumos[i] << "€" << endl;
            cout << "Kiekis: " << int(KiekisUzsakymui[i]) << " " << left << setw(50) << meniu[i].meniuItem << fixed << setprecision(2) << Sumos[i] << "€" << endl;
            cout << Ratas << endl;
        }
    }

    Cekis1 <<  "Viso: " << right << fixed << setprecision(2) << setw(59) << BendraSuma << "€";

    Cekis1.close();
}

int main() {
    string IvestasProduktas;
    float IvestaKaina;
    IssauktiMeniuParodyma();

    while(Pasirinkimas != 3) {
        cout << "Pasirink funkcija:\n1: Ivesti produkta\n2: Uzsisakyti\n3: Iseiti" << endl;
        cin >> Pasirinkimas;
        switch (Pasirinkimas) {
            case 1: {
                cout << "Ivesk produkto pavadinima" << endl;
                cin >> IvestasProduktas;
                cout << "Ivesk produkto kaina" << endl;
                cin >> IvestaKaina;
                MeniuPapildymas(IvestasProduktas, IvestaKaina);
                break;
            }
            case 2: {
                Uzsakymas();
                break;
            }
            case 3: break;
        }
    }
    IssauktiMeniuParodyma();

    return 0;
}