#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 5e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n, m;
vector<int> G[MAX_N];
int curH = 1;
int h[MAX_N], needed[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for (int i = 3; i <= n; i++) {
		if (G[i].empty()) {
			h[i] = curH;
			curH++;
		}
		needed[i] = G[i].size() / 2;
	}
	
	h[2] = n;
	
	queue<int> Q;
	Q.push(1);
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		if (needed[v] != 0) {
			cout << "NIE\n";
			return 0;
		}
		h[v] = curH;
		curH++;
		
		for (int to: G[v]) {
			needed[to]--;
			if (needed[to] < 0 && h[to] == 0) {
				cout << "NIE\n";
				return 0;
			}
			if (needed[to] == 0 && h[to] == 0) {
				Q.push(to);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (h[i] == 0) {
			cout << "NIE\n";
			return 0;
		}
	}
	
	cout << "TAK\n";
	for (int i = 1; i <= n; i++) {
		cout << h[i] << ' ';
	}
	cout << '\n';
	
    return 0;
}