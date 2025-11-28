#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void skaitytiFaila() {
    ifstream Meniu;
    Meniu.open("Meniu.txt");
    while(!Meniu.eof()) {

    }
    Meniu.close();
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
