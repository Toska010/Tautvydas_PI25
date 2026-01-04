#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


/*
Užduotis: „Testų vertinimo sistema“

Tikslas:

Sukurti C++ programą, kuri nuskaito studentų True/False (T/F) testo atsakymus iš failo, apskaičiuoja jų rezultatus, priskiria pažymius pagal dešimties balų vertinimo sistemą, apdorotus duomenis išsaugo rezultatų faile, pateikia klasės statistiką, leidžia ieškoti studento pagal ID ir analizuoja kiekvieno klausimo sudėtingumą.

Uždavinio aprašymas:

Teksto duomenys saugomi faile testData.txt:
Pirmoje failo eilutėje pateikiami teisingi atsakymai į 20 klausimų (T arba F).
Kiekvienoje kitoje eilutėje pateikiamas studento ID, tarpas ir studento atsakymai.
Studento atsakymuose gali būti: T - True, F - False, “-” arba tarpas – neatsakytas klausimas.
Studentų skaičius faile nėra žinomas iš anksto.
Testo vertinimas:

Teisingas atsakymas - +2 taškai
Neteisingas atsakymas - -1 taškas
Neatsakytas klausimas - 0 taškų
Testą sudaro 20 klausimų, todėl maksimaliai surenkamas taškų kiekis yra 40 taškų.
Procentų skaičiavimas:

percent = (score / 40.0) * 100
Pažymių skyrimas (be apvalinimo):

Procentai	Pažymys
95–100 %	10
85–94 %	9
75–84 %	8
65–74 %	7
55–64 %	6
50–54 %	5 (teigiamas)
35–49 %	4
25–34 %	3
15–24 %	2
0–14 %	1
Pastaba: teigiamas įvertinimas pradedamas nuo 5 balų.

Pavyzdžiai:

82 % → 8
85 % → 9
Reikalavimai programai:

Duomenys turi būti nuskaitomi iš failo.
Turi būti naudojama dinaminė atmintis (new / delete[] arba vector), nes studentų skaičius nežinomas iš anksto.
Duomenys turi būti saugomi struktūroje Student.
Programa turi išvesti visų studentų rezultatus.
Turi būti naudojamos funkcijos skaičiavimams ir paieškai.
Privalomos funkcijos:

1) Klasės statistika – apskaičiuoti ir išvesti:
studentų skaičių;
didžiausią ir mažiausią balą;
vidutinį balą ir vidutinį procentą;
pažymių (1–10) pasiskirstymą klasėje.
2) Studento paieška pagal ID – leisti vartotojui įvesti studento ID ir surasti atitinkamą studentą. Jei studentas nerandamas, turi būti išvedamas pranešimas. Paieška kartojama tol, kol vartotojas įveda 0.
3) Rezultatų išsaugojimas į failą – apdorotus studentų rezultatus išsaugoti naujame faile (pvz., results.txt). Faile turi būti: studento ID, surinkti taškai, procentai ir galutinis pažymys. Naudoti ofstream.
4) Kiekvieno klausimo statistika – kiekvienam iš 20 klausimų apskaičiuoti:
kiek studentų atsakė teisingai;
kiek atsakė neteisingai;
kiek neatsakė.
5) Sunkiausio klausimo nustatymas – nustatyti klausimą, kurio teisingų atsakymų procentas yra mažiausias. Jei tokių klausimų yra keli, išvesti visus.
Techniniai reikalavimai:

Naudoti ifstream ir ofstream darbui su failais.
Naudoti new ir delete[] dinaminei atminčiai valdyti arba vector – standartinį C++ bibliotekos konteinerį.
Kodas turi būti tvarkingas, struktūruotas ir pakomentuotas.
*/