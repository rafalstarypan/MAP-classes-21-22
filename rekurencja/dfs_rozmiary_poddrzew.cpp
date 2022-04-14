#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int n;
vector<int> G[MAX_N];
bool odw[MAX_N];
int rozmiar_poddrzewa[MAX_N];

int dfs(int v) {
    odw[v] = true;
    int rozmiar = 1;

    for (int i = 0; i < G[v].size(); i++) {
        if (odw[ G[v][i] ] == false) {
            rozmiar += dfs(G[v][i]);
        }
    }

    rozmiar_poddrzewa[v] = rozmiar;
    return rozmiar;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1);

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int v;
        cin >> v;
        cout << rozmiar_poddrzewa[v] << '\n';
    }

    return 0;
}