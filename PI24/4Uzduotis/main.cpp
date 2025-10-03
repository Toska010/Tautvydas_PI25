#include <iomanip>
#include <iostream>

using namespace std;

double Krastine;
double Perimetras;

double PerimetrasSkaiciuoti(double Krastine) {
    Perimetras = Krastine * 4;
    return Perimetras;
}

void FarToCel(double Temperatura) {
    double Celsijus = Temperatura * 9 / 5 +32;
    cout << Temperatura << " Fahrenheitais = " << Celsijus << " Celsijais" << endl;
}

void CelToFar(double Temperatura) {
    double Farenheit = (Temperatura - 32 ) * 5 / 9;
    cout << Temperatura << " Celsijais = " << Farenheit << " Fahrenheitais" << endl;
}

int main() {
    int Pasirinkimas;
    cout << setw(15) << "Pasirink funkcija:\n1: Celsijai i Fahrenheita\n2: Fahrenheitas i Celsijus" << endl;
    cin >> Pasirinkimas;
    switch (Pasirinkimas) {
        case 1: {
            double Skaicius;
            cout << "Ivesk skaiciu konvertavimui: " << endl;
            cin >> Skaicius;
            CelToFar(Skaicius);
            break;
        }
        case 2: {
            double Skaicius;
            cout << "Ivesk skaiciu konvertavimui: " << endl;
            cin >> Skaicius;
            FarToCel(Skaicius);
            break;
        }
        case 3: {
            cout << "Ivesk krastines ilgi: " << endl;
            cin >> Krastine;
            PerimetrasSkaiciuoti(Krastine);
            cout << "Preimetras = " << Perimetras;
        }
        default: {}
    }
    return 0;
}
