#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
int board[20][20];
int board2[20][20];

void rotate() {
	int temp[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = temp[n-1-j][i];
		}
	}
}

void tilt(int dir) {
	while (dir--) rotate();
	
	for (int i = 0; i < n; i++) {
		int tilted[20] = {};
		int idx = 0;
		
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0) tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j]) tilted[idx++] *= 2;
			else tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < n; j++) board2[i][j] = tilted[j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	
	int mx = 0;
	for (int tmp = 0; tmp < 1024; tmp++) {
		int brute = tmp;
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board2[i][j] = board[i][j];
			}
		}
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;
			
			tilt(dir);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mx = max(board2[i][j], mx);
			}
		}
	}
	
	cout << mx;
}
