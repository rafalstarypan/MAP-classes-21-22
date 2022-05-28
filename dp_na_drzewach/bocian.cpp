#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1e5+5;

int n;
ll a[MAX_N];
ll dp[MAX_N][2];
vector<int> G[MAX_N];

void dfs(int v, int p) {
	dp[v][0] = 0LL;
	dp[v][1] = a[v];
	
	ll allTaken = 0LL;
	ll allUntaken = 0LL;
	
	for (int to: G[v]) {
		if (to == p) continue;
		dfs(to, v);
		
		allTaken += dp[to][1];
		allUntaken += min(dp[to][0], dp[to][1]);
	}
	
	dp[v][0] += allTaken;
	dp[v][1] += allUntaken;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	
	while (T--) {
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			G[i].clear();
			cin >> a[i];
		}
	
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		dfs(1, -1);
		
		cout << min(dp[1][0], dp[1][1]) << '\n';
	}
	
	return 0;
}