#include <iostream>
#include <string>
using namespace std;
const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;
int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU] = {0};
    int mokiniuKiekis = 0;
    int pasirinkimas;
    while (true) {
        cout << "\nMokiniu pazymiu sistema\n";
        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti vieno mokinio pazymius\n";
        cout << "4. Keisti pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Baigti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;
    }
    return 0;
}
