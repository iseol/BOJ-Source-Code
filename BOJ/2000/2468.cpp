#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[100][100];
bool flooded[100][100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	int n;
	cin >> n;
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int level = 0; level <= 100; level++) {
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i]+n, false);
			fill(flooded[i], flooded[i]+n, false); 
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] <= level) {
					flooded[i][j] = true;
				}
			}
		}
		
		queue<pair<int, int> > q;
		int not_flooded_area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!flooded[i][j] && !vis[i][j]) {
					vis[i][j] = true;
					q.push({i, j});
					not_flooded_area++;
					while (!q.empty()) {
						auto cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (flooded[nx][ny] || vis[nx][ny]) continue;
							vis[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}	
			}
		}
		res = max(res, not_flooded_area);
	}
	cout << res << '\n';
}
