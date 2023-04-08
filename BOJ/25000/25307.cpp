#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;

int board[2005][2005];
int dist[2005][2005];
bool forbidden[2005][2005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<tuple<int, int, int, int>> mq; // mx my nx ny
    queue<pair<int, int>> q;
    vector<pair<int, int>> chairs;
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) fill(dist[i], dist[i]+m, -1); // didnt visit
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) chairs.push_back({i, j});
            else if (board[i][j] == 3) {
                mq.push({i, j, i, j});
                forbidden[i][j] = true;
            }
            else if (board[i][j] == 4) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!mq.empty()) {
        auto cur = mq.front(); mq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = get<2>(cur) + dx[dir];
            int ny = get<3>(cur) + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (forbidden[nx][ny]) continue; // ?
            if ((abs(nx-get<0>(cur))+abs(ny-get<1>(cur))) <= k) {
                forbidden[nx][ny] = true; // forbidden
                mq.push({get<0>(cur), get<1>(cur), nx, ny});
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (forbidden[nx][ny] || dist[nx][ny] != -1 || board[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    int res = 987654321;
    for (auto chair : chairs) {
        if (dist[chair.X][chair.Y] < 0 || forbidden[chair.X][chair.Y]) continue;
        res = min(res, dist[chair.X][chair.Y]);
    }


    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << forbidden[i][j] << ' ';
        }
        cout << '\n';
    } */
    if (res == 987654321) cout << -1;
    else cout << res;
}