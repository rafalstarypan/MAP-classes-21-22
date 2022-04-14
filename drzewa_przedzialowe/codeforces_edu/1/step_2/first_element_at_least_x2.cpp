#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n, Q;
int a[MAX_N];
int t[4*MAX_N];

int pull(int x, int y) {
	return max(x, y);
}

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	
	build(2*v, l, mid);
	build(2*v+1, mid + 1, r);
	
	t[v] = pull(t[2*v], t[2*v+1]);
}

void update(int v, int l, int r, int pos, int val) {
	if (l > pos || r < pos) return;
	if (l == pos && r == pos) {
		t[v] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(2*v, l, mid, pos, val);
	update(2*v+1, mid + 1, r, pos, val);
	
	t[v] = pull(t[2*v], t[2*v+1]);
}

int query(int v, int l, int r, int x, int start) {
	if (t[v] < x) return inf;
	if (l == r) return l;
	int mid = (l + r) / 2;
	int res = inf;
	
	if (t[2*v] >= x && mid >= start) {
		res = query(2*v, l, mid, x, start);
	} 
	
	if (res == inf) {
		res = query(2*v+1, mid+1, r, x, start);
	}
	
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	
	for (int q = 0; q < Q; q++) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos, val; 
			cin >> pos >> val;
			pos++;
			update(1, 1, n, pos, val);
		} else {
			int k, l;
			cin >> k >> l;
			l++;
			int ans = query(1, 1, n, k, l) - 1;
			if (ans == inf-1) ans = -1;
			cout << ans << '\n';
		}
	}
	
    return 0;
}
