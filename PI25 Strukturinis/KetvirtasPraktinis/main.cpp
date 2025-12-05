#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const int strukturosDydis = 124;
int failoDydis;

ofstream istorija;
ifstream duomenuFailas;

struct menuItemType {
    string menuItem;
    double menuPrice;
}Meniu[strukturosDydis];

int getSize() {
    istorija << "getSize pradetas:" << endl;
    failoDydis = 0;
    string laikinas;
    duomenuFailas.open("Duomenys.txt");
    istorija << "atidarytas duomenu failas: Duomenys.txt" << endl;
    while (!duomenuFailas.eof()) {
        getline(duomenuFailas, laikinas);
        failoDydis++;
        istorija << "nuskaityta eilute: " << failoDydis << " su duomenimis: " << laikinas << endl;
    }
    duomenuFailas.close();
    istorija << "uzdarytas duomenu failas: Duomenys.txt" << endl << "grazinamas failo dydis: " << failoDydis << endl << "getSize pabaiga" << endl << endl;
    return failoDydis;
}

vector<pair<string, double>> getData(const string &fileName) {
    istorija << "Paisleido vektorius:" << endl;
    ifstream failas(fileName);
    vector<pair<string, double>> menu;
    string eilute;
    while (getline(failas, eilute)) {
        istringstream iss(eilute);
        string laikinas, pavadinimas;
        double kaina;
        while (iss >> laikinas) {
            if (iss.peek() == EOF) {
                kaina = stod(laikinas);
            }
            else {
                pavadinimas += laikinas + " ";
            }
        }
        if (!pavadinimas.empty()) {
            pavadinimas.pop_back();
        }
        menu.push_back({pavadinimas, kaina});
    }
}



int main() {
    istorija.open("istorija.txt");
    istorija << "Paleista programa" << endl << endl;
    getSize();
    istorija << "tesiamas main darbas" << endl;
    istorija << "Sukuriama struktura (Meniu) kurio dydis: " << failoDydis << endl;
    vector<pair<string, double>> menu = getData("Duomenys.txt");
    cout << "kas darosi?" << endl;
    for (auto &pavadinimas : menu) {
        cout << "Preke: " << pavadinimas.first << " Kaina: " << pavadinimas.second << endl;
    }
}
