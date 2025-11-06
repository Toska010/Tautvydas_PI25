#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
static int funkcijuKiekis = 3;
string failai[4] = {"Bilietai.txt", "DarbuotojaiAlgos.txt", "Pardavimai.txt", "AtnaujintiDarbuotojaiAlgos.txt"};
string meniuPasirinkimai[1] = {"Pasirink funkcija:\n0: Nutraukti darba\n1: Skaiciuoti bilietu pardavim\n2: Atnaujinti darbuotoju atlyginimus"};
int meniu() {
    while (true) {
        cout << meniuPasirinkimai[0] << endl;
        string ivestis;
        cin >> ivestis;
        for (int i = 0; i < funkcijuKiekis; i++) {
            if (i == stoi(ivestis)) {
                return i;
            }
        }
        cout << "Netinkamas pasirinkimas!" << endl;
    }
}
void pirmas(int veiksmas) {
    int operacija = veiksmas - 1;
    int suveike = 0;
    double paimta;
    ifstream bilietaiFailas;
    bilietaiFailas.open(failai[operacija]);
    string sudas;
    getline(bilietaiFailas, sudas); //Eilutes ignoravimas
    cout << "Nuskaitomi elementai" << endl;
    while (!bilietaiFailas.eof()) {
        bilietaiFailas >> paimta;
        cout << suveike + 1 << endl;
        suveike++;
    }
    double failoMasyvas[suveike];
    suveike = 0;
    bilietaiFailas.close();
    bilietaiFailas.open(failai[operacija]);
    getline(bilietaiFailas, sudas); //Eilutes ignoravimas
    while (!bilietaiFailas.eof()) {
        bilietaiFailas >> failoMasyvas[suveike];
        suveike++;
    }
    bilietaiFailas.close();
    ofstream bilietaiFailas2;
    bilietaiFailas2.open(failai[operacija + 2]);
    cout << left << setw(15) << "Kaina" << left << setw(15) << "Kiekis" << "Suma" << endl;
    bilietaiFailas2 << left << setw(15) << "Kaina" << left << setw(15) << "Kiekis" << "Suma" << endl;
    cout << fixed << setprecision(2);
    bilietaiFailas2 << fixed << setprecision(2);
    double bendrasKiekis = 0;
    double bendraSuma = 0;
    for (int i = 0; i < suveike; i++) {
        int dalybai = i + 2;
        if (dalybai % 2 == 0) {
            cout << left << setw(15) << failoMasyvas[i];
            bilietaiFailas2 << left << setw(15) << failoMasyvas[i];
        }
        else {
            bendrasKiekis += failoMasyvas[i];
            bendraSuma += failoMasyvas[i] * failoMasyvas[i - 1];
            cout << left << setw(15) << fixed << setprecision(0) << failoMasyvas[i] << fixed << setprecision(2) << failoMasyvas[i - 1] * failoMasyvas[i] << endl;
            bilietaiFailas2 << left << setw(15) << fixed << setprecision(0) << failoMasyvas[i] << fixed << setprecision(2) << failoMasyvas[i - 1] * failoMasyvas[i] << endl;
        }
    }
    cout << left << setw(15) << "Viso:" << left << setw(15) << fixed << setprecision(0) << bendrasKiekis << setprecision(2) << bendraSuma << endl;
    bilietaiFailas2 << left << setw(15) << "Viso:" << left << setw(15) << fixed << setprecision(0) << bendrasKiekis << setprecision(2) << bendraSuma << endl;
}
void antras(int veiksmas) {
    int operacija = veiksmas - 1;
    int suveike = 0;
    string sudas;
    ifstream algosFailas;
    algosFailas.open(failai[operacija]);
    getline(algosFailas, sudas);
    while (!algosFailas.eof()) {
        getline(algosFailas, sudas);
        suveike++;
    }
    algosFailas.close();
    algosFailas.open(failai[operacija]);
    ofstream algosFailas2;
    algosFailas2.open(failai[operacija + 2]);
    double skaiciai[suveike * 2];
    string vardasPav[suveike * 2];
    suveike = 0;
    getline(algosFailas, sudas);
    algosFailas2 << "Pavarde\tVardas\tAlga" << endl;
    cout << "Pavarde\tVardas\tAlga" << endl;
    while (!algosFailas.eof()) {
        algosFailas >> vardasPav[suveike] >> vardasPav[suveike + 1] >> skaiciai[suveike + 2] >> skaiciai[suveike + 3];
        algosFailas2 << vardasPav[suveike] << "\t" << vardasPav[suveike + 1] << "\t" << skaiciai[suveike + 2] * (1 + skaiciai[suveike + 3] / 100) << endl;
        cout << vardasPav[suveike] << "\t" << vardasPav[suveike + 1] << "\t" << skaiciai[suveike + 2] * (1 + skaiciai[suveike + 3] / 100) << endl;
        suveike + 4;
    }
}
int main() {
    while (true) {
        int veiksmas = meniu();
        if (veiksmas == 0) {
            break;
        }
        if (veiksmas == 1) {
            pirmas(veiksmas);
        }

        if (veiksmas == 2) {
            antras(veiksmas);
        }
    }
    return 0;
}