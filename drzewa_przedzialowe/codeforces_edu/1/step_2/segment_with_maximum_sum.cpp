#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<int, ll> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

struct Node {
    ll sum;
    ll pref;
    ll suff;
    ll best;
};

int n, Q;
ll a[MAX_N];
int leaves;
Node t[4*MAX_N];

void print(Node x) {
    cout << x.sum << " " << x.pref << " " << x.suff << " " << x.best << "\n";
}

void printAns() {
    ll ans = max(0LL, t[1].best);
    cout << ans << "\n";
}

Node pull(Node a, Node b) {
    ll newSum = a.sum + b.sum;
    ll newPref = max(a.pref, a.sum + b.pref);
    ll newSuff = max(b.suff, b.sum + a.suff);
    ll newBest = max({a.best, b.best, a.suff + b.pref, newSum});

    Node res = {newSum, newPref, newSuff, newBest};
    return res;
}

void build() {
    leaves = 1;
    while (leaves < n) {
        leaves *= 2;
    }

    for (int i = 1; i <= n; i++) {
        t[i+leaves-1] = {a[i], a[i], a[i], a[i]};
    }

    for (int i = leaves-1; i >= 1; i--) {
        t[i] = pull(t[2*i], t[2*i+1]);
    }
}

void update(int pos, ll val) {
    int v = leaves + pos - 1;
    t[v] = {val, val, val, val};
    v /= 2;

    while (v) {
        t[v] = pull(t[2*v], t[2*v+1]);
        v /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build();

    printAns();

    for (int q = 0; q < Q; q++) {
        int pos; ll val;
        cin >> pos >> val;
        pos++;
        update(pos, val);
        printAns();
    }

    return 0;
}
