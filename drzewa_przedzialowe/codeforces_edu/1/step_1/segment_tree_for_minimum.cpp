#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, Q;
ll a[MAX_N];
ll t[2*MAX_N];

void build() {
    for (int i = 1; i <= n; i++) {
        t[i+n-1] = a[i];
    }

    for (int i = n-1; i >= 1; i--) {
        t[i] = min(t[2*i], t[2*i+1]);
    }
}

void update(int pos, ll val) {
    int v = n + pos - 1;
    t[v] = val;
    v /= 2;

    while (v) {
        t[v] = min(t[2*v], t[2*v+1]);
        v /= 2;
    }
}

ll query(int l, int r) {
    int vL = n + l - 1;
    int vR = n + r - 1;
    ll res = t[vL];
    if (vL != vR) res = min(res, t[vR]);

    while (vL/2 != vR/2) {
        if (vL%2 == 0) {
            res = min(res, t[vL+1]);
        }
        if (vR%2 == 1) {
            res = min(res, t[vR-1]);
        }
        vL /= 2;
        vR /= 2;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build();

    for (int q = 0; q < Q; q++) {
        int type; cin >> type;
        if (type == 1) {
            int pos; ll val;
            cin >> pos >> val;
            pos++;
            update(pos, val);
            a[pos] = val;
        } else {
            int l, r;
            cin >> l >> r;
            l++;
            cout << query(l, r) << "\n";
        }
    }




    return 0;
}
