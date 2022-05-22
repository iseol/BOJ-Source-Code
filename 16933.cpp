#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

string board[1005];
int dist[2][11][1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) fill(dist[0][i][j], dist[0][i][j]+m, -1);
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) fill(dist[1][i][j], dist[1][i][j]+m, -1);
    }

    queue<tuple<bool, int, int, int> > q;
    q.push({true, k, 0, 0}); // isday, jumps, x, y
    dist[1][k][0][0] = 1;
    while (!q.empty()) {
        int x, y, jumps;
        bool isday;
        tie(isday, jumps, x, y) = q.front(); q.pop();
        
        if (x == n-1 && y == m-1) {
            cout << dist[isday][jumps][x][y] << '\n';
            return 0;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if (board[nx][ny] == '0') {
                if (dist[!isday][jumps][nx][ny] != -1) continue;
                dist[!isday][jumps][nx][ny] = dist[isday][jumps][x][y] + 1;
                q.push({!isday, jumps, nx, ny});
            }
            else if (jumps > 0) {
                if (isday) {
                    if (dist[!isday][jumps-1][nx][ny] != -1) continue;
                    dist[!isday][jumps-1][nx][ny] = dist[isday][jumps][x][y] + 1;
                    q.push({!isday, jumps-1, nx, ny});
                }
                else {
                    if (dist[!isday][jumps][x][y] != -1) continue;
                    dist[!isday][jumps][x][y] = dist[isday][jumps][x][y] + 1;
                    q.push({!isday, jumps, x, y});
                }
            }
        }
    }/*
    cout << '\n';
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= k; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    cout << dist[i][j][k][l] << ' ';
                }
                cout << '\n';
            }
            cout << '\n' << '\n';
        }
        cout << '\n' << '\n';
    }*/
    cout << -1;
}