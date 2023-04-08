#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

string board[1001];
int dist[11][1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            fill(dist[i][j], dist[i][j]+m, -1);
        }
    }
 
    for (int i = 0; i < n; i++) cin >> board[i];
    queue<tuple<int, int, int> > q;
    dist[k][0][0] = 1;
    q.push({k, 0, 0});
    while (!q.empty()) {
        int left, x, y;
        tie(left, x, y) = q.front(); q.pop();
        if (x == n-1 && y == m-1) {
            cout << dist[left][x][y];
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '0') {
                if (dist[left][nx][ny] != -1) continue;
                dist[left][nx][ny] = dist[left][x][y] + 1;
                q.push({left, nx, ny});
            }
            else {
                if (left <= 0) continue;
                if (dist[left-1][nx][ny] != -1) continue;
                dist[left-1][nx][ny] = dist[left][x][y] + 1;
                q.push({left-1, nx, ny});
            }
        }
    }
    cout << -1;
}