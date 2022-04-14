#include<bits/stdc++.h>
using namespace std;

/*
8 7
1 2
2 3
2 4
1 5
5 6
6 7
7 8
*/

int n, m;
vector<int> G[100];

bool odw[100];

void dfs(int v) {
    cout << v << '\n';
    odw[v] = true;

    for (int i = 0; i < G[v].size(); i++) {
        if (odw[ G[v][i] ] == false) {
            dfs(G[v][i]);
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
        G[b].push_back(a);
    }

    /*for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < G[i].size(); j++) {
            cout << G[i][j] << ' ';
        }
        cout << '\n';
    }*/

    dfs(1);


    return 0;
}