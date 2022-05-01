#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int dist[301][301];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		int l;
		cin >> l;
		for (int i = 0; i < l; i++) {
			fill(dist[i], dist[i]+l, -1);
		}
		
		queue<pair<int, int> > q;
		int x, y;
		cin >> x >> y;
		dist[x][y] = 0;
		q.push({x, y});
		cin >> x >> y;
		
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({nx, ny});
			}
		}

		cout << dist[x][y] << '\n';
	}
}
