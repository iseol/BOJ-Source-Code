#include <iostream>
#include <utility>
using namespace std;

int n, m, k;
int note[42][42];
int sticker[12][12];
int r, c;

bool pasteable(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (note[x+i][y+j] == 1 && sticker[i][j] == 1) return false;
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1) note[x+i][y+j] = 1;
		}
	}
	return true;
}

void rotate() {
	int temp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = sticker[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			sticker[i][j] = temp[r-1-j][i];
		}
	}
	swap(r, c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
		
		for (int rot = 0; rot < 4; rot++) {
			bool pasted = false;
			for (int i = 0; i <= n-r; i++) {
				if (pasted) break;
				for (int j = 0; j <= m-c; j++) {
					if (pasteable(i, j)) {
						pasted = true;
						break;
					}
				}
			}
			if (pasted) break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += note[i][j];
		}
	}
	cout << cnt;
}
