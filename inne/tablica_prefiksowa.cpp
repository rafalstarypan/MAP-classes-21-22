#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+5;
int n;
int a[MAX_N];
int pref[MAX_N], suff[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    pref[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pref[i] = max(pref[i - 1], a[i], 5);
        /*pref[i] = pref[i - 1];
        if (a[i] > pref[i]) {
            pref[i] = a[i];
        }*/
    }

    suff[n] = a[n];
    for (int i = n-1; i >= 1; i--) {
        suff[i] = max(suff[i + 1], a[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << pref[i] << ' ' << suff[i] << '\n';
    }

    return 0;
}