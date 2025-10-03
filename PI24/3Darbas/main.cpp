#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void Issaukimas() {
    string Vardas = "Tautvydas";
    string Tekstas = "Programu sistemu studijas pasirinkau todel, nes atrode idomios studijos.";
    cout << Vardas << "\t" << Tekstas << endl;
}

void Pavadinimas() {
    string Turinys = "Vilniaus kolegija";
    cout << Turinys << endl;
}

void Fakultetas() {
    string Turinys = "Elektronikos ir informatikos fakultetas";
    cout << Turinys << endl;
}

int Atsitiktinis();

int main() {
    Issaukimas();
    Issaukimas();

    Pavadinimas();
    Fakultetas();

    for (int i = 1; i <= 10; i++) {
    Atsitiktinis();
        cout << Atsitiktinis() << endl;
    }

    return 0;


}
int Atsitiktinis() {
    srand(time(nullptr));
    int Skaicius = rand();
    return Skaicius;
}
