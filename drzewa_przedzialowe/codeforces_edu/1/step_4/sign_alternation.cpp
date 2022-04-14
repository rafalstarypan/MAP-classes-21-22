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

// Odd Segment Tree
int oddTree[2*BASE+5];

void buildOdd() {
	for (int i = 1; i <= n; i++) {
		if (i%2) {
			oddTree[i + BASE - 1] = a[i];
		}
	}
	for (int i = BASE-1; i >= 1; i--) {
		oddTree[i] = oddTree[2*i] + oddTree[2*i+1];
	}
}

void updateOdd(int pos, int val) {
	pos += BASE - 1;
	oddTree[pos] = val;
	pos /= 2;
	while (pos) {
		oddTree[pos] = oddTree[2*pos] + oddTree[2*pos+1];
		pos /= 2;
	}
}

int queryOdd(int l, int r) {
	l += BASE - 2;
	r += BASE;
	int res = 0;
	while (r-l > 1) {
		if (l%2 == 0) res += oddTree[l+1];
		if (r%2 == 1) res += oddTree[r-1];
		l /= 2; r /= 2;
	}
	return res;
}

// Even Segment Tree
int evenTree[2*BASE+5];

void buildEven() {
	for (int i = 1; i <= n; i++) {
		if (i%2 == 0) {
			evenTree[i + BASE - 1] = a[i];
		}
	}
	for (int i = BASE-1; i >= 1; i--) {
		evenTree[i] = evenTree[2*i] + evenTree[2*i+1];
	}
}

void updateEven(int pos, int val) {
	pos += BASE - 1;
	evenTree[pos] = val;
	pos /= 2;
	while (pos) {
		evenTree[pos] = evenTree[2*pos] + evenTree[2*pos+1];
		pos /= 2;
	}
}

int queryEven(int l, int r) {
	l += BASE - 2;
	r += BASE;
	int res = 0;
	while (r-l > 1) {
		if (l%2 == 0) res += evenTree[l+1];
		if (r%2 == 1) res += evenTree[r-1];
		l /= 2; r /= 2;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	buildOdd();
	buildEven();
	
	cin >> Q;
	for (int qq = 0; qq < Q; qq++) {
		int type; cin >> type;
		if (type == 0) {
			int pos, val;
			cin >> pos >> val;
			if (pos%2) {
				updateOdd(pos, val);
			} else {
				updateEven(pos, val);
			}
		} else {
			int l, r;
			cin >> l >> r;
			int odd = queryOdd(l, r);
			int even = queryEven(l, r);
			if (l%2) {
				cout << odd - even << '\n';
			} else {
				cout << even - odd << '\n';
			}
		}
	}
	
    return 0;
}
