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
int a[2*MAX_N];
int L[MAX_N], R[MAX_N], ans[MAX_N];
vector<PII> inter;

const int LOG = 18;
const int BASE = (1 << LOG);
int tree[2*BASE+5];

void update(int pos, int val) {
	pos += BASE - 1;
	tree[pos] += val;
	pos /= 2;
	while (pos) {
		tree[pos] = tree[2*pos] + tree[2*pos+1];
		pos /= 2;
	}
}

int query(int l, int r) {
	l += BASE - 2;
	r += BASE;
	int res = 0;
	while (r-l > 1) {
		if (l%2 == 0) res += tree[l+1];
		if (r%2 == 1) res += tree[r-1];
		l /= 2; r /= 2;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= 2*n; i++) {
		cin >> a[i];
		if (L[a[i]] == 0) {
			L[a[i]] = i;
		} else {
			R[a[i]] = i;
			inter.emplace_back(L[a[i]], R[a[i]]);
		}
	}
	
	sort(inter.rbegin(), inter.rend());
	
	for (int i = 0; i < n; i++) {
		int l = inter[i].first;
		int r = inter[i].second;
		int who = a[l];
		ans[who] = query(l, r);
		update(r, 1);
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	
	
    return 0;
}
