#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int board[101][101];
int dist[101][101];
int land[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }

    vector<int> ans;
    queue<pair<int, int> > q, wq;
    int landno = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && land[i][j] == 0) {
                land[i][j] = landno;
                q.push({i, j});
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (land[nx][ny] == land[cur.X][cur.Y]) continue;
                        if (board[nx][ny] == 0) {
                            if (land[nx][ny] != land[cur.X][cur.Y] && land[nx][ny] != 0) {
                                ans.push_back(1);
                                continue;
                            }
                            dist[nx][ny] = 1;
                            land[nx][ny] = landno;
                            wq.push({nx, ny});
                            continue;
                        }
                        else q.push({nx, ny}); 
                        land[nx][ny] = landno;
                    }
                }
                landno++;
            }
        }
    }

    while (!wq.empty()) {
        auto cur = wq.front(); wq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != -1 && land[nx][ny] != land[cur.X][cur.Y]) {
                ans.push_back(dist[nx][ny] + dist[cur.X][cur.Y]);
            }
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                land[nx][ny] = land[cur.X][cur.Y];
                wq.push({nx, ny});
            }
        }
    }
    int res = 12345;
    for (int i = 0; i < ans.size(); i++) res = min(res, ans[i]);
    cout << res;
}