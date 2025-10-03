#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int dydis;
    float vidurkis = 0;
    float teigiamas = 5;
    string arTeigiamas = "klaida";
    cout << "Ivesk koks bus pazymiu kiekis: " << endl;
    cin >> dydis;
    int pazymiai[dydis];
    for (int i = 0; i < dydis; i++) {
        cout << "Ivesk " << i + 1 << "-aji pazymi: " << endl;
        cin >> pazymiai[i];
    }
    for (int i = 0; i < dydis; i++) {
        vidurkis = float(pazymiai[i]) + vidurkis;
        cout << i + 1 << " pazimys = " << pazymiai[i] << endl;
    }
    if (teigiamas < vidurkis) {arTeigiamas = "neigiamas";}
    else if (teigiamas > vidurkis) {arTeigiamas = "teigiamas";}
    cout << "vidurkis " << vidurkis / dydis << " yra " << arTeigiamas << endl;



    return 0;
}
