#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

char board[25][25];
bool vis[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	vector<int> res;
	queue<pair<int, int> > q;
	int ans = 0;
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '1' && vis[i][j] == false) {
				q.push({i, j});
				vis[i][j] = true;
				ans++;
				int houses = 1;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[nx][ny] == '0' || vis[nx][ny] == true) continue;
						vis[nx][ny] = true;
						q.push({nx, ny});
						houses++;
					}
				}
				res.push_back(houses);
			}
		}
	}
	
	sort(res.begin(), res.end());
	cout << ans << '\n';
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
}
