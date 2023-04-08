#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

char board[5][5];
bool vis[5][5];
bool arr[25];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> s;

bool sel(int x, int y) {
    bool flag = false;
    for (int i : s) {
        if (x*5+y == i)
        flag = true;
    }
    return flag;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) cin >> board[i][j];
    }

    fill(arr, arr+25, 1);
    for (int i = 0; i < 7; i++) arr[i] = 0;

    queue<pair<int, int>> q;
    int res = 0;
    do {
        int cnt = 0;
        for (int i = 0; i < 25; i++) {
            if (!arr[i]) s.push_back(i);
        }
        int st = s[0];
        q.push({st/5, st%5});
        if (board[st/5][st%5] == 'S') cnt++;
        vis[st/5][st%5] = true;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (vis[nx][ny] || !sel(nx, ny)) continue;
                if (board[nx][ny] == 'S') cnt++;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        bool flag = true;
        for (int i : s) {
            if (!vis[i/5][i%5]) flag = false;
        }
        if (flag && cnt >= 4) res++;


        for (int i = 0; i < 5; i++) fill(vis[i], vis[i]+5, false);
        s.erase(s.begin(), s.end());
        
    } while (next_permutation(arr, arr+25));
    cout << res;
}