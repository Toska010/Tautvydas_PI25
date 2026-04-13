/*
Sukurti dvejetainį medį, kurio elementai būtų asmenų pavardės (simbolių eilutės). Realizuoti
įterpimo, paieškos, spausdinimo ir šalinimo operacijas bei atlikti šiuos veiksmus:
a. Visas pavardes iš medžio, kurios baigiasi „as“, įrašyti į deką, realizuotą kaip sąrašas, į
pradžią.
b. Visas pavardes iš medžio, kurios baigiasi „is“, įrašyti į tą patį deką, bet į pabaigą.
c. Pašalinti iš medžio visas pavardes, kurios baigiasi „os“, įrašant jas į eilę, realizuotą
kaip sąrašas.
d. Spausdinti deką ir eile
*/
/*
Kiekvienoje programoje reikia atlikti 5 užduotis (pradinė užduotis ir pažymėtas:
a), b) c) ir d)).
Pradinė užduotis, a) ir b) vertinama 2 balais, o c) ir d) 1 balu. Viso 8 balai.
Programoje turi būti naudojamos funkcijos ir „draugiškas“ vartotojo interfeisas (pvz. meniu).
Vartotojo interfeisas gali būti vertinamas ir turės įtakos pažymiui (jei interfeiso nėra,
tai vertinamos dalys nebus vertinamos maksimaliu balu). Jie interfeisas bus labai geras,
tai gali būti, kad prie galutinio pažymio bus pridėtas vienas balas.
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Medis {
  int key;
  struct Medis *Kaire;
  struct Medis *Desine;
  int dydis;
};



int RastiDydi(struct Medis *N) {
  if (N == NULL)
    return 0;
  return N->dydis;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

struct Medis *NaujasElementas(int key) {
   Medis *Medis1= new Medis;
  Medis1->key = key;
  Medis1->Kaire = NULL;
  Medis1->Desine = NULL;
  Medis1->dydis = 1;
  return (Medis1);
}


struct Medis *DesinePosukis(struct Medis *y) {
  struct Medis *x = y->Kaire;
  struct Medis *T2 = x->Desine;

  x->Desine = y;
  y->Kaire = T2;

  y->dydis = max(RastiDydi(y->Kaire), RastiDydi(y->Desine)) + 1;
  x->dydis = max(RastiDydi(x->Kaire), RastiDydi(x->Desine)) + 1;

  return x;
}

// Kaire rotate
struct Medis *KairePosukis(struct Medis *x) {
  struct Medis *y = x->Desine;
  struct Medis *T2 = y->Kaire;

  y->Kaire = x;
  x->Desine = T2;

  x->dydis = max(RastiDydi(x->Kaire), RastiDydi(x->Desine)) + 1;
  y->dydis = max(RastiDydi(y->Kaire), RastiDydi(y->Desine)) + 1;

  return y;
}

// Get the balance factor
int BalansinisKoef(struct Medis *N) {
  if (N == NULL)
    return 0;
  return RastiDydi(N->Kaire) - RastiDydi(N->Desine);
}

// Insert Medis
struct Medis *IterptiElementa(struct Medis *Medis, int key) {
  // Find the correct position to IterptiElementa the Medis and IterptiElementa it
  if (Medis == NULL)
    return (NaujasElementas(key));
  Medis->Kaire = IterptiElementa(Medis->Kaire, key);

  // Update the balance factor of each Medis and
  // Balance the tree
  Medis->dydis = 1 + max(RastiDydi(Medis->Kaire),
               RastiDydi(Medis->Desine));

  int Balansas = BalansinisKoef(Medis);
  if (Balansas > 1 && key < Medis->Kaire->key)
    return DesinePosukis(Medis);

  if (Balansas < -1 && key > Medis->Desine->key)
    return KairePosukis(Medis);

  if (Balansas > 1 && key > Medis->Kaire->key) {
    Medis->Kaire = KairePosukis(Medis->Kaire);
    return DesinePosukis(Medis);
  }

  if (Balansas < -1 && key < Medis->Desine->key) {
    Medis->Desine = DesinePosukis(Medis->Desine);
    return KairePosukis(Medis);
  }

  return Medis;
}

struct Medis *Minimumas(struct Medis *Medis) {
  struct Medis *current = Medis;

  while (current->Kaire != NULL)
    current = current->Kaire;

  return current;
}

// Delete a Mediss
struct Medis *deleteMedis(struct Medis *root, int key) {
  // Find the Medis and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->Kaire = deleteMedis(root->Kaire, key);

  else if (key > root->key)
    root->Desine = deleteMedis(root->Desine, key);

  else {
    if ((root->Kaire == NULL) || (root->Desine == NULL)) {
      struct Medis *temp = root->Kaire ? root->Kaire : root->Desine;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Medis *temp = Minimumas(root->Desine);

      root->key = temp->key;

      root->Desine = deleteMedis(root->Desine, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the Balansas factor of each Medis and
  // Balansas the tree
  root->dydis = 1 + max(RastiDydi(root->Kaire),
               RastiDydi(root->Desine));

  int Balansas = BalansinisKoef(root);
  if (Balansas > 1 && BalansinisKoef(root->Kaire) >= 0)
    return DesinePosukis(root);

  if (Balansas > 1 && BalansinisKoef(root->Kaire) < 0) {
    root->Kaire = KairePosukis(root->Kaire);
    return DesinePosukis(root);
  }

  if (Balansas < -1 && BalansinisKoef(root->Desine) <= 0)
    return KairePosukis(root);

  if (Balansas < -1 && BalansinisKoef(root->Desine) > 0) {
    root->Desine = DesinePosukis(root->Desine);
    return KairePosukis(root);
  }

  return root;
}

// Print the tree
void Spausdinti(struct Medis *root) {
  if (root != NULL) {

    Spausdinti(root->Kaire);
     printf("%d ", root->key);
    Spausdinti(root->Desine);
  }
}

/*
void pasirinkimai() {
    cout << "Pasirinkite funkcija:\n"
            "0: Nutraukti programa\n"
            "1: Ivesti pavarde\n"
            "2: Paieska\n"
            "3: Spasudinti duomenis (medzio)\n"
            "4: Salinti pavarde\n"
            "5: Perkelti pavardes kurios baigiasi (as) i deka\n"
            "6: Perkelti pavardes kurios baigiasi (is) i deka\n"
            "7: Pasalinti pavardes kurios baigiasi (os) perkeliant jas i eile\n"
            "8: Spausdinti deka ir eile" << endl;
}
*/
int main()
{
    struct Medis *root = NULL;

    root = IterptiElementa(root, 2);
    root = IterptiElementa(root, 1);
    root = IterptiElementa(root, 7);
    root = IterptiElementa(root, 4);
    root = IterptiElementa(root, 5);
    root = IterptiElementa(root, 3);
    root = IterptiElementa(root, 8);

    Spausdinti(root);

    root = deleteMedis(root, 3);

    printf("\nPo pasalinimo ");
    Spausdinti(root);

    return 0;
}
