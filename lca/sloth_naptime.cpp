#include <bits/stdc++.h>
using namespace std;

/*
    Second Thread Codeforces Gym Contest
    Problem C Sloth Naptime
    Contest Link: https://codeforces.com/gym/102694
    Video Solutions Link: https://www.youtube.com/watch?v=5ZZELkqmGOo
    Second Thread Lecture: https://www.youtube.com/watch?v=MOy4UDjN8DM  
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 3e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, Q;
vector<int> G[MAX_N];
int depth[MAX_N], par[MAX_N];
int ancestor[MAX_N][21];

void dfs(int v, int p, int d) {
    par[v] = p;
    depth[v] = d;
    for (int to: G[v]) {
        if (to == p) continue;
        dfs(to, v, d + 1);
    }
}

int findLca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    for (int k = 20; k >= 0; k--) {
        if (depth[ancestor[b][k]] >= depth[a]) b = ancestor[b][k];
    }

    if (a == b) return a;

    for (int k = 20; k >= 0; k--) {
        if (ancestor[a][k] != ancestor[b][k]) {
            a = ancestor[a][k];
            b = ancestor[b][k];
        }
    }

    return par[a];
}

int dist(int u, int v) {
    int lca = findLca(u, v);
    return depth[u] + depth[v] - 2*depth[lca];
}

int query(int v, int len) {
    for (int k = 20; k >= 0; k--) {
        if (len & (1 << k)) {
            v = ancestor[v][k];
        }
    }
    return v;
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

    dfs(1, -1, 0);

    ancestor[1][0] = 1;
    par[1] = 1;
    for (int i = 2; i <= n; i++) {
        ancestor[i][0] = par[i];
    }
    for (int k = 1; k <= 20; k++) {
        for (int x = 1; x <= n; x++) {
            ancestor[x][k] = ancestor[ancestor[x][k-1]][k-1];
        }
    }

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = dist(a, b);
        int lca = findLca(a, b);
        int toLca = depth[a] - depth[lca];
        if (d <= c) {
            cout << b << "\n";
            continue;
        }
        int goUp = a;
        if (c > toLca) {
            goUp = b;
            d = depth[b] - depth[lca];
            c = d - c + toLca;
        }
        cout << query(goUp, c) << "\n";
    }

    return 0;
}