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

int n, Q;
int a[MAX_N];

const int LOG = 17;
const int BASE = (1 << LOG);
bitset<42> tree[2*BASE+5];

void build() {
	for (int i = 1; i <= n; i++) {
		tree[i + BASE - 1][a[i]] = true;
	}
	for (int i = BASE-1; i >= 1; i--) {
		tree[i] = (tree[2*i] | tree[2*i+1]);
	}
}

void update(int pos, int val) {
	pos += BASE - 1;
	tree[pos].reset();
	tree[pos][val] = true;
	pos /= 2;
	while (pos) {
		tree[pos] = (tree[2*pos] | tree[2*pos+1]);
		pos /= 2;
	}
}

bitset<42> query(int l, int r) {
	bitset<42> res;
	l += BASE - 2;
	r += BASE;
	while (r-l > 1) {
		if (l%2 == 0) res |= tree[l+1];
		if (r%2 == 1) res |= tree[r-1];
		l /= 2; r /= 2;
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
	
	build();
	
	for (int qq = 0; qq < Q; qq++) {
		int type; cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << query(l, r).count() << '\n';
		} else {
			int pos, val;
			cin >> pos >> val;
			update(pos, val);
		}
	}
	
    return 0;
}
