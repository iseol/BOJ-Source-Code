#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

string board[12];
bool vis[12][6];
bool tempvis[12][6];
char color[5] = {'R', 'G', 'B', 'P', 'Y'};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 12; i++) cin >> board[i];

    queue<pair<int, int> > q;
    int rensa = 0;
    while (1) {
        for (char c: color) {
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 6; j++) {
                    if (!vis[i][j] && board[i][j] == c) {
                        int sz = 1;
                        tempvis[i][j] = true;
                        q.push({i, j});
                        while (!q.empty()) {
                            auto cur = q.front(); q.pop();
                            for (int dir = 0; dir < 4; dir++) {
                                int nx = cur.X + dx[dir];
                                int ny = cur.Y + dy[dir];
                                if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                                if (tempvis[nx][ny] || board[nx][ny] != c) continue;
                                tempvis[nx][ny] = true;
                                sz++;
                                q.push({nx, ny});
                            }
                        }
                        if (sz >= 4) {
                            for (int k = 0; k < 12; k++) {
                                for (int l = 0; l < 6; l++) {
                                    if (tempvis[k][l]) vis[k][l] = true;
                                }
                            }
                        }
                        for (int k = 0; k < 12; k++) fill(tempvis[k], tempvis[k]+6, false);
                    }
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (vis[i][j]) {
                    flag = true;
                    board[i][j] = '.';
                }
            }
        }
        for (int col = 0; col < 6; col++) {
            int cursor = 11;
            int tilted[12] = {};
            fill(tilted, tilted+12, '.');
            for (int row = 11; row >= 0; row--) {
                if (board[row][col] != '.') {
                    tilted[cursor] = board[row][col];
                    cursor--;
                }
            }
            for (int row = 11; row >= 0; row--) {
                board[row][col] = tilted[row];
            }
        }
        for (int i = 0; i < 12; i++) fill(vis[i], vis[i]+6, false);
        if (flag) rensa++;
        else break;
    }
    cout << rensa;
}