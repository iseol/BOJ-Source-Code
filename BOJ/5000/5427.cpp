#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int fdist[1001][1001];
int dist[1001][1001];
char board[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int h, w;
		cin >> w >> h;
		
		for (int i = 0; i < h; i++) {
			fill(fdist[i], fdist[i]+w, -1);
			fill(dist[i], dist[i]+w, -1);
		}
		
		pair<int, int> sg;
		queue<pair<int, int> > q;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					fdist[i][j] = 0;
					q.push({i, j});
				}
				if (board[i][j] == '@') {
					dist[i][j] = 0;
					sg = {i, j};
				}
			}
		}
		
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#' || fdist[nx][ny] >= 0) continue;
				fdist[nx][ny] = fdist[cur.X][cur.Y] + 1;
				q.push({nx, ny});
			}
		}
		
		bool flag = false;
		q.push(sg);
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					if (!flag) {
						cout << dist[cur.X][cur.Y] + 1 << '\n';
						flag = true;
					}
				}
				if (board[nx][ny] == '#' || dist[nx][ny] >= 0) continue;
				if (fdist[nx][ny] != -1 && dist[cur.X][cur.Y]+1 >= fdist[nx][ny]) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({nx, ny});
			}
		}
		if (!flag) cout << "IMPOSSIBLE" << '\n';
	}
}
