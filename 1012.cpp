#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[51][51];
int vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i]+m, 0);
			fill(vis[i], vis[i]+m, 0);
		}
		
		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> y >> x;
			board[x][y] = 1;
		}
		
		queue<pair<int, int> > q;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) continue;
				else if (vis[i][j] == 0) {
					q.push({i, j});
					vis[i][j] = 1;
					ans++;
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
							vis[nx][ny] = 1;
							q.push({nx, ny});
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
