#include <iostream>
#include <string>
#include <ctime>
#include<string.h>

using namespace std;

//string Velniava[32] {"A","Ą","B","C","Č","D","E","Ę","Ė","F","G","H","I","Į","Y","J","K","L","M","N","O","P","R","S","Š","T","U","Ų","Ū","V","Z","Ž"};
const char Velniava[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//                           1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26
void SifruoteAbc() {
        char Tekstas[50];
        char Raktas[50];
        int SifruotoId;

        cout << "Ivesk norima uzsifruoti teksta: " << endl;
        cin >> Tekstas;
        cout << "Ivesk rakta sifravimui: " << endl;
        cin >> Raktas;

        int DydisSifruotuiTekstui = strlen(Tekstas);
        char Sifruotas[DydisSifruotuiTekstui];

        for(int i = 0; i < DydisSifruotuiTekstui; i++) {
            for(int k = 0; k < sizeof(Velniava); k++) {
                if(toupper(Tekstas[i]) == Velniava[k]) {
                    for(int l = 0; l < sizeof(Velniava); l++) {
                        if(toupper(Raktas[i % strlen(Raktas)]) == Velniava[l]) {
                            SifruotoId = (k + l) % sizeof(Velniava);
                            Sifruotas[i] = Velniava[SifruotoId];
                        }
                    }


                }
            }
        }
    cout << Sifruotas << endl;
}

void IssifruotiAbc() {
    char Tekstas[50];
    char Raktas[50];
    int RaktoId;

    cout << "Ivesk norima issifruoti teksta: " << endl;
    cin >> Tekstas;
    cout << "Ivesk rakta issifravimui: " << endl;
    cin >> Raktas;

    int DydisTekstui = strlen(Tekstas);
    char Issifruotas[DydisTekstui];

    for(int i = 0; i < DydisTekstui; i++) {
        for(int k = 0; k < sizeof(Velniava); k++) {
            if(toupper(Tekstas[i]) == Velniava[k]) {
                for(int l = 0; l < sizeof(Velniava); l++) {
                    if(toupper(Raktas[i % strlen(Raktas)]) == Velniava[l]) {
                        RaktoId = l;
                    }
                }
                Issifruotas[i] = Velniava[(k - RaktoId + sizeof(Velniava))  % sizeof(Velniava)];
            }
        }
    }
    cout << Issifruotas << endl;
}

void SifruoteASCII() {
    char Tekstas[50];
    char Raktas[50];
    int SifruotoSkaicius;
    int TekstoSkaicius;
    int RaktoSkaicius;


    cout << "Ivesk norima uzsifruoti teksta: " << endl;
    cin >> Tekstas;
    cout << "Ivesk rakta sifravimui: " << endl;
    cin >> Raktas;
    char Sifruotas[strlen(Tekstas)];
    // 93 simboliai be nesamoniu
    // nuo 33 iki 126

    for(int i = 0; i < strlen(Tekstas); i++) {
        TekstoSkaicius = (int(Tekstas[i]) - 33);
                                                                            cout << TekstoSkaicius << endl;
        RaktoSkaicius = (int(Raktas[i % strlen(Raktas)]) - 33);
                                                                            cout << RaktoSkaicius << endl;
        SifruotoSkaicius = (TekstoSkaicius + RaktoSkaicius) % 85 + 33;
                                                                            cout << SifruotoSkaicius << endl;
        Sifruotas[i] = char(SifruotoSkaicius);
                                                                            cout << Sifruotas[i] << endl;

    }
    cout << Sifruotas << endl;
}

void IssifruoteASCII() {
    char Tekstas[50];
    char Raktas[50];
    int IssifruotoSkaicius;
    int TekstoSkaicius;
    int RaktoSkaicius;


    cout << "Ivesk norima issifruoti teksta: " << endl;
    cin >> Tekstas;
    cout << "Ivesk rakta issifravimui: " << endl;
    cin >> Raktas;
    char Issifruotas[strlen(Tekstas)];
    // 93 simboliai be nesamoniu
    // nuo 33 iki 126

    for(int i = 0; i < strlen(Tekstas); i++) {
        RaktoSkaicius = (int(Raktas[i % strlen(Raktas)]) - 33) % 94;
        //SifruotoSkaicius = int(Tekstas[i]) + int(Raktas[i % strlen(Raktas)]);
        TekstoSkaicius = (int(Tekstas[i]) - 33);
        cout << TekstoSkaicius << endl;
        RaktoSkaicius = (int(Raktas[i % strlen(Raktas)]) - 33);
        cout << RaktoSkaicius << endl;
        IssifruotoSkaicius = (TekstoSkaicius - RaktoSkaicius) + 118;
        cout << IssifruotoSkaicius << endl;
        Issifruotas[i] = char(IssifruotoSkaicius);
        cout << Issifruotas[i] << endl;

    }
    cout << Issifruotas << endl;
}

int main() {
    while(true) {
        int Pasirinkimas;
        cout << "Pasirinkite funkcija:\t1: Sifruoti\t2: Desifruoti" << endl;
        cin >> Pasirinkimas;
        switch(Pasirinkimas) {
            case 1: {
                int Pasirinkimas2;
                cout << "Kokiu metodu:\t1: Abecele\t2: ASCII" << endl;
                cin >> Pasirinkimas2;
                switch(Pasirinkimas2) {
                    case 1: {
                        SifruoteAbc();
                        break;
                    }
                    case 2: {
                        SifruoteASCII();
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case 2: {
                int Pasirinkimas2;
                cout << "Koki metoda:\t1: Abecele\t2: ASCII" << endl;
                cin >> Pasirinkimas2;
                switch(Pasirinkimas2) {
                    case 1: {
                        IssifruotiAbc();
                        break;
                    }
                    case 2: {
                        IssifruoteASCII();
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            default: {
                break;
            }
        }
    }

    cout << "Hello, World!" << endl;
    return 0;
}