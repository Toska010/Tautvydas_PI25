#include <iostream>
#include <string>

using namespace std;

bool programa = true;
const int pazymiai = 10;

string varduMasyvas[3];
int pazymiuMasyvas[3][pazymiai];
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

void laukNulius() {
    for (int i = 0; i <= ivestiMokiniai; i++) {
        for (int j = 0; j <= 9; j++) {
            if (pazymiuMasyvas[i][j] == 0 && j < 9) {
                pazymiuMasyvas[i][j] = pazymiuMasyvas[i][j + 1];
                pazymiuMasyvas[i][j + 1] = 0;
            }
        }
    }
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
                    laukNulius();
                    break;
                }
                case 2: {
                    laukNulius();
                    for (int i = 0; i < ivestiMokiniai; i++) {
                        cout << varduMasyvas[i] << " ID: " << i + 1 << endl;
                        for (int j = 0; j <= 9; j++) {
                            if (pazymiuMasyvas[i][j] != 0) {
                                cout << pazymiuMasyvas[i][j] << " ";
                            }
                        }
                        cout << endl;
                    }
                    break;
                }
                case 3: {
                    while (true) {
                        laukNulius();
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
                                    laukNulius();
                                    int vardoId;
                                    int paz;
                                    cout << "Iveskite mokinio ID: ";
                                    cin >> vardoId;
                                    cout << "Mokinys: " << varduMasyvas[vardoId - 1] << ". Kuri pazymi norite pakeisti? " << endl;
                                    for (int j = 0; j <= 9; j++) {
                                        if (pazymiuMasyvas[vardoId - 1][j] != 0) {
                                            cout << pazymiuMasyvas[vardoId - 1][j] << " ";
                                        }
                                    }
                                    cout << endl;
                                    cin >> paz;
                                    cout << "Pazimys kuri keiciate: " << pazymiuMasyvas[vardoId - 1][paz - 1] << " Iveskite i koki norite pakeisti: ";
                                    cin >> pazymiuMasyvas[vardoId - 1][paz - 1];
                                    cout << "Mokinys: " << varduMasyvas[vardoId - 1] << " nauji pazymiai:" << endl;
                                    for (int j = 0; j <= 9; j++) {
                                        if (pazymiuMasyvas[vardoId - 1][j] != 0) {
                                            cout << pazymiuMasyvas[vardoId - 1][j] << " ";
                                        }
                                    }
                                    cout << endl;
                                    break;
                                }
                                case 2: {
                                    laukNulius();
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
                                                if (pazymiuMasyvas[vardoId][j] != 0) {
                                                    cout << pazymiuMasyvas[vardoId][j] << " ";
                                                }
                                            }
                                            cout << endl;
                                            cin >> paz;
                                            cout << "Pazimys kuri keiciate: " << pazymiuMasyvas[vardoId][paz - 1] << " Iveskite i koki norite pakeisti: ";
                                            cin >> pazymiuMasyvas[vardoId][paz - 1];
                                            cout << "Mokinys: " << varduMasyvas[vardoId] << " nauji pazymiai:" << endl;
                                            laukNulius();
                                            for (int z = 0; z <= 9; z++) {
                                                if (pazymiuMasyvas[vardoId][z] != 0) {
                                                    cout << pazymiuMasyvas[vardoId][z] << " ";
                                                }
                                            }
                                        }
                                    }
                                    cout << endl;
                                    if (neSuveike) {
                                            cout << "Mokinio " << nepasitikiu << " sistemoje nera!" << endl;
                                        }
                                    break;
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
                                    for (ciklas = 0; ciklas <= 2; ciklas++) {
                                        if (nepasitikiu == varduMasyvas[ciklas]) {
                                            neSuveike = false;
                                            int vardoId = ciklas + 1;
                                            cout << "Mokinys: " << varduMasyvas[vardoId - 1] << " buvo pasalnitas!" << endl;
                                            for (int i = vardoId; i <= 2; i++) {
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