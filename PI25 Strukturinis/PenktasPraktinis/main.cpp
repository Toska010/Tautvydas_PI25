#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int klausimuKiekis = 20;
const double maxTasku = 40;
char atsakymai[klausimuKiekis];

struct strukturaStudento {
    string id;
    double procentas;
    int pazymys;
    char atsakymai[klausimuKiekis];
    int taskai;
};

//Procento israiska pazymiu
int priskirtiPaazymi(int procentas) {
    if (procentas >= 95) return 10;
    if (procentas >= 85) return 9;
    if (procentas >= 75) return 8;
    if (procentas >= 65) return 7;
    if (procentas >= 55) return 6;
    if (procentas >= 45) return 5;
    if (procentas >= 35) return 4;
    if (procentas >= 25) return 3;
    if (procentas >= 15) return 2;
                         return 1;
}
//Duomenu paemimas is failo testData.txt
void duomenysIsFailo(vector<strukturaStudento> &studentas) {
    ifstream infile;
    infile.open("testData.txt");
    char laikinas;
    for (int i = 0; i < klausimuKiekis; i++) {
        infile >> atsakymai[i];
    }
    strukturaStudento nezinau;
    while (infile >> nezinau.id) {
        for (int i = 0; i < klausimuKiekis; i++) {
            infile >> laikinas;
            if (laikinas == 'T' || laikinas == 't') laikinas = 'T';
            else if (laikinas == 'F' || laikinas == 'f') laikinas = 'F';
            else laikinas = '-';
            nezinau.atsakymai[i] = laikinas;
        }
        int taskai = 0;
        for (int i = 0; i < klausimuKiekis; i++) {
            if (atsakymai[i] == nezinau.atsakymai[i]) {
                taskai = taskai + 2;
            }
            else if (nezinau.atsakymai[i] == '-') {
                taskai = taskai;
            }
            else {
                taskai = taskai - 1;
            }
        }
        nezinau.taskai = taskai;
        double proc = (taskai / maxTasku) * 100;
        if (proc < 0) proc = 0;
        nezinau.procentas = proc;
        nezinau.pazymys = priskirtiPaazymi(proc);
        studentas.push_back(nezinau);
    }
    infile.close();
}
//Isvedimas i faila results.txt
void saugojimas(const vector<strukturaStudento> &studentas) {
    ofstream lauk;
    lauk.open("results.txt");
    lauk << "ID\tTaskai\tProcent\tPazymys\n";
    for (auto& nezinau : studentas) {
        lauk << nezinau.id << "\t" << nezinau.taskai << "\t" << nezinau.procentas << "%\t" << nezinau.pazymys << endl;
    }
    lauk.close();
}

void klasesStatistika(const vector<strukturaStudento> &studentas) {
    int studentuSk = studentas.size();
    int maxTaskai = studentas[0].taskai;
    int minTaskai = studentas[0].taskai;
    double sumTaskai = 0;
    double sumProc = 0;
    int pazymiuPasiskirstymas[11] = {};
    for (const auto &nezinau : studentas) {
        if (nezinau.taskai > maxTaskai) maxTaskai = nezinau.taskai;
        if (nezinau.taskai < minTaskai) minTaskai = nezinau.taskai;
        sumTaskai += nezinau.taskai;
        sumProc += nezinau.procentas;
        pazymiuPasiskirstymas[nezinau.pazymys]++;
    }
    double vidTaskai = sumTaskai / studentuSk;
    double vidProc = sumProc / studentuSk;
    cout << "Studentu skaicius: " << studentuSk << endl;
    cout << "Didziausias balas: " << maxTaskai << endl;
    cout << "Maziausias balas: " << minTaskai << endl;
    cout << "Vidutinis balas: " << fixed << setprecision(0) << vidTaskai << endl;
    cout << "Vidutinis procentas: " << fixed << vidProc << "%" << endl << endl;
    cout << "Pazymiu pasiskirstymas:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << ": " << pazymiuPasiskirstymas[i];
        if (i  != 10) {
            cout << " | ";
        };
    }
    cout << endl << endl;
}

