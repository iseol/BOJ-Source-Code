#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char board1[101][101]; // 적록색약  
char board2[101][101]; //  적록색약 ㄴㄴ 
bool vis1[101][101];
bool vis2[101][101];

int ans1;
int ans2;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board2[i][j];
			if (board2[i][j] == 'B' || board2[i][j] == 'R') board1[i][j] = board2[i][j];
			else if (board2[i][j] == 'G') board1[i][j] = 'R';
		}
	}
	// board1 bfs
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board1[i][j] == 'R') {
				if (vis1[i][j] == false) {
				    q.push({i, j});
				    vis1[i][j] = true;
				    ans1++;
				    while (!q.empty()) {
				    	auto cur = q.front(); q.pop();
				    	for (int dir = 0; dir < 4; dir++) {
				    		int nx = cur.X + dx[dir];
				    		int ny = cur.Y + dy[dir];
				    		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board1[nx][ny] == 'B' || vis1[nx][ny] == true) continue;
							vis1[nx][ny] = true;
							q.push({nx, ny});
						}
					}
			    }
			}
			else if (board1[i][j] == 'B') {
				if (vis1[i][j] == false) {
					q.push({i, j});
				    vis1[i][j] = true;
				    ans1++;
				    while (!q.empty()) {
				    	auto cur = q.front(); q.pop();
				    	for (int dir = 0; dir < 4; dir++) {
				    		int nx = cur.X + dx[dir];
				    		int ny = cur.Y + dy[dir];
				    		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board1[nx][ny] == 'R' || vis1[nx][ny] == true) continue;
							vis1[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
			}
		}
	}
	// board2 bfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 'R') {
				if (vis2[i][j] == false) {
				    q.push({i, j});
				    vis2[i][j] = true;
				    ans2++;
				    while (!q.empty()) {
				    	auto cur = q.front(); q.pop();
				    	for (int dir = 0; dir < 4; dir++) {
				    		int nx = cur.X + dx[dir];
				    		int ny = cur.Y + dy[dir];
				    		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board2[nx][ny] != 'R' || vis2[nx][ny] == true) continue;
							vis2[nx][ny] = true;
							q.push({nx, ny});
						}
					}
			    }
			}
			else if (board2[i][j] == 'B') {
				if (vis2[i][j] == false) {
					q.push({i, j});
				    vis2[i][j] = true;
				    ans2++;
				    while (!q.empty()) {
				    	auto cur = q.front(); q.pop();
				    	for (int dir = 0; dir < 4; dir++) {
				    		int nx = cur.X + dx[dir];
				    		int ny = cur.Y + dy[dir];
				    		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board2[nx][ny] != 'B' || vis2[nx][ny] == true) continue;
							vis2[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
			}
			else if (board2[i][j] == 'G') {
				if (vis2[i][j] == false) {
					q.push({i, j});
				    vis2[i][j] = true;
				    ans2++;
				    while (!q.empty()) {
				    	auto cur = q.front(); q.pop();
				    	for (int dir = 0; dir < 4; dir++) {
				    		int nx = cur.X + dx[dir];
				    		int ny = cur.Y + dy[dir];
				    		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (board2[nx][ny] != 'G' || vis2[nx][ny] == true) continue;
							vis2[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
			}
		}
	}
	cout << ans2 << ' ' << ans1 << '\n';
}
