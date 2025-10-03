#include <iostream>

using namespace std;


int main() {
    /*int choise = 0;

    while (choise!=4) {
        cout << "Paprastas meniu pasirinkimas" << endl;
        cout << "1. Pirma opcija" << endl;
        cout << "2. Antra opcija" << endl;
        cout << "3. Trecia opcija" << endl;
        cout << "4. Iseiti" << endl;
        cout << "Jusu pasirinkimas: ";
        cin >> choise;

        switch (choise) {
            case 1:
                cout << "Jus pasirinkote pirma opcija" << endl;
            break;
            case 2:
                cout << "Jus pasirinkote antra opcija" << endl;
            break;
            case 3:
                cout << "Jus pasirinkote trecia opcija" << endl;
            break;
            case 4:
                cout << "Jus pasirinkote iseiti" << endl;
            break;
            default:
                cout << "Tokio pasirinkimo nera." << endl;
        }
    }*/

    //Pirma uzduotis
    /*
    double PirmasSk1;
    double AntrasSk1;
    double Vidurkis1;

    cout << "Ivesk du skaicius" << endl;
    cin >> PirmasSk1 >> AntrasSk1;
    Vidurkis1 = (PirmasSk1 + AntrasSk1) / 2;
    cout << endl << "Vidurkis: " << Vidurkis1 << endl;

    //Antra uzduotis

    double PirmasSk2;
    double AntrasSk2;
    double Vidurkis2;

    cout << "Ivesk du skaicius" << endl;
    cin >> PirmasSk2 >> AntrasSk2;
    Vidurkis2 = (PirmasSk2 + AntrasSk2) / 2;
    if (Vidurkis2 < 5) {cout << endl << "Vidurkis yra neigiamas" << endl;}
    else {cout << endl << "Vidurkis: " << Vidurkis2 << endl;}


    //Trecia uzduotis

    int EgzaminoPaz1;
    cout << "Iveskite egzamino pazymi: ";
    cin >> EgzaminoPaz1;
    cout << endl;
    if (EgzaminoPaz1==10){cout << "Puiu";}
    else if (EgzaminoPaz1==9){cout << "Labai gerai";}
    else if (9>EgzaminoPaz1 & EgzaminoPaz1>4){cout << "Gerai";}
    else if (5>EgzaminoPaz1 & EgzaminoPaz1>=0){cout << "Egzaminas neislaikytas";}
    else {cout << "Netinkama ivestis";}


    //Ketvirta uzduotis

    int EgzaminoPaz2;
    cout << "Iveskite egzamino pazymi: ";
    cin >> EgzaminoPaz2;
    cout << endl;
    switch (EgzaminoPaz2) {
        case 10: cout << "Puiu" << endl; break;
        case 9: cout << "Labai gerai" << endl; break;
        case 8: cout << "Gerai" << endl; break;
        case 7: cout << "Gerai" << endl; break;
        case 6: cout << "Gerai" << endl; break;
        case 5: cout << "Gerai" << endl; break;
        case 4: cout << "Egzaminas neislaikytas" << endl; break;
        case 3: cout << "Egzaminas neislaikytas" << endl; break;
        case 2: cout << "Egzaminas neislaikytas" << endl; break;
        case 1: cout << "Egzaminas neislaikytas" << endl; break;
        case 0: cout << "Egzaminas neislaikytas" << endl; break;
        default: cout << "Netinkama ivestis" << endl;
    }


    //Penkta uzduotis

    int Linija = 20;
    int Seka[20];
    int Kintamasis = 0;
    int Skaicius[Kintamasis];
    int Suma[Kintamasis];

    cout << "Duomenu ivestis" << endl;

    for (int z = 1; z <= Linija; z++) {cout << "-";}
    cout << endl;

    for (int i = 1; i <= 20; i++) {
        Seka[i]=i;
        cout << "I: " << i << endl;}

    for (int z = 1; z <= Linija; z++) {cout << "-";}
    cout << endl;

    for (int i = 1; i <=20; i++) {
        if (Seka[i]%2!=0){Kintamasis++; Skaicius[Kintamasis] = Seka[i]; cout<<"iteracija: "<<i<<"\t"<<endl;}
        else {continue;}
    }

    for (int z = 1; z <= Linija; z++) {cout << "-";}
    cout << endl;

    for (int i = 1; i <= Kintamasis; i++) {
        if (i==1) {
            Suma[i]=Skaicius[i];
            cout << "iteracija: "<<i<<"\t"<<"Tarpine suma: "<<Suma[i]<<endl;
        }
        else {
            int z = i-1;
            Suma[i] = Skaicius[i] + Suma[z];
            cout << "iteracija: "<<i<<"\t"<<"Tarpine suma: "<<Suma[i]<<endl;
        }
    }

    //Sesta uzduotis

    double Skaicius6 = 1000;
    double Metai6 = 20;


    for (int i = 1; i <= Metai6; i++) {
        Skaicius6 = Skaicius6 + Skaicius6 / 100 * 5;
        cout << "Tarpine suma " << i << " metais: " << Skaicius6 << endl;
    }
    cout << "Galutine suma: " << Skaicius6 << endl;
*/

    //Septinta uzduotis

    for (int i = 1; i <= 20; i++ ) {
        if (i % 4 == 0) {cout << "Skaicius: " << i << " dalijasi is 4." << endl;}
        else {continue;}
    }

    return 0;
}
