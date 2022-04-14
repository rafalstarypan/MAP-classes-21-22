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
int a[MAX_N];

const int LOG = 17;
const int BASE = (1 << LOG);
int tree[2*BASE+5];

void build() {
	for (int i = 1; i <= n; i++) {
		tree[i + BASE - 1] = 1;
	}
	
	for (int i = BASE-1; i >= 1; i--) {
		tree[i] = tree[2*i] + tree[2*i+1];
	}
}

void update(int pos, int val) {
	pos += BASE - 1;
	tree[pos] = val;
	pos /= 2;
	while (pos) {
		tree[pos] = tree[2*pos] + tree[2*pos+1];
		pos /= 2;
	}
}

int query(int k) {
	int v = 1;
	while (true) {
		if (v >= BASE) return v - BASE + 1;
		if (tree[2*v+1] > k) {
			v = 2*v+1;
		} else {
			k -= tree[2*v+1];
			v *= 2;
		}
	}
	assert(false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	build();
	
	deque<int> ans;
	for (int i = n; i >= 1; i--) {
		int nxt = query(a[i]);
		//cout << "D: " << nxt << '\n';
		update(nxt, 0);
		ans.push_front(nxt);
	}
	
	for (int i: ans) {
		cout << i << ' ';
	}
	cout << '\n';
	
    return 0;
}
