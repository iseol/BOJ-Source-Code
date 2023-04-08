#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
string board[1002];
int dist[1002][1002];
int firedist[1002][1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		fill(firedist[i], firedist[i]+c, -1);
		fill(dist[i], dist[i]+c, -1);
	}
	
	pair<int, int> jihoon;
	queue<pair<int, int> > q;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				jihoon = {i, j};
				dist[i][j] = 0;
			}
			if (board[i][j] == 'F') {
				q.push({i, j});
				firedist[i][j] = 0;
			}
		}
	}
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == '#' || firedist[nx][ny] >= 0) continue;
			firedist[nx][ny] = firedist[cur.X][cur.Y] + 1;
			q.push({nx, ny}); 
		}
	}
	
	q.push(jihoon);
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || dist[nx][ny] >= 0) continue;
			if (firedist[nx][ny] != -1 && firedist[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({nx, ny}); 
		}
	}
	/*
	cout << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << firedist[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	} */
	cout << "IMPOSSIBLE" << '\n';
}
