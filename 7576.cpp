#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[1002][1002];
int dis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m, n;
	cin >> m >> n;
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({i, j});
			}
			else if (board[i][j] == 0) {
				dis[i][j] = -1;
			}
		}
	}
	
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dis[nx][ny] >= 0) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	
	int ans = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dis[i][j] == -1) {
				cout << -1 << '\n';
				return 0;
			}
			ans = max(dis[i][j], ans);
		}
	}
	cout << ans << '\n';
}
