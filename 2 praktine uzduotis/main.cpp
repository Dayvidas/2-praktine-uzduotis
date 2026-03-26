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
        if (pasirinkimas == 1) {
            if (mokiniuKiekis < MAX_MOKINIU) {
                int kiek;
                cout<<"Iveskite mokinio varda: ";
                cin>>vardai[mokiniuKiekis];
                cout<<"Kiek pazymiu vesite? ";
                cin>>kiek;
                if (kiek > MAX_PAZYMIU) {
                    kiek = MAX_PAZYMIU;
                }
                for (int j = 0; j < kiek; j++) {
                    cout << "Iveskite " << j + 1 << " pazymi: ";
                    cin >> pazymiai[mokiniuKiekis][j];
                }
                mokiniuKiekis++;
                cout << "Mokinys pridetas.\n";
            }
            else {
                cout << "Nebegalima prideti daugiau mokiniu.\n";
            }
        }
        else if (pasirinkimas == 2) {
            if (mokiniuKiekis == 0) {
                cout << "Mokiniu nera.\n";
            } else {
                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << vardai[i] << ": ";
                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        if (pazymiai[i][j] != 0) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 3) {
            string vardas;
            bool rastas = false;
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;
            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    cout << vardai[i] << ": ";
                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        if (pazymiai[i][j] != 0) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                    rastas = true;
                }
            }
            if (!rastas) {
                cout << "Mokinys nerastas.\n";
            }
        }
    }
    return 0;
}
