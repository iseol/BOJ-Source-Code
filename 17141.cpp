#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[51][51];
int dist[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> place;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) place.push_back({i, j});
        }
    }

    int sz = (int)place.size();
    vector<int> arr;
    for (int i = 0; i < m; i++) arr.push_back(0);
    for (int i = 0; i < sz-m; i++) arr.push_back(1);

    queue<pair<int, int>> q;

    int res = 1e7;
    do {
        for (int i = 0; i < n; i++) fill(dist[i], dist[i]+n, -1);
        for (int i = 0; i < sz; i++) {
            if (!arr[i]) {
                q.push(place[i]);
                dist[place[i].X][place[i].Y] = 0;
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] != -1 || board[nx][ny] == 1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }

        int time = -2;
        [&] () {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    time = max(time, dist[i][j]);
                    if (board[i][j] == 0 && dist[i][j] == -1) {
                        time = -2;
                        return;
                    }
                }
            }
        } ();
        if (time != -2) {
            res = min(res, time);
        } 
    } while (next_permutation(arr.begin(), arr.end()));
    if (res == 1e7) cout << -1;
    else cout << res;
}