#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= m; j++) board[i][j] = temp[j-1]-'0';
    }
    
    for (int i = 1; i <= n; i++) fill(dist1[i]+1, dist1[i]+m+1, -1);
    for (int i = 1; i <= n; i++) fill(dist2[i]+1, dist2[i]+m+1, -1);

    queue<pair<int, int>> q;
    dist1[1][1] = 0;
    q.push({1, 1});

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (dist1[nx][ny] != -1 || board[nx][ny] == 1) continue;

            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    dist2[n][m] = 1;
    q.push({n, m});
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (dist2[nx][ny] != -1 || board[nx][ny] == 1) continue;

            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    int ans = 1e7 + 9;
    for (int i = 1; i <= n; i++) {
        int r = -1;
        int ridx = -1;
        for (int j = 1; j <= m; j++) {
            if (dist1[i][j] != -1) {
                r = dist1[i][j];
                ridx = j;
                break;
            }
        }
        int b = -1;
        int bidx = -1;
        for (int j = m; j >= 1; j--) {
            if (dist2[i][j] != -1) {
                b = dist2[i][j];
                bidx = j;
                break;
            }
        }

        if (r == -1 || b == -1) continue;
        int temp = r + b + abs(ridx - bidx) - 1;
        ans = min(ans, temp);
    }

    for (int i = 1; i <= m; i++) {
        int r = -1;
        int ridx = -1;
        for (int j = 1; j <= n; j++) {
            if (dist1[j][i] != -1) {
                r = dist1[j][i];
                ridx = j;
                break;
            }
        }
        int b = -1;
        int bidx = -1;
        for (int j = n; j >= 1; j--) {
            if (dist2[j][i] != -1) {
                b = dist2[j][i];
                bidx = j;
                break;
            }
        }

        if (r == -1 || b == -1) continue;
        int temp = r + b + abs(ridx - bidx) - 1;
        ans = min(ans, temp);
    }

    
    //dist1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << dist1[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
    // dist2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout<< dist2[i][j] << ' ';
        cout << '\n';
    }

    if (ans == 1e7 + 9) cout << -1;
    else cout << ans;
}