#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+5;

int n;
int pierwszy_dzielnik[MAX_N];

/*
    Funkcja rozklada liczby rzędu 1e6 w czasie O(log x),
    co pozwala odpowiadac na wiele zapytan
*/
vector<int> znajdz_rozklad(int x) {
    vector<int> wyn;
    while (pierwszy_dzielnik[x] != 0) {
        wyn.push_back(pierwszy_dzielnik[x]);
        x /= pierwszy_dzielnik[x];
    }
    wyn.push_back(x);

    sort(wyn.begin(), wyn.end());
    return wyn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i*i <= MAX_N; i++) {
        if (pierwszy_dzielnik[i] == 0) {
            for (int j = i*i; j < MAX_N; j += i) {
                pierwszy_dzielnik[j] = i;
            }
        }
    }


    return 0;
}