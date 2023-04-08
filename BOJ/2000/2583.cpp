#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[101][101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	for (int r = 0; r < k; r++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int a = x1; a <= x2-1; a++) {
			for (int b = y1; b <= y2-1; b++) {
				board[a][b] = 1;
			}
		}
	}
	
	int areas = 0;
	vector<int> res;
	queue<pair<int, int> > q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 && vis[i][j] == false) {
				q.push({i, j});
				vis[i][j] = true;
				areas++;
				int ans = 1;
				
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (board[nx][ny] == 1 || vis[nx][ny] == true) continue;
						vis[nx][ny] = true;
						ans++;
						q.push({nx, ny});
					}
				}
				res.push_back(ans);
			}
		}
	}
	
	sort(res.begin(), res.end());
	cout << areas << '\n';
	for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
}
