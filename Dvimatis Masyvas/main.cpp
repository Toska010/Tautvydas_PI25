#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int eilutes = 3;
    const int stulpeliai = 2;

    int Masyvas[eilutes][stulpeliai];

    cout << "Iveskite 5x3 lenteles elementus: " << endl;
    for (int i = 0; i < eilutes; i++) {
        for(int z = 0; z < stulpeliai; z++) {
            cout << "Masyvo " << i+1 << " x " << z+1 << " elementas: ";
            cin >> Masyvas[i][z];
        }
    }
    cout << "Masyvas" << endl;
    for (int i = 0; i < eilutes; i++) {
        for(int z = 0; z < stulpeliai; z++) {
            cout << setw(5) << Masyvas[i][z] << " ";
        }
        cout << endl;
    }
    cout << "Masyvas ir eiluciu suma" << endl;
    for (int i = 0; i < eilutes; i++) {
        int SumaEiluciu = 0;
        for(int z = 0; z < stulpeliai; z++) {
            cout << setw(5) << Masyvas[i][z] << " ";
            SumaEiluciu += Masyvas[i][z];
        }
        cout << setw(5) << "Eiluciu suma: " << SumaEiluciu << endl;
    }

    cout << "Masyvas ir stulpeliu suma" << endl;
    for (int i = 0; i < stulpeliai; i++) {
        int SumaStulpeliu = 0;
        for(int z = 0; z < eilutes; z++) {
            cout << setw(5) << Masyvas[z][i] << " ";
            SumaStulpeliu += Masyvas[z][i];
        }
        cout << setw(5) << "Stupeliu suma: " << SumaStulpeliu << endl;
    }

    return 0;
}
