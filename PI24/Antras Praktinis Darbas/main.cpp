#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool Balsiai() {
    string BALSIAI[10]{"A","a","E","e","U","u","I","i","O","o"};
    string Balsis;
    cout << "Iveskite raide:";
    cin >> Balsis;
    for (int i = 0; i < 10; i++) {
        if(Balsis == BALSIAI[i]) {
            return true;
        }
    }
    return false;
}

void Daliklis() {
    int Skaicius1;
    int Skaicius2;
    cout << "Iveskite du skaicius:";
    cin >> Skaicius1 >> Skaicius2;
    if (Skaicius1 == 0 || Skaicius2 == 0){cout << "Dalyba is nulio negalima!" << endl;}
    else {
        int Skaicius3;
        if (Skaicius1 < Skaicius2){Skaicius3 = Skaicius1; Skaicius1 = Skaicius2; Skaicius2 = Skaicius3;}
        while (Skaicius2 != 0) {
            Skaicius3 = Skaicius1;
            Skaicius1 = Skaicius2;
            Skaicius2 = Skaicius3 % Skaicius1;
            if(Skaicius2 == 0){cout << "Didziausias bendras daliklis = " << Skaicius1 << endl;}
        }
    }
}

void Zaidimas() {
    srand(time(nullptr));
    int Spejimas;
    int Skaicius = (rand() %100) + 1;
    cout << "Atspek skaiciu:" << endl;
    for (int i = 1; i <=10; i++) {
        cin >> Spejimas;
        if (Spejimas == Skaicius) {
            cout << "Atspejai, sveikinu!" << endl;
            break;
        }
        if (Spejimas < Skaicius) {
            cout << "Daugiau" << endl;
        }
        if (Spejimas > Skaicius) {
            cout << "Maziau" << endl;
        }
        if (i == 10) {
            cout << endl << "Pasiduodi?\n1: Taip\t2: Ne" << endl;
            cin >> Spejimas;
            switch (Spejimas) {
                case 1: {
                    break;
                }
                case 2: {
                    i = 0;
                    cout << "Skaicius" << endl;
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
}

void Velniava() {
    int Skaicius;
    cout << "Ivesk sveika, teigiama skaiciu:" << endl;
    cin >> Skaicius;
    int SMasyvas[Skaicius + 1];
    for (int i = 1; i < Skaicius + 1; i++) {
        SMasyvas[i] = i;
        if (SMasyvas[i] % 3 == 0 && SMasyvas[i] % 5 == 0) {
            cout << SMasyvas[i] << " FizzBuzz" << endl;
        }
        else if (SMasyvas[i] % 3 == 0) {
            cout << SMasyvas[i] << " Fizz" << endl;
        }
        else if (SMasyvas[i] % 5 == 0) {
            cout << SMasyvas[i] << " Buzz" << endl;
        }
        else {cout << SMasyvas[i] << endl;}
    }
}

int Pasirinkimas = 0;

int main() {
    for (int Ratas = 0; Ratas <=1; Ratas++) {
        cout << "Pasirinkite veiksma:\n1: Balses tikrinimas\n2: Bendras didziausias daliklis\n3: Atspek skaiciu\n4: FizzBuzz\n5: Iseiti" << endl;
        cin >> Pasirinkimas;
        switch (Pasirinkimas) {
            case 1: {
                Ratas--;
                Balsiai();
                break;
            }
            case 2: {
                Ratas--;
                Daliklis();
                break;
            }
            case 3: {
                Ratas--;
                Zaidimas();
                break;
            }
            case 4: {
                Ratas--;
                Velniava();
                break;
            }
            case 69: {
                Ratas = 2;
                cout << "Vaikiska";
                break;
            }
            case 420: {
                Ratas = 2;
                cout << ";)" << endl;
                break;
            }
            case 911: {
                srand(time(nullptr));
                int Faktas = (rand() % 7) + 1;
                switch (Faktas) {
                    case 1: {
                        cout << "The deadliest terrorist attacks on U.S. soil in U.S. history" << endl;
                        break;
                    }
                    case 2: {
                        cout << "Over 3,000 people died in the attacks and rescue efforts" << endl;
                        break;
                    }
                    case 3: {
                        cout << "President George W. Bush was reading with schoolchildren during the attacks" << endl;
                        break;
                    }
                    case 4: {
                        cout << "Flight 93 crashed before reaching its target" << endl;
                        break;
                    }
                    case 5: {
                        cout << "It was the longest uninterrupted news event in American history" << endl;
                        break;
                    }
                    case 6: {
                        cout << "16 people survived in a stairwell during the collapse of the North Tower" << endl;
                        break;
                    }
                    case 7: {
                        cout << "In total, 2,977 people (not including the 19 plane hijackers) died in the attacks and thousands were injured" << endl;
                        break;
                    }
                }

            }
            default: {
                Ratas = 2;
                cout << "Viso gero" << endl;
                break;
            }
        }
    }
    return 0;
}
