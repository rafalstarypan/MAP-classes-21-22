#include<bits/stdc++.h>
using namespace std;

/* Sito Eratostenesa */

int n;
bool czy_zlozona[1000];    // domyslnie wartosci sa ustawione na false

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i = 2; i*i <= n; i++) {
        if (czy_zlozona[i] == false) {  // i jest liczba pierwsza
            for (int j = i*i; j <= n; j += i) {
                czy_zlozona[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << i << ": " << czy_zlozona[i] << "\n";
    }


    return 0;
}