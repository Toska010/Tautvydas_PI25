#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int duomenuKiekis = 0;

struct meniuList {
    string pavadinimas;
    double kaina;
    int kiekis;
};

const int maxMasyvoDydis = 124;
const double pvm = 0.21;
string spvm = "(21%)";
const int sK = 3;  //Skaitmenu kiekis
const int tK = 45; //Teksto kiekis
const int pK = 2;  //Skaiciai po kablelio

void primintiUzsakyma(meniuList meniu[]) {
    for (int i = 0; i < duomenuKiekis; i++) {
        if (meniu[i].kiekis > 0) {
            cout << setw(sK) << meniu[i].kiekis << ": " << left << setw(tK) << meniu[i].pavadinimas << endl;
        }
    }
}

void getData(meniuList meniu[]) {
    ifstream infile;
    infile.open("Meniu.txt");
    duomenuKiekis = 0;
    while (!infile.eof() && duomenuKiekis < maxMasyvoDydis) {
        infile >> meniu[duomenuKiekis].pavadinimas >> meniu[duomenuKiekis].kaina;
        string laikinas = meniu[duomenuKiekis].pavadinimas;
        for (auto& c : laikinas) {
            if (c == '_') {
                c = ' ';
            }
        }
        meniu[duomenuKiekis].pavadinimas = laikinas;
        duomenuKiekis++;
    }
    infile.close();
}

void parodytiMeniu(meniuList meniu[]) {
    cout << "Meniu:" << endl << endl;
    for (int i = 0; i < duomenuKiekis; i++) {
        cout << setw(sK) << i + 1 << ": " << left << setw(tK) << meniu[i].pavadinimas << right << fixed << setprecision(pK) << meniu[i].kaina << " EUR" << endl;
    }
    cout << "Uzsakymui pateikti iveskite patiekalo numeri ir iveskite norima kieki\nUzsakymo uzbaigimui iveskite 0" << endl << endl;
    while (true) {
        int pasirinkimas;
        int kiekis = 0;
        cin >> pasirinkimas;
        if (pasirinkimas == 0) {
            primintiUzsakyma(meniu);
            break;
        }
        if (pasirinkimas < 0 || pasirinkimas > duomenuKiekis) {
            cout << "Netinkamas patiekalo pasirinkimas!" << endl;
        }
        if (pasirinkimas > 0 && pasirinkimas <= duomenuKiekis) {
            cin >> kiekis;
            if (kiekis < 0) {
                cout << "Netinkamas patiekalo kiekis!" << endl;
            }
            else {
                meniu[pasirinkimas - 1].kiekis = kiekis;
                cout << setw(sK) << meniu[pasirinkimas - 1].kiekis << ": " << left << setw(tK) << meniu[pasirinkimas - 1].pavadinimas << endl;
            }
        }
    }
}

void kvitas(meniuList meniu[]) {
    double suma = 0;
    ofstream outfile;
    outfile.open("Cekis.txt");
    outfile << "Sveiki atvyke i skestancio pirato restorana" << endl << endl;
    for (int i = 0; i < duomenuKiekis; i++) {
        if (meniu[i].kiekis > 0) {
            suma = suma + double(meniu[i].kiekis) * meniu[i].kaina;
            outfile << setw(sK) << meniu[i].kiekis << " " << left << setw(tK) << meniu[i].pavadinimas << right << fixed << setprecision(pK) << meniu[i].kaina * double(meniu[i].kiekis) << " EUR" << endl;
        }
    }
    outfile << endl << setprecision(pK) << "Mokesciai " << left << setw(tK - 6) << spvm << right << fixed << suma * pvm << " EUR" << endl << left << setw(tK + 4) << "Galutine suma" << right << fixed << suma + suma * pvm << " EUR" << endl;
    outfile.close();
}

void opcijos(meniuList meniu[]) {
    bool darbas = true;
    int opcijos;
    getData(meniu);
    while (darbas == true) {
        cout << "Pasirinkite funkcija:\n0: Nutraukti programa\n1: Parodyti meniu ir pateikti uzsakyma\n2: Spausdinti kvita" << endl;
        cin >> opcijos;
        switch (opcijos) {
            case 0: {
                darbas = false;
                break;
            }
            case 1: {
                parodytiMeniu(meniu);
                break;
            }
            case 2: {
                kvitas(meniu);
                break;
            }
            default: {
                cout << "Netinkamai pasirinkta funkcija!" << endl;
            }
        }
    }
}

int main() {
    meniuList meniu[maxMasyvoDydis];
    opcijos(meniu);
    return 0;
}
