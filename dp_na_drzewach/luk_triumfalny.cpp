#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 3e5+5;
const ll MOD = (ll)(1e9+7);
const ll INF = (ll) (1e18);
const int inf = 1e9;

int n;
int dp[MAX_N];
vector<int> G[MAX_N];

void dfs(int node, int parent, int k) {
    if (G[node].size()==1 && parent!=-1) {
        dp[node] = 0;
        return;
    }
    int subTrees = 0;
    for (auto adj: G[node]) {
        if (adj == parent) continue;
        dfs(adj, node, k);
        subTrees += dp[adj] + 1;
    }
    dp[node] = max(subTrees-k, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int left = 0;
    int right = n;

    while (left < right) {
        int mid = (left+right) / 2;
        dfs(1, -1, mid);

        if (dp[1] == 0) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

    cout << left;

    return 0;
}
