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
        if (pasirinkimas == 1) { // Pridedamas mokinys
            if (mokiniuKiekis < MAX_MOKINIU) { //Patikrina ar mokinių kiekis nėra jau per didelis
                int kiek;
                cout<<"Iveskite mokinio varda: ";
                cin>>vardai[mokiniuKiekis];
                cout<<"Kiek pazymiu vesite? ";
                cin>>kiek;
                if (kiek > MAX_PAZYMIU) { //Jei naudotojas įveda skaičių didesni nei MAX_PAZYMIU tai jo įvestas skaičius nusistato į didžiausią galimą reikšmę
                    kiek = MAX_PAZYMIU;
                }
                for (int j = 0; j < kiek; j++) {
                    cout << "Iveskite " << j + 1 << " pazymi: "; //Įvedami mokinio pažymiai, j+1 nes masyvas prasideda nuo 0, todėl yra +1
                    cin >> pazymiai[mokiniuKiekis][j];
                }
                mokiniuKiekis++; //Mokinių sąrašas padidėja vienu
                cout << "Mokinys pridetas.\n";
            }
            else {
                cout << "Nebegalima prideti daugiau mokiniu.\n"; //Jei per daug mokinių, pridėti daugiau nebegalima
            }
        }
        else if (pasirinkimas == 2) { // Parodo visus mokinius su jų pažymiais
            if (mokiniuKiekis == 0) { //Jei mokinių nėra, tai jų nėra 🤯
                cout << "Mokiniu nera.\n";
            } else {
                for (int i = 0; i < mokiniuKiekis; i++) { //Numeruoja mokinius
                    cout << vardai[i] << ": ";
                    for (int j = 0; j < MAX_PAZYMIU; j++) { //Surašo jų pažymius
                        if (pazymiai[i][j] != 0) { //Jeigu pažymmis lygus 0, reiškiasi jo nėra (pradžioj buvo nustatytos visos reikšmės į 0), todėl programa spausdins pažymius tik jei jie yra
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 3) { // Rodo konkretaus mokinio pažymius
            string vardas;
            bool rastas = false;
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;
            for (int i = 0; i < mokiniuKiekis; i++) {
                if (vardai[i] == vardas) { //Tikrinama, ar sąraše yra toks vardas (Turi būti įrašytas identiškai, negali skirtis nė viena raidė)
                    cout << vardai[i] << ": "; //Jei vardas surastas, jis spausdinamas
                    for (int j = 0; j < MAX_PAZYMIU; j++) {
                        if (pazymiai[i][j] != 0) { // i tas pats, koks ir vardo, todėl dabar spausdinami tiktais pažymiai
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                    rastas = true;
                }
            }
            if (!rastas) { //Mokinys nesurastas
                cout << "Mokinys nerastas.\n";
            }
        }
        else if (pasirinkimas == 4) { //Keičiamas konkretaus mokinio pažymis
            string vardas;
            int nr, naujas;
            bool rastas = false;
            cout << "Iveskite mokinio varda: ";
            cin >> vardas;
            for (int i= 0; i<mokiniuKiekis;i++) {
                if (vardai[i] == vardas) { //Tikrinamas mokinys
                    cout << "Kelinta pazymi norite pakeisti? (1-10): ";
                    cin >> nr; //Kelintas pažymis bus keičiamas
                    if (nr >= 1 && nr <= 10 && pazymiai[i][nr - 1] != 0) { //Tikrina, ar yra toks pažymis
                        cout << "Iveskite nauja pazymi: ";
                        cin >> naujas;
                        pazymiai[i][nr - 1] = naujas; //Pakeičia pažymį
                        cout << "Pazymys pakeistas.\n";
                    } else {
                        cout << "Toks pazymys neegzistuoja.\n";
                    }
                    rastas = true;
                }
            }
            if (!rastas) {
                cout << "Mokinys nerastas.\n";
            }
        }
        else if (pasirinkimas == 5) { //Šalinamas mokinys
            string vardas;
            bool rastas = false;
            cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
            cin >> vardas;
            for (int i = 0; i <mokiniuKiekis; i++) {
                if (vardai[i] == vardas) {
                    for (int k = i; k < mokiniuKiekis - 1; k++) {
                        vardai[k] = vardai[k + 1]; //Vardas nustumumiamas į prieky
                        for (int j = 0; j < MAX_PAZYMIU; j++) {
                            pazymiai[k][j] = pazymiai[k + 1][j]; //Pažymiai nustumiami į prieky kartu su vardu
                        }
                    }
                    mokiniuKiekis--;
                    cout << "Mokinys pasalintas.\n";
                    rastas = true;
                    break;
                }
            }
            if (!rastas) {
                cout << "Mokinys nerastas.\n";
            }
        }
        else if (pasirinkimas == 0) { //Uždaryti programą
            cout << "Programa baigta.\n";
            break;
        }
        else {
            cout << "Neteisingas pasirinkimas.\n";
        }
    }
    return 0;
}
