#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[21][21], dist[21][21];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> sharks;

int main() {
    pair<int, int> baby;
  
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 6) sharks.push_back({i, j});
            if (board[i][j] == 9) {
                baby = {i, j};
                board[i][j] = 0;
            }
        }
    }

    int lvl = 2;
    int exp = 0;
    int ans = 0;

    while (1) {
        for (int i = 0; i < n; i++) fill(dist[i], dist[i]+n, -1);

        queue<pair<int, int>> q;
        dist[baby.X][baby.Y] = 0;
        q.push(baby);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] != -1 || board[nx][ny] > lvl) continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }

        pair<int, int> nxt = {20, 20};
        dist[20][20] = 100000000;
        for (auto pos : sharks) {
            if (board[pos.X][pos.Y] < lvl && dist[pos.X][pos.Y] != -1) {
                if (dist[pos.X][pos.Y] < dist[nxt.X][nxt.Y]) {
                    nxt = pos;
                }
                if ((dist[pos.X][pos.Y] == dist[nxt.X][nxt.Y]) && (nxt > pos)) {
                    nxt = pos;
                }
            }
        }
        if (nxt.X == 20) {
            cout << ans;
            return 0;
        }
        baby = nxt;
        board[baby.X][baby.Y] = 0;
        exp++;
        if (exp == lvl) {
            exp = 0;
            lvl++;
        }

        ans += dist[baby.X][baby.Y];

    

        int sz = sharks.size();
        for (int i = 0; i < sz; i++) {
            if (sharks[i] == baby) sharks.erase(sharks.begin()+i);
        }
    }
} 