void studentoPaieska(const vector<strukturaStudento> &studentas) {
    string ID;
    while (true) {
        cout << "Iveskite studento ID\n0: nutraukti paieska: " << endl;
        cin >> ID;
        if (ID == "0") break;

        bool rastas = false;
        for (const auto &nezinau : studentas) {
            if (nezinau.id == ID) {
                cout << "ID\tTaskai\tProcent\tPazymys" << endl;
                cout << nezinau.id << "\t" << nezinau.taskai << "\t" << nezinau.procentas << "%\t" << nezinau.pazymys << endl << endl;
                rastas = true;
                break;
            }
        }
        if (!rastas) {
            cout << "Studentas su ID '" << ID << "' nerastas." <<  endl << endl;
        }
    }
}

void klausimuStatistika(const vector<strukturaStudento> &studentas) {
    int teisingi[klausimuKiekis] = {0};
    int neteisingi[klausimuKiekis] = {0};
    int neatsakyti[klausimuKiekis] = {0};
    for (const auto &nezinau : studentas) {
        for (int i = 0; i < klausimuKiekis; i++) {
            if (nezinau.atsakymai[i] == '-') {
                neatsakyti[i]++;
            } else if (nezinau.atsakymai[i] == atsakymai[i]) {
                teisingi[i]++;
            } else {
                neteisingi[i]++;
            }
        }
    }
    cout << "Kl:\tT:\tF:\t-:" << endl;
    for (int i = 0; i < klausimuKiekis; i++) {
        cout  << (i + 1) << "\t" << teisingi[i] << "\t" << neteisingi[i] << "\t" << neatsakyti[i] << endl << endl;
    }
}

void sunkiausiasKlausimas(const vector<strukturaStudento> &studentas) {
    int teisingi[klausimuKiekis] = {0};
    for (const auto &nezinau : studentas) {
        for (int i = 0; i < klausimuKiekis; i++) {
            if (nezinau.atsakymai[i] == atsakymai[i]) {
                teisingi[i]++;
            }
        }
    }
    double minProcentas = 101.0;
    vector<int> sunkiausi; //Taip ir cia vektorius nes velniai zino kiek tu sunkiausiu klausimu gali buti...
    for (int i = 0; i < klausimuKiekis; i++) {
        double procentas = (static_cast<double>(teisingi[i]) / studentas.size()) * 100.0;
        if (procentas < minProcentas) {
            minProcentas = procentas;
            sunkiausi.clear();
            sunkiausi.push_back(i + 1);
        } else if (procentas == minProcentas) {
            sunkiausi.push_back(i + 1);
        }
    }
    cout << "Klausimas: ";
    for (int nr : sunkiausi) {
        cout << nr << " ";
    }
    cout << "Teisingai atsake: " << minProcentas << "%" << endl << endl;
}

int main() {
    vector<strukturaStudento> studentas;
   duomenysIsFailo(studentas);
    bool veikimas = true;
    int pasirinkimas;
    while (veikimas == true) {
        cout << "Pasirinkite funkcija:\n0: Nutraukti programa\n1: Klases statistika\n2: Studento paieska pagal ID\n3: Rezultatu issaugojimas i faila\n4: Kiekvieno klausimo statistika\n5: Sunkiausio klausimo nustatymas" << endl;
        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case 0: {
                veikimas = false;
                break;
            }
            case 1: {
                klasesStatistika(studentas);
                break;
            }
            case 2: {
                studentoPaieska(studentas);
                break;
            }
            case 3: {
                saugojimas(studentas);
                break;
            }
            case 4: {
                klausimuStatistika(studentas);
                break;
            }
            case 5: {
                sunkiausiasKlausimas(studentas);
                break;
            }
        }
    }
    return 0;
}