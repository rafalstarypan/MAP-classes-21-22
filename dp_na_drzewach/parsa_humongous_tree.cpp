#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 3e4+5;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n;
vector<int> G[MAX_N];
ll l[MAX_N], r[MAX_N];
ll dp[MAX_N][2];

void dfs(int v, int p) {
	for (int to: G[v]) {
		if (to == p) continue;
		dfs(to, v);
		dp[v][0] += max(dp[to][0] + abs(l[to] - l[v]), dp[to][1] + abs(r[to] - l[v]));
		dp[v][1] += max(dp[to][0] + abs(l[to] - r[v]), dp[to][1] + abs(r[to] - r[v]));
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		G[i].clear();
		cin >> l[i] >> r[i];
		dp[i][0] = dp[i][1] = 0LL;
	}
	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1);
	
	cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
		
	int T; cin >> T;
	while (T--) {
		solve();
	}		
	
	
    return 0;
}