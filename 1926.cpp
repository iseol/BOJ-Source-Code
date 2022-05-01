#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	queue<pair<int, int> > q;
	
	int MAX = 0;
	int paints = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			int s = 0;
			if (board[i][j] == 0) continue;
			else if (vis[i][j] == false) {
				paints++;
				s++;
				vis[i][j] = true;
				q.push({i, j});
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = true;
						s++;
						q.push({nx, ny});
					}
				}
				if (MAX < s) MAX = s;
				s = 0;
			}
		}
	}
	cout << paints << '\n';
	cout << MAX << '\n';
}
