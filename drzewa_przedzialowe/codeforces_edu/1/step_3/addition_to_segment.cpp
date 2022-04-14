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

const int LOG = 17;
const int BASE = (1 << LOG);
ll tree[2*BASE+5];

void update(int l, int r, ll val) {
	l += BASE - 2;
	r += BASE;
	while (r-l > 1) {
		if (l%2 == 0) tree[l+1] += val;
		if (r%2 == 1) tree[r-1] += val;
		l /= 2; r /= 2;
	}
} 

ll query(int pos) {
	pos += BASE - 1;
	ll res = 0LL;
	while (pos) {
		res += tree[pos];
		pos /= 2;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> Q;
	for (int qq = 0; qq < Q; qq++) {
		int type; cin >> type;
		if (type == 1) {
			int l, r; ll val;
			cin >> l >> r >> val;
			l++;
			update(l, r, val);
		} else {
			int pos; cin >> pos;
			pos++;
			cout << query(pos) << '\n';
		}
	}
	
    return 0;
}
