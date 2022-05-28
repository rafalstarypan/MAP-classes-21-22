#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 2e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, k;
vector<int> G[MAX_N];

int gle[MAX_N];
int sub[MAX_N];

bool comp(int a, int b) {
    int x = gle[a] - sub[a];
    int y = gle[b] - sub[b];
    return x > y;
}

void dfs(int v, int p) {
    if (p == -1) {
        gle[v] = 0;
    } else {
        gle[v] = gle[p] + 1;
    }

    for (auto to: G[v]) {
        if (to == p) continue;
        dfs(to, v);
        sub[v] += sub[to];
        sub[v]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, -1);

    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }

    sort(a.begin(), a.end(), comp);

    ll ans = 0LL;

    for (int i = 0; i < k; i++) {
        int v = a[i];
        ans += gle[v];
        ans -= sub[v];
    }

    cout << ans;

    return 0;
}