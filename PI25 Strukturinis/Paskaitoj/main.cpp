#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string failai[2]{"algos.txt", "bilietai.txt"};

int dydisFailo(string paduotas) {
    int kiekis = 0;
    int laikinas;
    ifstream Failas;
    Failas.open(paduotas);
    while (!Failas.eof()) {
        Failas >> laikinas;
        kiekis++;
    }
    Failas.close();
    return kiekis;
}

void nuskaitymasFailo(string paduotas, int max) {
    ifstream bilietuFailas;
    bilietuFailas.open(paduotas);
    while (!bilietuFailas.eof()) {

    }
}

int main() {
    int masyvasBilietu;
    masyvasBilietu = dydisFailo(failai[1]);
    double bilietai[masyvasBilietu/2][masyvasBilietu/2];
    return 0;
}
