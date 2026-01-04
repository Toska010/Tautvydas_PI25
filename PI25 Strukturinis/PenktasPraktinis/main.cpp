#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int klausimuKiekis = 20;
const int testoIzanga = 4;

struct strukturaKlausimu {
    int id;
    string klausimas;
    bool atsakymas;
};

struct strukturaStudento {
    int id;
    int procentas;
    int pazymys;
    bool teisingi[klausimuKiekis];
    char atsakymai[klausimuKiekis];
};

void trueFalse(strukturaKlausimu klausimai[]) {
    ifstream tiesaNetiesa;
    tiesaNetiesa.open("klausimai.txt");
    int iteracija = 0;
    string eilute;
    while (!tiesaNetiesa.eof()) {
        klausimai[iteracija].id = iteracija;
        getline(tiesaNetiesa, eilute); klausimai[iteracija].klausimas = eilute;
        getline(tiesaNetiesa, eilute);
        if (eilute == "T") {
            klausimai[iteracija].atsakymas = true;
        }
        else {
            klausimai[iteracija].atsakymas = false;
        }
        iteracija++;
    }
    tiesaNetiesa.close();
}

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

void tekstoDuomenys(strukturaKlausimu klausimai[]) {
    ofstream duomenys;
    duomenys.open("testData.txt");
    duomenys << "\t";
    for (int i = 0; i < klausimuKiekis; i++) {
        if(klausimai[i].atsakymas == true) {
            duomenys << "T ";
        }
        else {
            duomenys << "F ";
        }
    }
    duomenys << endl;
    duomenys.close();
}

void testas(strukturaKlausimu klausimai[], vector<strukturaStudento> studentas) {
    ofstream testas;
    testas.open("testas.txt");
    testas << "I klausimus atsakykite po jais esanciose eilutese\nT: jei tiesa, F: jei netiesa, -: jei norite praleisti klausima" << endl << endl;
    testas << "Studento sprendziancio testa id: "; testas << studentas.size() + 1 << endl;
    for (int i = 0; i < klausimuKiekis; i++) {
        testas << klausimai[i].id + 1 << ") " << klausimai[i].klausimas << endl << endl;
    }
    testas.close();
}

void priimti(strukturaKlausimu klausimai[], vector<strukturaStudento> studentas) {
    ifstream testas;
    testas.open("testas.txt");
    string eilute;
    int eilesNr;
    eilesNr = studentas.size();
    strukturaStudento nezinau;
    nezinau.id = eilesNr;
    for (int i = 0; i < testoIzanga; i++) {
        getline(testas, eilute);
    }
    int iteracija = 0;
    while (testas.eof()) {
        getline(testas, eilute);
        getline(testas, eilute);
        if (eilute == "T" || eilute == "t") {
            nezinau.atsakymai[iteracija] = 'T';
        }
        else if (eilute == "F" || eilute == "f") {
            nezinau.atsakymai[iteracija] = 'F';
        }
        else {
            nezinau.atsakymai[iteracija] = '-';
        }
    }


}

int main() {
    vector<strukturaStudento> studentas;
    strukturaKlausimu klausimai[klausimuKiekis];
    trueFalse(klausimai);
    tekstoDuomenys(klausimai);

    bool veikimas = true;
    int pasirinkimas;
    while (veikimas == true) {
        cout << "Pasirinkite funkcija:\n0: Nutraukti programa\n1: Valyti testa\n2: Priimti testa" << endl;
        cin >> pasirinkimas;
        switch (pasirinkimas) {
            case 0: {
                break;
            }
            case 1: {
                testas(klausimai, studentas);
                break;
            }
            case 2: {
                priimti(klausimai, studentas);
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