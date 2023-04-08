#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

double board[101][101];
bool vis[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    queue<pair<int, int> > q, nq;
    int time = 0;
    bool flag = false;
    while (1) {
        q.push({0, 0});
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (vis[nx][ny]) continue;
                if (board[nx][ny] != 0) {
                    nq.push({nx, ny});
                    continue;
                }
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        while (!nq.empty()) {
            auto cur = nq.front(); nq.pop();
            if (board[cur.X][cur.Y] > 0) board[cur.X][cur.Y] -= 0.5;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0.5) board[i][j] = 1;
            }
        }
        flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j]) flag = false;
                vis[i][j] = false;
            }
        }

        time++;
        if (flag) break;
    }
    cout << time;
}