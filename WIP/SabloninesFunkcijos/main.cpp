#include <iostream>
using namespace std;

const int saraElem = 2;
bool sarasaiElementai[saraElem] = {false, false};

struct dSarasas {
    int skaicius;
    dSarasas *kitas;
    dSarasas *ankstesnis;
};
struct vSarasas {
    int skaicius;
    vSarasas *kitas;
};

int paimtSk() {
    int sk;
    cin >> sk;
    return sk;
}

void meniuOpciju(bool sar, bool ele, int pasirinkimas) {
    while (true) {
        switch (pasirinkimas) {
            case 0:
        }
    }
}

int main()
{
    return 0;
}
