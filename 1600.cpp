#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int board[202][202];
int dist[31][202][202];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int kdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int kdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, w, h;
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				dist[i][j][k] = -1;
			}
		}
	}


	queue<tuple<int, int, int> > q;
	dist[k][0][0] = 0;
	q.push({k, 0, 0});
	while (!q.empty()) {
		int jumps, x, y;
		tie(jumps, x, y) = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (dist[jumps][nx][ny] != -1 || board[nx][ny] == 1) continue;
			dist[jumps][nx][ny] = dist[jumps][x][y] + 1;
			q.push({jumps, nx, ny});
		}
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + kdx[dir];
			int ny = y + kdy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (jumps > 0) {
				if (dist[jumps-1][nx][ny] == -1 && board[nx][ny] == 0) {
					dist[jumps-1][nx][ny] = dist[jumps][x][y] + 1;
					q.push({jumps-1, nx, ny});
				}
			}
		}
	}
	int res = 40004;
	for (int i = 0; i <= k; i++) {
		if (dist[i][h-1][w-1] != -1) {
			res = min(dist[i][h-1][w-1], res);
		}
	}
	if (res == 40004) cout << -1;
	else cout << res;
}