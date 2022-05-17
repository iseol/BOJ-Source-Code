#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
char board[31][31][31]; // z, x, y
int dist[31][31][31];

int main() {
    while (1) {
        int l, r, c;
        cin >> l >> r >> c;
        if (l+r+c == 0) return 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                fill(dist[i][j], dist[i][j]+c, -1);
            }
        }
        
        queue<tuple<int, int, int> > q;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S') {
                        dist[i][j][k] = 0;
                        q.push(make_tuple(i, j, k));
                    }
                }
            }
        }
        
        int dx[6] = {1, 0, -1, 0, 0, 0};
        int dy[6] = {0, -1, 0, 1, 0, 0};
        int dz[6] = {0, 0, 0, 0, 1, -1};
        
        bool flag = false;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 6; dir++) {
                int nx = get<1>(cur) + dx[dir];
                int ny = get<2>(cur) + dy[dir];
                int nz = get<0>(cur) + dz[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
                if (board[nz][nx][ny] == '#' || dist[nz][nx][ny] != -1) continue;
                dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                if (board[nz][nx][ny] == 'E') {
                    cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
                    flag = true;
                }
                q.push(make_tuple(nz, nx, ny));
            }
        }
        if (!flag) cout << "Trapped!\n";
    }
}
