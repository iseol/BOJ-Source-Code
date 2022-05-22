#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

string board[1005];
int dist[2][1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) fill(dist[0][i], dist[0][i]+m, -1);
	for (int i = 0; i < n; i++) fill(dist[1][i], dist[1][i]+m, -1);
	dist[0][0][0] = 1;
	dist[1][0][0] = 1;
	
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(0, 0, 0));
	
	while (!q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = q.front();
		if (x == n-1 && y == m-1) {
			cout << dist[broken][x][y];
			return 0;
		}
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[broken][nx][ny] != -1) continue;
			
			if (board[nx][ny] == '0' && dist[broken][nx][ny] == -1) {
				dist[broken][nx][ny] = dist[broken][x][y] + 1;
				q.push(make_tuple(nx, ny, broken));
			}
			if (!broken && board[nx][ny] == '1' && dist[1][nx][ny] == -1) {
				dist[1][nx][ny] = dist[broken][x][y] + 1;
				q.push(make_tuple(nx, ny, 1));
			}
		}
	}
	if (dist[1][n-1][m-1] != -1 && dist[0][n-1][m-1] == -1) cout << dist[1][n-1][m-1];
	else cout << min(dist[0][n-1][m-1], dist[1][n-1][m-1]);
}
