#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[300][300];
bool vis[300][300];
bool vis2[300][300];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	int time = 0;
	while (1) {
		
		queue<pair<int, int> > idq;
		int cnt = 0;
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (board[i][j] != 0 && !vis[i][j]) {
					idq.push({i, j});
					vis[i][j] = true;
					while (!idq.empty()) {
						auto cur = idq.front(); idq.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 1 || nx >= n-1 || ny < 1 || ny >= m-1) continue;
							if (vis[nx][ny] || board[nx][ny] == 0) continue;
							vis[nx][ny] = true;
							idq.push({nx, ny});
						}
					}
					cnt++;
				}
			}
		}
		if (cnt >= 2) {
			cout << time;
			return 0;
		}
		else if (cnt == 0) {
			cout << 0;
			return 0;
		}
		
		for (int i = 1; i < n-1; i++) fill(vis[i]+1, vis[i]+m-1, false);
		
		queue<pair<int, int> > q;
		queue<pair<int, int> > nq;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis2[i][j] && (board[i][j] == 0)) {
					vis2[i][j] = true;
					q.push({i, j});
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (vis2[nx][ny]) continue;
							if (board[nx][ny] > 0) {
								nq.push({nx, ny});
								continue;
							}
							vis2[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
			}
		}
		while (!nq.empty()) {
			auto ice = nq.front(); nq.pop();
			if (board[ice.X][ice.Y] >= 1) board[ice.X][ice.Y]--;
		}
		time++;
		for (int i = 0; i < n; i++) fill(vis2[i], vis2[i]+m, false);

	}
}
