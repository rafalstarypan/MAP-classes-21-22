#include <bits/stdc++.h>
using namespace std;

// 1: 6
// 2: 5
// 3: 5
// 4: 3
// 5: 2
// 6: 1
// 7: 4
// 8: 6
// 9: 6
// 10: 6

const int MAX_N = 1e4+5;

int n, m;
vector<int> G[MAX_N], revG[MAX_N];
bool vis[MAX_N];

vector<int> my_stack;  // back()  pop_back()
int which_scc[MAX_N];
int current_scc = 1;
int scc_sizes[MAX_N];

void dfs1(int v) {
    vis[v] = true;
    for (int to: G[v]) {
        if (!vis[to]) {
            dfs1(to);
        }
    }
    my_stack.push_back(v);
}

void dfs2(int v) {
    which_scc[v] = current_scc;
    for (int to: revG[v]) {
        if (which_scc[to] == 0) {
            dfs2(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        revG[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    /*for (int x: my_stack) {
        cout << x << '\n';
    } */

    while (!my_stack.empty()) {
        int v = my_stack.back();
        my_stack.pop_back();
        if (!which_scc[v]) {
            dfs2(v);
            current_scc++;
        }
    }

    for (int i = 1; i <= n; i++) {
        scc_sizes[ which_scc[i] ]++;
    }

    while (true) {
        int x; cin >> x;
        if (x == 0) break;
        cout << scc_sizes[ which_scc[x] ] << '\n';
    }

    return 0;
}