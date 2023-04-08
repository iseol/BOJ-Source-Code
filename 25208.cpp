#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char board[505][505];
int dist[6][505][505];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)  {
            cin >> board[i][j];
            if (board[i][j] == 'D') {
                q.push({i, j});
                dist[5][i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
        }
    }
}