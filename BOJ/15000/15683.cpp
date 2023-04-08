#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board1[8][8];
int board2[8][8];
vector<pair<int, int> > cctv;

void upd(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m || board2[x][y] == 6) return;
		if (board2[x][y] != 0) continue;
		board2[x][y] = 7;
	}
}

int main() {
	cin >> n >> m;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({i, j});
			if (board1[i][j] == 0) mn++;
		} 
	}
	
	for (int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x, y;
			tie(x, y) = cctv[i];
			
			switch (board2[x][y]) {
				case 1:
					upd(x, y, dir);
					break;
				case 2:
					upd(x, y, dir);
					upd(x, y, dir+2);
					break;
				case 3:
					upd(x, y, dir);
					upd(x, y, dir+1);
					break;
				case 4:
					upd(x, y, dir);
					upd(x, y, dir+1);
					upd(x, y, dir+2);
					break;
				case 5:
					upd(x, y, dir);
					upd(x, y, dir+1);
					upd(x, y, dir+2);
					upd(x, y, dir+3);
					break;
			}
		}
		int val = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				val += (board2[i][j] == 0);
			}
		}
		mn = min(mn, val);
	}
	cout << mn;
}
