#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
char board[102][102];
int dis[102][102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fill(dis[i], dis[i]+m, -1);
	}
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};
	
	queue<pair<int, int> > q;
	q.push({0, 0});
	dis[0][0] = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] != '1') continue;
			if (dis[nx][ny] != -1) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	
	cout << dis[n-1][m-1]+1 << '\n';
}
