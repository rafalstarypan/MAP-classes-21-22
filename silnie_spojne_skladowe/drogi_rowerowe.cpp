#include <bits/stdc++.h>
using namespace std;

/*
    Drogi rowerowe XXV OI
    DP na grafie silnie spojnych skladowych
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<int, ll> PILL;
typedef pair<ll, int> PLI;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, m;
vector<int> G[MAX_N], revG[MAX_N];
vector<int> sccGraph[MAX_N];
int curSize = 0; 
int curScc = 0;
int whichScc[MAX_N], dp[MAX_N], inDeg[MAX_N];
bool vis[MAX_N];
vector<int> st;

void dfs1(int v) {
	vis[v] = true;
	for (int to: G[v]) {
		if (vis[to]) continue;
		dfs1(to);
	}
	st.push_back(v);
}

void dfs2(int v) {
	vis[v] = true;
	whichScc[v] = curScc;
	curSize++;
	for (int to: revG[v]) {
		if (vis[to]) continue;
		dfs2(to);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		revG[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
	}
	
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		if (vis[v]) continue;
		curScc++;
		curSize = 0;
		dfs2(v);
		dp[curScc] = curSize;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int to: G[i]) {
			int myScc = whichScc[i];
			int yourScc = whichScc[to];
			if (myScc == yourScc) continue;
			
			sccGraph[yourScc].push_back(myScc);
			inDeg[myScc]++;
		}
	}
	
	queue<int> Q;
	for (int i = 1; i <= curScc; i++) {
		if (inDeg[i] == 0) {
			Q.push(i);
		}
	}
    
    while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (int to: sccGraph[v]) {
			inDeg[to]--;
			dp[to] += dp[v];
			if (inDeg[to] == 0) {
				Q.push(to);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int myScc = whichScc[i];
		cout << dp[myScc] - 1 << '\n';
	}
    
    return 0;
}
