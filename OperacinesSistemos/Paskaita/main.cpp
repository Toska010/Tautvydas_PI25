#include <iostream>
using namespace std;

int main() {
    // Pirmas
    cout << "Iveskite kiek bus duomenu:" << endl;
    int duomenuKiekis;
    cin >> duomenuKiekis;
    int duomenys[duomenuKiekis];
    for (int i = 0; i < duomenuKiekis; i++) {
        cout << "Iveskite " << i + 1 << " duomenis: " << endl;
        cin >> duomenys[i];
    }
    int neigiami;
    for (int i = 0; i < duomenuKiekis; i++) {
        if (duomenys[i] < 0) {
            neigiami = duomenys[i] + neigiami;
        }
    }
    cout << "Neigiamu skaiciu suma: " << neigiami << endl;
    int didziausias = duomenys[0];
    int maziausias = duomenys[0];
    for (int i = 0; i < duomenuKiekis; i++) {
        if (duomenys[i] < maziausias) {
            maziausias = duomenys[i];
        }
        else if (duomenys[i] > didziausias) {
            didziausias = duomenys[i];
        }
    }
    cout << "Didziausias: " << didziausias << "\nMaziausias: " << maziausias << "\nJu suma:" << didziausias + maziausias << endl;
    int keitimas;
    for (int i = 0; i < duomenuKiekis; i++) {
        for (int j = 0; j < duomenuKiekis; j++) {
            if (duomenys[j] < duomenys[i]) {
                keitimas = duomenys[i];
                duomenys[i] = duomenys[j];
                duomenys[j] = keitimas;

            }
        }
    }
    for (int i = 0; i < duomenuKiekis; i++) {
        cout << duomenys[i] << " " << endl;
    }
    return 0;
}
