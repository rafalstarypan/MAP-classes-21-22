#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n;
int a[1005][1005];
bool odw[1005][1005];

const int MOVES = 4;
int dr[MOVES] = {-1, 0, 1, 0};
int dc[MOVES] = {0, 1, 0, -1};

bool inside(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < n);
}

int bfs(int start_row, int start_col) {
    queue<pair<int, int>> Q;
    int component_size = 0;
    int value_in_component = a[start_row][start_col];   // connected components
    odw[start_row][start_col] = true;
    Q.push(make_pair(start_row, start_col));

    while (!Q.empty()) {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        component_size++;

        for (int i = 0; i < MOVES; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (inside(new_row, new_col) && a[new_row][new_col] == value_in_component && odw[new_row][new_col] == false) {
                odw[new_row][new_col] = true;
                Q.push(make_pair(new_row, new_col));
            }
        }
    }

    return component_size;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int max_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (odw[i][j] == false) {
                max_size = max(max_size, bfs(i, j));
            }
        }
    }

    cout << max_size << '\n';

    return 0;
}