#include<bits/stdc++.h>
using namespace std;

int n;
int tab[100];

/*
    10
    2 1 4 3 10 9 5 7 6 8

*/

int wysz_bin(int x) {
    int l = 0;
    int p = n-1;

    while (l < p) {
        int sr = (l + p) / 2;    //szukam najmniejszego
        //int sr = (l + p + 1) / 2;  PRZY SZUKANIU NAJWIEKSZEGO
        if (tab[sr] >= x) {
            p = sr;
        } else {
            l = sr + 1;
        }
    }

    if (tab[l] != x) return -1;     // element nie wystepuje w tablicy

    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    sort(tab, tab+n);
    //sort(vec.begin(), vec.end());

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x; cin >> x;
        cout << wysz_bin(x) << '\n';
    }


    return 0;
}