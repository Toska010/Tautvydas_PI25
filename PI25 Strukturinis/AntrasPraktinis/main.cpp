#include <iostream>
#include <string>

using namespace std;

bool programa = true;

string varduMasyvas[100];
int pazymiuMasyvas[100][10];
int ivestiMokiniai = 0;

string nepasitikiu;
int nelauzykManoProgramosPrasau(string patikra, int varijantas) {
    if (varijantas == 1) {
        for (int i = 0; i <= 4; i++) {
            if (patikra == to_string(i)) {
                return i;
            }
        }
        cout << "Netinkamas pasirinkimas!" << endl;
        return -1;
    }
    if (varijantas == 2) {
        for (int i = 0; i <= 10; i++) {
            if (patikra == to_string(i)) {
                return i;
            }
        }
        cout << "Netinkamas ivestis" << endl;
        return -1;
    }
    return -1;
}

int main() {
    while (programa == true) {
        // Meniu
        int funkcija = -1;
        while (funkcija != 0 && (4 < funkcija || funkcija < 1)) {
            cout <<
                "Pasirinkite funkcija:\n"
                "0: Nutraukti darba\n"
                "1: Ivesti mokinius ir ju pazymius\n"
                "2: Perziureti visu mokiniu pazymius\n"
                "3: Atnaujinti konkrtu pazymi konkreciam mokyniui\n"
                "4: Pasalinti mokini is saraso"
            << endl;
            cin >> nepasitikiu;
            funkcija = nelauzykManoProgramosPrasau(nepasitikiu,1);
            if (funkcija == 0) {
                programa = false;
                break;
            }
            switch (funkcija) {
                case 1: {
                    int ivedamiMokiniai = 0;
                    int buferis;
                    cout << "Noredami baigti vesti mokiniu vardus ar pazymius irasykite 'NE'" << endl;
                    while (true) {
                        cout << "Iveskite " << ivestiMokiniai + ivedamiMokiniai + 1 << "-ojo mokinio varda:";
                        cin >> nepasitikiu;
                        if (nepasitikiu == "NE") {
                            ivestiMokiniai = ivestiMokiniai + ivedamiMokiniai;
                            break;
                        }
                        else {
                            varduMasyvas[ivestiMokiniai + ivedamiMokiniai] = nepasitikiu;
                            for (int i = 0; i <= 9; i++) {
                                cout << "Iveskite " << i + 1 << "-aji pazymi: ";
                                cin >> nepasitikiu;
                                if (nepasitikiu == "NE") {
                                    break;
                                }
                                else {
                                    buferis = nelauzykManoProgramosPrasau(nepasitikiu,2);
                                    if (0 <= buferis && buferis <= 10) {
                                        pazymiuMasyvas[ivestiMokiniai + ivedamiMokiniai][i] = buferis;
                                    }
                                    else {
                                        i--;
                                    }
                                }
                            }
                            ivedamiMokiniai++;
                        }
                    }
                    break;
                }
                case 2: {
                    for (int i = 0; i < ivestiMokiniai; i++) {
                        cout << varduMasyvas[i] << " ID: " << i + 1 << endl;
                        for (int j = 0; j <= 9; j++) {
                            cout << pazymiuMasyvas[i][j] << " ";
                        }
                        cout << endl;
                    }
                    break;
                }
                case 3: {
                    while (true) {
                        cout <<
                            "Pasirinkite metoda mokiniui pasirinkti:\n"
                            "0: Atgal i meniu\n"
                            "1: Pagal ID\n"
                            "2: Pagal varda"
                        << endl;
                        cin >> nepasitikiu;
                        funkcija = nelauzykManoProgramosPrasau(nepasitikiu,1);
                        if (funkcija == 0) {
                            break;
                        }
                        if (funkcija == 1 || funkcija == 2) {
                            switch (funkcija) {
                                case 1: {
                                    int vardoId;
                                    int paz;
                                    cout << "Iveskite mokinio ID: ";
                                    cin >> vardoId;
                                    cout << "Mokinys: " << varduMasyvas[vardoId - 1] << ". Kuri pazymi norite pakeisti? " << endl;
                                    for (int i = 0; i <= 9; i++) {
                                        cout << pazymiuMasyvas[vardoId - 1][i] << " ";
                                    }
                                    cout << endl;
                                    cin >> paz;
                                    cout << "Pazimys kuri keiciate: " << pazymiuMasyvas[vardoId - 1][paz - 1] << " Iveskite i koki norite pakeisti: ";
                                    cin >> pazymiuMasyvas[vardoId - 1][paz - 1];
                                    cout << "Mokinys: " << varduMasyvas[vardoId - 1] << " nauji pazymiai:" << endl;
                                    for (int i = 0; i <= 9; i++) {
                                        cout << pazymiuMasyvas[vardoId - 1][i] << " ";
                                    }
                                    cout << endl;
                                    break;
                                }
                                case 2: {
                                    cout << "Iveskite mokinio varda: ";
                                    cin >> nepasitikiu;
                                    int ciklas;
                                    bool neSuveike = true;
                                    for (ciklas = 0; ciklas <= 99; ciklas++) {
                                        if (nepasitikiu == varduMasyvas[ciklas]) {
                                            neSuveike = false;
                                            int vardoId = ciklas;
                                            int paz;
                                            cout << "Mokinys: " << varduMasyvas[vardoId] << ". Kuri pazymi norite pakeisti? " << endl;
                                            for (int j = 0; j <= 9; j++) {
                                                cout << pazymiuMasyvas[vardoId][j] << " ";
                                            }
                                            cout << endl;
                                            cin >> paz;
                                            cout << "Pazimys kuri keiciate: " << pazymiuMasyvas[vardoId][paz - 1] << " Iveskite i koki norite pakeisti: ";
                                            cin >> pazymiuMasyvas[vardoId][paz - 1];
                                            cout << "Mokinys: " << varduMasyvas[vardoId] << " nauji pazymiai:" << endl;
                                            for (int z = 0; z <= 9; z++) {
                                                cout << pazymiuMasyvas[vardoId][z] << " ";
                                            }
                                        }
                                        if (neSuveike) {
                                            cout << "Mokinio " << nepasitikiu << " sistemoje nera!" << endl;
                                        }
                                        cout << endl;
                                        break;
                                    }
                                }
                                default: {
                                    cout << "Tokio pasirinkimo nera!" << endl;
                                }
                            }
                        }
                    }
                    break;
                }
                case 4: {
                    while (true) {
                        cout <<
                            "Pasirinkite metoda mokiniui pasalinti:\n"
                            "0: Atgal i meniu\n"
                            "1: Pagal ID\n"
                            "2: Pagal varda"
                        << endl;
                        cin >> nepasitikiu;
                        funkcija = nelauzykManoProgramosPrasau(nepasitikiu,1);
                        if (funkcija == 0) {
                            break;
                        }
                        if (funkcija == 1 || funkcija == 2) {
                            switch (funkcija) {
                                case 1: {
                                    int vardoId;
                                    cout << "Iveskite mokinio ID: ";
                                    cin >> vardoId;
                                    cout << "Mokinys: " << varduMasyvas[vardoId - 1] << " buvo pasalnitas!" << endl;
                                    for (int i = vardoId; i <= 99; i++) {
                                        varduMasyvas[i - 1] = varduMasyvas[i];
                                        for (int j = 0; j <= 9; j++) {
                                            pazymiuMasyvas[i - 1][j] = pazymiuMasyvas[i][j];
                                        }
                                    }
                                    ivestiMokiniai--;
                                    break;
                                }
                                case 2: {
                                    cout << "Iveskite mokinio varda: ";
                                    cin >> nepasitikiu;
                                    int ciklas;
                                    bool neSuveike = true;
                                    for (ciklas = 0; ciklas <= 99; ciklas++) {
                                        if (nepasitikiu == varduMasyvas[ciklas]) {
                                            neSuveike = false;
                                            int vardoId = ciklas + 1;
                                            cout << "Mokinys: " << varduMasyvas[vardoId - 1] << " buvo pasalnitas!" << endl;
                                            for (int i = vardoId; i <= 99; i++) {
                                                varduMasyvas[i - 1] = varduMasyvas[i];
                                                for (int j = 0; j <= 9; j++) {
                                                    pazymiuMasyvas[i - 1][j] = pazymiuMasyvas[i][j];
                                                }
                                            }
                                            ivestiMokiniai--;
                                            break;
                                        }
                                    }
                                }
                                default: {
                                    cout << "Tokio pasirinkimo nera!" << endl;
                                    break;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}