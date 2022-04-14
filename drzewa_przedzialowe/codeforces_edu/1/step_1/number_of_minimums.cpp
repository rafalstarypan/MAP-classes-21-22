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
int a[MAX_N];
PII t[2*MAX_N];

PII pull(PII a, PII b) {
    PII res = a;
    if (a.first == b.first) {
        res.second += b.second;
    } else if (b.first < a.first) {
        res = b;
    }

    return res;
}

void build() {
    for (int i = 1; i <= n; i++) {
        t[i+n-1] = make_pair(a[i], 1);
    }

    for (int i = n-1; i >= 1; i--) {
        t[i] = pull(t[2*i], t[2*i+1]);
    }
}

void update(int pos, int val) {
    int v = n + pos - 1;
    t[v] = make_pair(val, 1);
    v /= 2;

    while (v) {
        t[v] = pull(t[2*v], t[2*v+1]);
        v /= 2;
    }
}

PII query(int l, int r) {
    int vL = n + l - 1;
    int vR = n + r - 1;
    PII res = t[vL];
    if (vL != vR) res = pull(res, t[vR]);

    while (vL/2 != vR/2) {
        if (vL%2 == 0) {
            res = pull(res, t[vL+1]);
        }
        if (vR%2 == 1) {
            res = pull(res, t[vR-1]);
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
            PII ans = query(l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }




    return 0;
}
