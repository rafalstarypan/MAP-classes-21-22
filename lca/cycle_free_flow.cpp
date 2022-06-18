#include <bits/stdc++.h>
using namespace std;

/*
    Second Thread Codeforces Gym Contest
    Problem D Cycle Free Flow
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
const int M = 3e4+5;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

const int LOG = 20;

int n, skip, Q;
vector<PII> G[MAX_N];
int par[MAX_N], depth[MAX_N], val[MAX_N];
int ancestor[MAX_N][LOG];
int mini[MAX_N][LOG];

void dfs(int v, int p, int d, int last) {
	par[v] = p;
	depth[v] = d;
	val[v] = last;
	
	for (PII e: G[v]) {
		int to = e.first;
		int w = e.second;
		if (to == p) continue;
		
		dfs(to, v, d + 1, w);
	}
}

int findLca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	
	for (int k = LOG-1; k >= 0; k--) {
		if (depth[ancestor[a][k]] >= depth[b]) a = ancestor[a][k];
	}
	if (a == b) return a;
	
	for (int k = LOG-1; k >= 0; k--) {
		if (ancestor[a][k] != ancestor[b][k]) {
			a = ancestor[a][k];
			b = ancestor[b][k];
		}
	}
	return par[a];
}

int goUp(int v, int dist) {
	int res = inf;
	for (int k = LOG-1; k >= 0; k--) {
		if (dist & (1 << k)) {
			res = min(res, mini[v][k]);
			v = ancestor[v][k];
		}
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
		
	cin >> n >> skip;
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	
	dfs(1, 1, 0, inf);
	
	for (int x = 1; x <= n; x++) {
		ancestor[x][0] = par[x];
		mini[x][0] = val[x];
	}
	
	for (int k = 1; k < LOG; k++) {
		for (int x = 1; x <= n; x++) {
			ancestor[x][k] = ancestor[ancestor[x][k-1]][k-1];
			mini[x][k] = min(mini[x][k-1], mini[ancestor[x][k-1]][k-1]);
		}
	}
	
	cin >> Q;
	for (int qq = 0; qq < Q; qq++) {
		int u, v;
		cin >> u >> v;
		int lca = findLca(u, v);
		
		int dist = depth[u] - depth[lca];
		int ans = goUp(u, dist);
		
		//cout << "D: " << lca << " " << dist << " " << ans << '\n';
		
		dist = depth[v] - depth[lca];
		ans = min(ans, goUp(v, dist));
		
		cout << ans << '\n';
	}
	
    return 0;
}