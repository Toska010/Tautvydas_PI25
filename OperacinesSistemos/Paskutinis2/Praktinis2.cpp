#include <iostream>
using namespace std;

struct sarasas {
    int data;
    sarasas *next;
};

sarasas *head = nullptr;

// Insert at end
void insertElement(int x) {
    sarasas *el = new sarasas;
    el->data = x;
    el->next = nullptr;

    if (!head) {
        head = el;
        return;
    }

    sarasas *p = head;
    while (p->next) p = p->next;
    p->next = el;
}

void deleteElement(int x) {
    if (!head) return;

    if (head->data == x) {
        sarasas *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    sarasas *p = head;
    while (p->next && p->next->data != x)
        p = p->next;

    if (p->next) {
        sarasas *tmp = p->next;
        p->next = tmp->next;
        delete tmp;
    }
}

bool searchElement(int x) {
    sarasas *p = head;
    while (p) {
        if (p->data == x) return true;
        p = p->next;
    }
    return false;
}

void printList() {
    sarasas *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

struct medis {
    int data;
    medis *left, *right;
};

medis *root = nullptr;

medis* insertTree(medis *r, int x) {
    if (!r) {
        r = new medis;
        r->data = x;
        r->left = r->right = nullptr;
        return r;
    }
    if (x < r->data) r->left = insertTree(r->left, x);
    else r->right = insertTree(r->right, x);
    return r;
}

void listToTree() {
    sarasas *p = head;
    sarasas *lag = p;
    while (p) {
        root = insertTree(root, p->data);
        p = p->next;
    }
}

void printTree(medis *r) {
    if (!r) return;
    printTree(r->left);
    cout << r->data << " ";
    printTree(r->right);
}

int main() {
    int choice, x;

    while (true) {
        cout << "\n1 - Iterpti\n2 - Pasalinti\n3 - Spausdinti sarasa\n4 - Ieskoti\n5 - Perkelti i medi\n6 - Spausdinti medi\n0 - Baigti\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Iveskite skaiciu: ";
                cin >> x;
                insertElement(x);
                break;

            case 2:
                cout << "Kuri skaiciu pasalinti: ";
                cin >> x;
                deleteElement(x);
                break;

            case 3:
                printList();
                break;

            case 4:
                cout << "Iveskite ieskoma skaiciu: ";
                cin >> x;
                cout << (searchElement(x) ? "Rastas" : "Nerastas") << endl;
                break;

            case 5:
                listToTree();
                cout << "Perkelta." << endl;
                break;

            case 6:
                printTree(root);
                cout << endl;
                break;

            case 0:
                return 0;
        }
    }
}
