#include<bits/stdc++.h>
using namespace std;

const int WIE = 100;
const int KOL = 200;

vector<string> a(WIE);

// 1x26, 2x13, 26x1, 13x2

pair<int, int> sprawdz(int szer, int wys) {
    for (int i = 0; i + wys <= WIE; i++) {
        for (int j = 0; j + szer <= KOL; j++) {

            vector<int> zlicz(26, 0);
            for (int wiersz = i; wiersz < i + wys; wiersz++) {
                for (int kol = j; kol < j + szer; kol++) {
                    zlicz[ a[wiersz][kol]-'a' ]++;
                }
            }

            bool ok = true;
            for (int k = 0; k < 26; k++) {
                if (zlicz[k] != 1) {
                    ok = false;
                    break;
                }
            }

            if (ok == true) {
                return make_pair(i, j);
            }
        }
    }
    cout << "HI\n";
    return make_pair(-1, -1);
}

int main() {
    fstream wejscie;
    wejscie.open("wykreslanka.txt", ios::in);

    for (int i = 0; i < WIE; i++) {
        wejscie >> a[i];
    }
    wejscie.close();

    pair<int, int> wyn = sprawdz(1, 26);
    if (wyn.first != -1) {
        cout << "Szerokosc: " << 1 << '\n';
        cout << "Wysokosc: " << 26 << '\n';
        cout << wyn.first << ' ' << wyn.second << '\n';
        return 0;
    }

    wyn = sprawdz(2, 13);
    if (wyn.first != -1) {
        cout << "Szerokosc: " << 2 << '\n';
        cout << "Wysokosc: " << 13 << '\n';
        cout << wyn.first << ' ' << wyn.second << '\n';
        return 0;
    }

    wyn = sprawdz(26, 1);
    if (wyn.first != -1) {
        cout << "Szerokosc: " << 26 << '\n';
        cout << "Wysokosc: " << 1 << '\n';
        cout << wyn.first << ' ' << wyn.second << '\n';
        return 0;
    }

    wyn = sprawdz(13, 2);
    if (wyn.first != -1) {
        cout << "Szerokosc: " << 13 << '\n';
        cout << "Wysokosc: " << 2 << '\n';
        cout << wyn.first << ' ' << wyn.second << '\n';
        return 0;
    }

    return 0;
}