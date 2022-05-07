#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

/*queue<int> kolejka;
q.push(1);
int pierwszy = q.front();
q.empty();
q.pop();*/

int n, m;
string a[1005];
int dist[1005][1005];
int startRow = -1, startCol = -1;
int endRow = -1, endCol = -1;

const int MOVES = 4;
int dr[MOVES] = {-1, 0, 1, 0};
int dc[MOVES] = {0, 1, 0, -1};

bool inside(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = inf;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                startRow = i;
                startCol = j;
            } else if (a[i][j] == 'M') {
                endRow = i;
                endCol = j;
            }
        }
    }

    dist[startRow][startCol] = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(startRow, startCol));

    while (!Q.empty()) {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();

        for (int i = 0; i < MOVES; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (inside(new_row, new_col) && a[new_row][new_col] != '#') {
                int tmp = dist[row][col] + 1;
                if (tmp < dist[new_row][new_col]) {
                    dist[new_row][new_col] = tmp;
                    Q.push(make_pair(new_row, new_col));
                }
            }
        }
    }

    if (dist[endRow][endCol] == inf) {
        cout << "NIE\n";
        return 0;
    } 
    
    cout << dist[endRow][endCol] << '\n';

    return 0;
}