#include <iostream>


using namespace std;

int a, b, c, d, e;
void Pirmas() {
    cout << "Ivesk tris skaicius" << endl;
    cin >> a >> b >> c;
    if (a < b) {
        if (a < c){
            {
                cout << a << " maziausias" << endl;
            }
        }
    }
    else if (b < a && b < c) {
        cout << b << " maziausias" << endl;
    }
    else cout << c << " maziausias" << endl;
}
void Antras() {
    cout << "Ivesk sveika skaiciu" << endl;
    cin >> a;
    b = 1;
    int i = 1;
    if (a >= 1) {
        while (i < a) {
            b=b*i+b;
            i++;
        }
    } else {cout << "Netinkamas skaicius" << endl;}
    cout << b << endl;
}
void Trecias() {
    cout << "Ivesk penkis skaicius" << endl;
    cin >> a >> b >> c >> d >> e;
    int z = (a+b+c+d+e)/5;
    cout << z << endl;
    if (a > b && a > c && a > d && a > e) { cout << a << endl; }
    else if (b > a && b > c && b > d && b > e) { cout << b << endl; }
    else if (c > a && c > b && c > d && c > e) { cout << c << endl; }
    else if (d > a && d > b && d > c && d > e) { cout << d << endl; }
    else { cout << e << endl; }
}

int main() {
    Pirmas();
    //Antras();
    //Trecias();
    return 0;
}
