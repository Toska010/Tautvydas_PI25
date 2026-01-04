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
    if      (procentas >= 95) return 10;
    else if (procentas >= 85) return 9;
    else if (procentas >= 75) return 8;
    else if (procentas >= 65) return 7;
    else if (procentas >= 55) return 6;
    else if (procentas >= 45) return 5;
    else if (procentas >= 35) return 4;
    else if (procentas >= 25) return 3;
    else if (procentas >= 15) return 2;
    else                      return 1;
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
        lauk << nezinau.id << "\t" << nezinau.taskai << "\t" << fixed << setprecision(0) << nezinau.procentas << "%\t" << nezinau.pazymys << endl;
    }
    lauk.close();
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
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                saugojimas(studentas);
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
        }
    }
    return 0;
}


/*

Sukurti C++ programą,
kuri nuskaito studentų True/False (T/F) testo atsakymus iš failo,
apskaičiuoja jų rezultatus,
priskiria pažymius pagal dešimties balų vertinimo sistemą,
apdorotus duomenis išsaugo rezultatų faile,
pateikia klasės statistiką,
leidžia ieškoti studento pagal ID ir analizuoja kiekvieno klausimo sudėtingumą.


Uždavinio aprašymas:

Teksto duomenys saugomi faile testData.txt:                                                                         yra
Pirmoje failo eilutėje pateikiami teisingi atsakymai į 20 klausimų (T arba F).                                      yra
Kiekvienoje kitoje eilutėje pateikiamas studento ID, tarpas ir studento atsakymai.                                  bus
Studento atsakymuose gali būti: T - True, F - False, “-” arba tarpas – neatsakytas klausimas.                       bus


Testo vertinimas:

Teisingas atsakymas - +2 taškai
Neteisingas atsakymas - -1 taškas
Neatsakytas klausimas - 0 taškų
Testą sudaro 20 klausimų, todėl maksimaliai surenkamas taškų kiekis yra 40 taškų.


Procentų skaičiavimas:

percent = (score / 40.0) * 100
Pažymių skyrimas (be apvalinimo):


Reikalavimai programai:

Duomenys turi būti nuskaitomi iš failo.                                                                             yra
Turi būti naudojama dinaminė atmintis (new / delete[] arba vector), nes studentų skaičius nežinomas iš anksto.      yra
Duomenys turi būti saugomi struktūroje Student.                                                                     yra
Programa turi išvesti visų studentų rezultatus.
Turi būti naudojamos funkcijos skaičiavimams ir paieškai.


Privalomos funkcijos:

1) Klasės statistika – apskaičiuoti ir išvesti:
studentų skaičių;
didžiausią ir mažiausią balą;
vidutinį balą ir vidutinį procentą;
pažymių (1–10) pasiskirstymą klasėje.

2) Studento paieška pagal ID – leisti vartotojui įvesti studento ID ir surasti atitinkamą studentą.
Jei studentas nerandamas, turi būti išvedamas pranešimas.
Paieška kartojama tol, kol vartotojas įveda 0.

3) Rezultatų išsaugojimas į failą – apdorotus studentų rezultatus išsaugoti naujame faile (pvz., results.txt).
Faile turi būti: studento ID, surinkti taškai, procentai ir galutinis pažymys. Naudoti ofstream.

4) Kiekvieno klausimo statistika – kiekvienam iš 20 klausimų apskaičiuoti:
kiek studentų atsakė teisingai;
kiek atsakė neteisingai;
kiek neatsakė.

5) Sunkiausio klausimo nustatymas – nustatyti klausimą, kurio teisingų atsakymų procentas yra mažiausias.
Jei tokių klausimų yra keli, išvesti visus.


Techniniai reikalavimai:

Naudoti new ir delete[] dinaminei atminčiai valdyti arba vector – standartinį C++ bibliotekos konteinerį.           yra

*/