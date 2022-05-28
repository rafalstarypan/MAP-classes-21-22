#include <bits/stdc++.h>
using namespace std;

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

struct Edge {
    int id;
    int u;
    int v;
    int w;
};

bool comp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int n, m;
Edge edges[MAX_N];
int par[7005], sizes[7005];
bool ans[MAX_N];

int doFind(int v) {
    int root = v;
    while (par[root] != root) root = par[root];

    while (v != root) {
        int nxt = par[v];
        par[v] = root;
        v = nxt;
    }

    return root;
}

void doUnion(int u, int v) {
    int p1 = doFind(u);
    int p2 = doFind(v);
    if (p1 == p2) return;

    if (sizes[p1] < sizes[p2]) {
        swap(p1, p2);
    }

    sizes[p1] += sizes[p2];
    par[p2] = p1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 0; i < m; i++) {
        edges[i].id = i;
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges+m, comp);

    int i = 0;
    while (i < m) {
        int curCost = edges[i].w;
        int j = i;
        while (j < m && edges[j].w == curCost) j++;

        for (int k = i; k < j; k++) {
            int u = edges[k].u;
            int v = edges[k].v;
            int id = edges[k].id;
            int p1 = doFind(u);
            int p2 = doFind(v);
            ans[id] = (p1 != p2);
        }

        for (int k = i; k < j; k++) {
            int u = edges[k].u;
            int v = edges[k].v;
            doUnion(u, v);
        }

        i = j;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i]) cout << "TAK\n";
        else cout << "NIE\n";
    }


    return 0;
}
