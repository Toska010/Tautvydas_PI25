#include <iostream>
#include <string>
using namespace std;
struct medis
{
    string data;
    int balansas;
    medis *desine;
    medis *kaire;
};
medis *saknis = NULL;
struct sarasas {
    string data;
    sarasas *kitas;
    sarasas *ankstesnis;
};
sarasas* sarPradzia = NULL;
sarasas* sarPabaiga = NULL;
struct stekas {
    string data;
    stekas *kitas;
};
stekas* stePradzia = NULL;
stekas* stePabaiga = NULL;
struct laikinasStekas {
    string data;
    laikinasStekas *kitas;
};
int aukstis(medis* saknis)
{
    if (saknis == NULL) {
        return 0;
    }
    int kaire = aukstis(saknis->kaire);
    int desine = aukstis(saknis->desine);
    if (kaire > desine) {
        return 1 + kaire;
    }
    else {
        return 1 + desine;
    }
}
bool pavardesPabaiga(string pavarde, string baigiasi) {
    if (pavarde.length() < baigiasi.length()) {
        return false;
    }
    return pavarde.substr(pavarde.length() - baigiasi.length()) == baigiasi;
}
void sarasoPriekin(string pavarde) {
    sarasas* elem = new sarasas;
    elem->data = pavarde;
    elem->ankstesnis = NULL;
    elem->kitas = sarPradzia;
    if (sarPradzia != NULL) {
        sarPradzia->ankstesnis = elem;
    }
    else {
        sarPabaiga = elem;
    }
    sarPradzia = elem;
}
void sarasoPabaigon(string pavarde) {
    sarasas* elem = new sarasas;
    elem->data = pavarde;
    elem->kitas = NULL;
    elem->ankstesnis = sarPabaiga;
    if (sarPabaiga != NULL) {
        sarPabaiga->kitas = elem;
    }
    else {
        sarPradzia = elem;
    }
    sarPabaiga = elem;
}
void iSteka(string pavarde) {
    stekas* elem = new stekas;
    elem->data = pavarde;
    elem->kitas = NULL;
    if (stePabaiga == NULL) {
        stePradzia = elem;
        stePabaiga = elem;
    } else {
        stePabaiga->kitas = elem;
        stePabaiga = elem;
    }
}
void spausdintiSarasa() {
    sarasas* elem = sarPradzia;
    while (elem != NULL) {
        cout << elem->data << endl;
        elem = elem->kitas;
    }
    cout << endl;
}
void spausdintiSteka() {
    stekas* elem = stePradzia;
    while (elem != NULL) {
        cout << elem->data << endl;
        elem = elem->kitas;
    }
    cout << endl;
}
void valytiSarasa() {
    sarasas* elem = sarPradzia;
    while (elem != NULL) {
        sarasas* temp = elem;
        elem = elem->kitas;
        delete temp;
    }
    sarPradzia = NULL;
    sarPabaiga = NULL;
}
void valytiSteka() {
    stekas* elem = stePradzia;
    while (elem != NULL) {
        stekas* temp = elem;
        elem = elem->kitas;
        delete temp;
    }
    stePradzia = NULL;
    stePabaiga = NULL;
}
int skaiciuotiBalansa(medis* saknis)
{
    if (saknis == NULL) return 0;
    return aukstis(saknis->desine) - aukstis(saknis->kaire);
}
void atnaujintiBalansus(medis* saknis)
{
    if (saknis == NULL) return;
    saknis->balansas = skaiciuotiBalansa(saknis);
    atnaujintiBalansus(saknis->kaire);
    atnaujintiBalansus(saknis->desine);
}
medis* naujasElementas(string pavarde)
{
    medis *elem;
    elem = new medis;
    elem->balansas = 0;
    elem->data = pavarde;
    elem->kaire = NULL;
    elem->desine = NULL;
    return elem;
}
medis* paieska(medis* saknis, string pavarde)
{
    if (saknis == NULL) {
        return NULL;
    }
    if (saknis->data == pavarde) {
        return saknis;
    }
    medis* kaire = paieska(saknis->kaire, pavarde);
    if (kaire != NULL) {
        return kaire;
    }
    return paieska(saknis->desine, pavarde);
}
void ieskomKo(medis* saknis, string pavarde) {
    medis* ieskom = paieska(saknis, pavarde);
    if (ieskom != NULL) {
        cout << "Elementas: " << ieskom->data << " rastas.\n";
    }
    else {
        cout << "Tokio elemento nera!\n";
    }
}
medis* iterpti(medis* saknis, string pavarde)
{
    if (saknis == NULL) {
        return naujasElementas(pavarde);
    }
    if (saknis->kaire == NULL) {
        saknis->kaire = naujasElementas(pavarde);
        return saknis;
    }
    if (saknis->desine == NULL) {
        saknis->desine = naujasElementas(pavarde);
        return saknis;
    }
    iterpti(saknis->kaire, pavarde);
    return saknis;
}
medis* Desinen(medis* saknis)
{
    if (saknis == NULL || saknis->kaire == NULL) {
        return saknis;
    }
    medis* elem = saknis->kaire;
    medis* elem2 = elem->desine;
    elem->desine = saknis;
    saknis->kaire = elem2;
    // skaiciujam svori saknu
    saknis->balansas = skaiciuotiBalansa(saknis);
    elem->balansas = skaiciuotiBalansa(elem);
    return elem;
}
medis* Kairen(medis* saknis)
{
    if (saknis == NULL || saknis->desine == NULL) {
        return saknis;
    }
    medis* elem = saknis->desine;
    medis* elem2 = elem->kaire;
    elem->kaire = saknis;
    saknis->desine = elem2;
    // skaiciujam svori saknu
    saknis->balansas = skaiciuotiBalansa(saknis);
    elem->balansas = skaiciuotiBalansa(elem);
    return elem;
}
medis* balansuotiForma(medis* saknis)
{
    if (saknis == NULL) {
        return NULL;
    }
    saknis->kaire  = balansuotiForma(saknis->kaire);
    saknis->desine = balansuotiForma(saknis->desine);
    int bal = skaiciuotiBalansa(saknis);
    saknis->balansas = bal;
    // Kaire gili
    if (bal < -1) {
        if (saknis->kaire != NULL) {
            int balansas = skaiciuotiBalansa(saknis->kaire);
            if (balansas > 0) {
                saknis->kaire = Kairen(saknis->kaire);
            }
        }
        return Desinen(saknis);
    }
    // Desine gili
    if (bal > 1) {
        if (saknis->desine != NULL) {
            int balansas = skaiciuotiBalansa(saknis->desine);
            if (balansas < 0) {
                saknis->desine = Desinen(saknis->desine);
            }
        }
        return Kairen(saknis);
    }
    return saknis;
}
medis* desiniausias(medis* saknis)
{
    if (saknis == NULL) {
        return NULL;
    }
    while (saknis->desine != NULL) {
        saknis = saknis->desine;
    }
    return saknis;
}
medis* salinti(medis* saknis, string pavarde)
{
    if (saknis == NULL) {
        return NULL;
    }

    if (saknis->data == pavarde) {
        // Bevaikis
        if (saknis->kaire == NULL && saknis->desine == NULL) {
            delete saknis;
            return NULL;
        }
        // Vaikas desinej
        if (saknis->kaire == NULL) {
            medis* temp = saknis->desine;
            delete saknis;
            return temp;
        }
        // Vaikas kairej
        if (saknis->desine == NULL) {
            medis* temp = saknis->kaire;
            delete saknis;
            return temp;
        }
        // Daugiavaikis
        medis* temp = desiniausias(saknis->kaire);
        temp->desine = saknis->desine;

        medis* nauja_saknis = saknis->kaire;
        delete saknis;
        return nauja_saknis;
    }
    // ieskom giliau
    saknis->kaire = salinti(saknis->kaire, pavarde);
    saknis->desine = salinti(saknis->desine, pavarde);
    return saknis;
}
void spausdinti(medis* saknis) {
    if (saknis == NULL) {
        return;
    }
    cout << saknis->data << endl;
    spausdinti(saknis->kaire);
    spausdinti(saknis->desine);
}
void spausdintiVizualu(medis* saknis, int gylis = 0)
{
    if (saknis == NULL) {
        return;
    }
    for (int i = 0; i < gylis; i++) cout << "  ";
    cout << saknis->data << " (bal=" << saknis->balansas << ") Gylis: " << gylis << "\n";

    spausdintiVizualu(saknis->kaire, gylis + 1);
    spausdintiVizualu(saknis->desine, gylis + 1);
}
medis* sabloninisIterpimas() {
    // ---- baigiasi "as" ----
    saknis = iterpti(saknis, "Petrauskas");
    saknis = iterpti(saknis, "Jankauskas");
    saknis = iterpti(saknis, "Kazlauskas");
    saknis = iterpti(saknis, "Ramanauskas");
    saknis = iterpti(saknis, "Paulauskas");
    saknis = iterpti(saknis, "Navickas");
    saknis = iterpti(saknis, "Zukauskas");
    saknis = iterpti(saknis, "Baranauskas");
    saknis = iterpti(saknis, "Kavaliauskas");
    saknis = iterpti(saknis, "Mikalauskas");

    // ---- baigiasi "is" ----
    saknis = iterpti(saknis, "Petraitis");
    saknis = iterpti(saknis, "Adomaitis");
    saknis = iterpti(saknis, "Jonaitis");
    saknis = iterpti(saknis, "Zemaitis");
    saknis = iterpti(saknis, "Noreikis");
    saknis = iterpti(saknis, "Giedraitis");
    saknis = iterpti(saknis, "Valiulis");
    saknis = iterpti(saknis, "Masiulis");
    saknis = iterpti(saknis, "Ilgauskis");
    saknis = iterpti(saknis, "Jovaisis");

    // ---- baigiasi "us" ----
    saknis = iterpti(saknis, "Butkus");
    saknis = iterpti(saknis, "Rimkus");
    saknis = iterpti(saknis, "Simkus");
    saknis = iterpti(saknis, "Mockus");
    saknis = iterpti(saknis, "Venckus");
    saknis = iterpti(saknis, "Vaitkus");

    // ---- baigiasi "os" (case 7 testavimui) ----
    saknis = iterpti(saknis, "Karvelos");
    saknis = iterpti(saknis, "Rimkos");
    saknis = iterpti(saknis, "Petronos");
    saknis = iterpti(saknis, "Daugvilos");
    saknis = iterpti(saknis, "Mazvydos");

    atnaujintiBalansus(saknis);
    return saknis;
}
medis* sabloninisSpausdinimas() {
    cout << "Pries formos balansavima:\n";
    spausdintiVizualu(saknis);
    cout << "\nPo formos balansavimo:\n";
    saknis = balansuotiForma(saknis);
    atnaujintiBalansus(saknis);
    spausdintiVizualu(saknis);
    return saknis;
}
void opcijuMeniu() {
    cout << "Pairinkite funkcija:\n";
    if (saknis == NULL) {
        cout << "0: Nutraukti programa\n"
                "1: Iterpti pavarde\n";
    }
    else {
        cout << "0: Nutraukti programa\n"
                "1: Iterpti pavarde\n"
                "2: Paieska\n"
                "3: Spausdinti\n"
                "4: Salinti\n"
                "5: Kopijuoti pavardes kurios baigiasi as i deko prieki\n"
                "6: Kopijuoti pavardes kurios baigiasi is i deko pabaiga\n"
                "7: Perkelti pavardes kurios baigiasi os i eile\n"
                "8: Spausdinti deka ir eile\n";
    }
}
void uzduotisA(medis* saknis)
{
    if (saknis == NULL) return;
    uzduotisA(saknis->kaire);
    uzduotisA(saknis->desine);
    if (pavardesPabaiga(saknis->data, "as")) {
        sarasoPriekin(saknis->data);
    }
}
void uzduotisB(medis* saknis)
{
    if (saknis == NULL) return;
    uzduotisB(saknis->kaire);
    uzduotisB(saknis->desine);
    if (pavardesPabaiga(saknis->data, "is")) {
        sarasoPabaigon(saknis->data);
    }
}
void uzduotisC1(medis* saknis, laikinasStekas*& temp)
{
    if (saknis == NULL) return;

    uzduotisC1(saknis->kaire, temp);
    uzduotisC1(saknis->desine, temp);

    if (pavardesPabaiga(saknis->data, "os")) {
        laikinasStekas* temp2 = new laikinasStekas;
        temp2->data = saknis->data;
        temp2->kitas = temp;
        temp = temp2;
    }
}
void uzduotisC()
{
    laikinasStekas* temp = NULL;
    uzduotisC1(saknis, temp);
    laikinasStekas* elem = temp;
    while (elem != NULL) {
        iSteka(elem->data);
        saknis = salinti(saknis, elem->data);
        laikinasStekas* tmp = elem;
        elem = elem->kitas;
        delete tmp;
    }
    saknis = balansuotiForma(saknis);
    atnaujintiBalansus(saknis);
}
void uzduotisD() {
    cout << "\n--- DEKAS ---\n";
    spausdintiSarasa();
    cout << "\n--- EILE ---\n";
    spausdintiSteka();
}
int main() {
    int opcija;
    bool veikimas = true;
    while (veikimas == true) {
        opcijuMeniu();
        cin >> opcija;
        if (saknis == NULL) {
            switch (opcija) {
                case 0: {
                    veikimas = false;
                    break;
                }
                case 111: {
                    saknis = sabloninisIterpimas();
                    break;
                }
                case 222: {
                    saknis = sabloninisSpausdinimas();
                    break;
                }
                case 1: {
                    cout << "Iveskite pavarde iterpimui:";
                    string pavarde;
                    cin >> pavarde;
                    saknis = iterpti(saknis, pavarde);
                    atnaujintiBalansus(saknis);
                    break;
                }
                default: {
                    cout << "Tokio pasirinkimo nera!\n";
                    break;
                }
            }
        }
        else {
            switch (opcija) {
                case 0: {
                    veikimas = false;
                    break;
                }
                case 111: {
                    saknis = sabloninisIterpimas();
                    break;
                }
                case 222: {
                    sabloninisSpausdinimas();
                    break;
                }
                case 1: {
                    cout << "Iveskite pavarde iterpimui:";
                    string pavarde;
                    cin >> pavarde;
                    saknis = iterpti(saknis, pavarde);
                    atnaujintiBalansus(saknis);
                    break;
                }
                case 2: {
                    cout << "Iveskite ieskoma pavarde: ";
                    string pavarde;
                    cin >> pavarde;
                    ieskomKo(saknis, pavarde);
                    break;
                }
                case 3: {
                    spausdinti(saknis);
                    break;
                }
                case 4: {
                    cout << "Iveskite norima pasalinti pavarde: ";
                    string pavarde;
                    cin >> pavarde;
                    saknis = salinti(saknis, pavarde);
                    saknis = balansuotiForma(saknis);
                    atnaujintiBalansus(saknis);
                    cout << "Likusios pavardes:\n";
                    spausdinti(saknis);
                    break;
                }
                case 5: {
                    uzduotisA(saknis);
                    break;
                }
                case 6: {
                    uzduotisB(saknis);
                    break;
                }
                case 7: {
                    uzduotisC();
                    break;
                }
                case 8: {
                    uzduotisD();
                    break;
                }
                default: {
                    cout << "Tokio pasirinkimo nera!\n";
                    break;
                }
            }
        }
    }
    return 0;
}