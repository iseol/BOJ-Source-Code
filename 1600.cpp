#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[200][200];
int dist[200][200];
int karr[200][200];

int dx[12] = {-2, 1, -1, -2, -2, -1, 1, 2, 0, 1, 0, -1};
int dy[12] = {1, 2, 2, 1, -1, -2, -2, -1, 1, 0, -1, 0};

int main() {
	int k;
	int w, h;
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		fill(dist[i], dist[i]+w, -1);
		fill(karr[i], karr[i]+w, -1);
	} 
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}
	
	queue<pair<int, int> > q;
	q.push({0, 0});
	dist[0][0] = 0;
	karr[0][0] = k;
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 12; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if ((dir <= 7 && karr[cur.X][cur.Y] != 0) || (dir > 7)) {
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist[nx][ny] != -1 || board[nx][ny] == 1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				if (dir <= 7) karr[nx][ny] = karr[cur.X][cur.Y] - 1;
				else karr[nx][ny] = karr[cur.X][cur.Y];
				
				q.push({nx, ny});
			} 
		}
	}
	
	cout << dist[h-1][w-1];
}
