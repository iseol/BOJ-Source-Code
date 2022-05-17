#include <iostream>
#define X first
#define Y second
using namespace std;

int paper[128][128];
int n;
int white, blue;

void sol(int n, pair<int, int> start, pair<int, int> end) {
	int half = n/2;
	
	if (n == 1) {
		if (paper[start.X][start.Y] == 0) white++;
		else blue++;
		return;
	}
	
	int color = paper[start.X][start.Y];
	for (int i = start.X; i <= end.X; i++) {
		for (int j = start.Y; j <= end.Y; j++) {
			if (color != paper[i][j]) {
				sol(n/2, start, {end.X-half, end.Y-half});
				sol(n/2, {start.X, start.Y+half}, {end.X-half, end.Y});
				sol(n/2, {start.X+half, start.Y}, {end.X, end.Y-half});
				sol(n/2, {start.X+half, start.Y+half}, end);
				return;
			}
		}
	}
	
	if (color == 0) white++;
	else blue++;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	sol(n, {0, 0}, {n-1, n-1});
	cout << white << '\n' << blue;
}
