#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const ll MOD = 1000000007LL;
const int MAX_N = 2e5+5;
const int inf = 1e9;
const ll INF = (ll)(1e18);

const int ZIEMIA = -2;

int n, m;
int lapki[MAX_N][3];
int rem[2*MAX_N][3];
int ans[MAX_N];
vector<int> G[MAX_N];

void dfs(int v, int t) {
	if (ans[v] != ZIEMIA) return;
	ans[v] = t;
	for (auto to: G[v]) {
		dfs(to, t);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
		cin >> lapki[i][1] >> lapki[i][2];
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		rem[i][0] = lapki[u][v];
		rem[i][1] = u;
		lapki[u][v] = -1;
	}
	
	for (int i = 1; i <= n; i++) {
		ans[i] = ZIEMIA;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 3; j++) {
			if (lapki[i][j] != -1) {
				G[lapki[i][j]].push_back(i);
				G[i].push_back(lapki[i][j]);
			}
		}
	}
	
	dfs(1, -1);
	
	for (int i = m-1; i >= 0; i--) {
		int u = rem[i][0];
		int v = rem[i][1];
		if (ans[u] == ZIEMIA && ans[v] != ZIEMIA) {
			dfs(u, i);
		} else if (ans[v] == ZIEMIA && ans[u] != ZIEMIA) {
			dfs(v, i);
		}
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;

}
