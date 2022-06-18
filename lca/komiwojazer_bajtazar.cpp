#include <bits/stdc++.h>
using namespace std;

/*
    Proste zadanie na LCA:
    Komiwojazer Bajtazar IX OI
    Artykul Meetit: https://platform.meetit.pl/articles/gra_lca
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<int, ll> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 30005;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, m;
vector<int> G[MAX_N];
vector<int> cities;
int par[MAX_N], gle[MAX_N];
int ancestor[MAX_N][19];

void dfs(int v, int p) {
    par[v] = p;
    if (p == -1) gle[v] = 0;
    else gle[v] = gle[p] + 1;
    for (auto to: G[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
}

int findLca(int a, int b) {
    if (gle[b] < gle[a]) swap(a, b);

    for (int k = 17; k >= 0; k--) {
        if (gle[ancestor[b][k]] >= gle[a]) {
            b = ancestor[b][k];
        }
    }
    if (a == b) return a;

    for (int k = 17; k >= 0; k--) {
        if (ancestor[a][k] != ancestor[b][k]) {
            a = ancestor[a][k];
            b = ancestor[b][k];
        }
    }

    return par[a];
}

int getDist(int u, int v, int lca) {
    return gle[u] + gle[v] - 2*gle[lca];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> m;
    cities.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> cities[i];
    }

    dfs(1, -1);

    ancestor[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        ancestor[i][0] = par[i];
    }

    for (int k = 1; k <= 17; k++) {
        for (int x = 1; x <= n; x++) {
            ancestor[x][k] = ancestor[ancestor[x][k - 1]][k - 1];
        }
    }

    int curCity = 1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int nxt = cities[i];
        int lca = findLca(curCity, nxt);
        int tmp = getDist(curCity, nxt, lca);
        //cout << lca << " " << tmp << "\n";
        ans += tmp;
        curCity = nxt;
    }

    cout << ans << "\n";

    return 0;
}
