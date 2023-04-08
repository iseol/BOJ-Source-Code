#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[8][8];
int board2[8][8];
bool vis[8][8];
// vis2
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            board2[i][j] = board[i][j];
        }
    }

    queue<pair<int, int> > q;
    int res = -1;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < m; y2++) {
                    for (int x3 = 0; x3 < n; x3++) {
                        for (int y3 = 0; y3 < m; y3++) {
                            if (board[x1][y1] != 0 || board[x2][y2] != 0 || board[x3][y3] != 0) continue;
                            if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x1 && y3 == y1)) continue;
                            board2[x1][y1] = 1;
                            board2[x2][y2] = 1;
                            board2[x3][y3] = 1;

                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    if (board2[i][j] == 2 && !vis[i][j]) {
                                        vis[i][j] = true;
                                        q.push({i, j});
                                        while (!q.empty()) {
                                            auto cur = q.front(); q.pop();
                                            for (int dir = 0; dir < 4; dir++) {
                                                int nx = cur.X + dx[dir];
                                                int ny = cur.Y + dy[dir];

                                                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                                                if (vis[nx][ny] || board2[nx][ny] != 0) continue;
                                                vis[nx][ny] = true;
                                                q.push({nx, ny});
                                            }
                                        }
                                    }
                                }
                            }
                            int area = 0;
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    if (board2[i][j] == 0 && !vis[i][j]) area++;
                                }
                            }
                            res = max(res, area);

                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    board2[i][j] = board[i][j];
                                }
                                fill(vis[i], vis[i]+m, false);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res;
}