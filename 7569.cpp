#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int board[102][102][102];
int dis[102][102][102];

int main() {
	int m, n, h;
	cin >> m >> n >> h;
	
	queue<tuple<int, int, int> > q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 0) {
					dis[i][j][k] = -1;
				} 
				if (board[i][j][k] == 1) {
					dis[i][j][k] = 0;
					q.push(make_tuple(i, j, k)); // z, x, y
				}
			}
		}
	}
	
	int dx[6] = {1, 0, -1, 0, 0, 0};
	int dy[6] = {0, -1, 0, 1, 0, 0};
	int dz[6] = {0, 0, 0, 0, 1, -1};
	
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			int nz = get<0>(cur) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dis[nz][nx][ny] >= 0) continue;
			dis[nz][nx][ny] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push(make_tuple(nz, nx, ny));
		}
	}
	
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dis[i][j][k] == -1) {
					cout << -1 << '\n';
					return 0;
				}
				ans = max(dis[i][j][k], ans);
			}
		}
	}
	cout << ans << '\n';
}
