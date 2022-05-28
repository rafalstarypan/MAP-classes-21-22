#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;

/*
    Fajne zadanie z OI
    XXVIII OI etap II
    Zadanie: Zdjecia krasnali
*/

int n, m;
vector<int> G[MAX_N];
int in_deg[MAX_N];
vector<int> topsort_order;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);  // krawedz jest skierowana - dodaje tylko w jedna strone
        in_deg[b]++;        // mam krawedz a->b zatem zwiekszam liczbe krawedzi wchodzacych do b
    }

    queue<int> Q;

    // dodaje poczatkowe wierzcholki bez zaleznosci do kolejki
    for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0) {
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        topsort_order.push_back(v);     // dodaje wierzcholek do wynnikowej kolejnosci

        for (int i = 0; i < G[v].size(); i++) {
            int neighbour = G[v][i];   

            // wirtualnie usuwam wierzcholek v, wiec zmniejszam liczbe krawedzi wchodzacych do sasiada     
            in_deg[neighbour]--;  

            // sasiad nie ma juz zadnych zaleznosci - dodaje go do kolejki  
            if (in_deg[neighbour] == 0) {
                Q.push(neighbour);
            }
        }
    }
    
    // jesli nie przetworzono wszystkich wierzcholkow to w grafie wystapil cykl
    // if (topsort_order.size() < n) {
    //     cout << "W grafie wystapil cykl";
    //     return 0;
    // }

    for (int i = 0; i < topsort_order.size(); i++) {
        cout << topsort_order[i] << ' ';
    }
    cout << '\n';

    return 0;
}