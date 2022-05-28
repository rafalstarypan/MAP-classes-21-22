#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int inf = 1e9;
const ll INF = (ll)(1e18);

const ll MOD = 1000000007LL;

int n, m;
ll a[5005];
ll dist[5005], dist2[5005];
vector<PILL> G[5005];
vector<PILL> revG[5005];

void dijkstra(bool which) {
    if (which) {
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            dist2[i] = INF;
        }
    }


    priority_queue<PILL, vector<PILL>, greater<PILL>> pq;
    pq.push({0LL, 1});

    while (!pq.empty()) {
        ll cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        vector<PILL> adj;
        if (which) {
            adj = G[v];
            if (dist[v] <= cost) continue;
            dist[v] = cost;
        } else {
            adj = revG[v];
            if (dist2[v] <= cost) continue;
            dist2[v] = cost;
        }

        for (PILL to: adj) {
            ll w = to.first;
            ll nxt = to.second;
            pq.push({cost+w, nxt});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] /= 2;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        G[u].push_back({c, v});
        revG[v].push_back({c, u});
    }

    dijkstra(true);
    dijkstra(false);

    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dist[i] + a[i] + dist2[i]);
    }

    cout << ans;

    return 0;
}
