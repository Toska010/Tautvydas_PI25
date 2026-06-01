#include <iostream>
using namespace std;

struct sarasas {
    int skaicius;
    sarasas *kitas;
};

sarasas *pradzia = nullptr, *pabaiga = nullptr;
sarasas *nPradzia = nullptr, *nPabaiga = nullptr;

void prideti(sarasas *&start, sarasas *&end, int x) {
    sarasas *el = new sarasas;
    el->skaicius = x;
    el->kitas = nullptr;

    if (!start) start = end = el;
    else {
        end->kitas = el;
        end = el;
    }
}

void sukurtiMasyva() {
    int kiek, x;
    cout << "Iveskite kiek elementu bus: ";
    cin >> kiek;

    for (int i = 0; i < kiek; i++) {
        cout << "Iveskite " << i+1 << " elementa: ";
        cin >> x;
        prideti(pradzia, pabaiga, x);
    }
}

void spausdinti(sarasas *start) {
    while (start) {
        cout << start->skaicius << " ";
        start = start->kitas;
    }
    cout << endl;
}

int ilgis(sarasas *start) {
    int n = 0;
    while (start) {
        n++;
        start = start->kitas;
    }
    return n;
}

sarasas* gauti(sarasas *start, int index) {
    for (int i = 0; i < index; i++)
        start = start->kitas;
    return start;
}

void iKitaSarasa() {
    int n = ilgis(pradzia);

    for (int i = 0; i < n; i++) {
        sarasas *left = gauti(pradzia, i);
        sarasas *right = gauti(pradzia, n - 1 - i);

        prideti(nPradzia, nPabaiga, left->skaicius - right->skaicius);
    }
}

int main() {
    sukurtiMasyva();

    cout << "Pirmas sarasas: ";
    spausdinti(pradzia);

    iKitaSarasa();

    cout << "Antras sarasas: ";
    spausdinti(nPradzia);

    return 0;
}
