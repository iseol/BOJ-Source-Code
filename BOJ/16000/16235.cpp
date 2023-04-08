#include <iostream>
#include <deque>
using namespace std;

deque<int> grid[11][11];
int a[11][11], nut[11][11];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) fill(nut[i], nut[i]+n+1, 5);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }

    while (m--) {
        int r, c, age;
        cin >> r >> c >> age;
        grid[r][c].push_back(age);
    }

    while (k--) {
        // spring
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int sz = (int)grid[i][j].size();
                for (int k = sz-1; k >= 0; k--) {
                    if (nut[i][j] - grid[i][j][k] >= 0) {
                        nut[i][j] -= grid[i][j][k];
                        grid[i][j][k]++;
                    }
                    else {
                        for (int l = 0; l <= k; l++) {
                            nut[i][j] += grid[i][j].front() / 2;
                            grid[i][j].pop_front();
                        }
                        break;
                    }
                }
            }
        }

        // fall
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int sz = (int)grid[i][j].size();
                for (int k = 0; k < sz; k++) {
                    if (grid[i][j][k] % 5 == 0) {
                        for (int dir = 0; dir < 8; dir++) {
                            int nx = i + dx[dir];
                            int ny = j + dy[dir];
                            if (nx > n || nx <= 0 || ny > n || ny <= 0) continue;
                            grid[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }

        // winter
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) nut[i][j] += a[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res += grid[i][j].size();
        }
    }
    cout << res;
}