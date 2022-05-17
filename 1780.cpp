#include <iostream>
#define X first
#define Y second
using namespace std;

int paper[2187][2187];
int n;
int minus_one, zero, one;

void sol(int n, pair<int, int> start, pair<int, int> end) {
	int third = n/3;
	
	if (n == 1) {
		if (paper[start.X][start.Y] == 1) one++;
		if (paper[start.X][start.Y] == 0) zero++;
		if (paper[start.X][start.Y] == -1) minus_one++;
		return;
	}
	
	int num = paper[start.X][start.Y];
	for (int i = start.X; i <= end.X; i++) {
		for (int j = start.Y; j <= end.Y; j++) {
			if (paper[i][j] != num) {
				sol(third, start, {end.X-third-third, end.Y-third-third});
				sol(third, {start.X, start.Y+third}, {end.X-third-third, end.Y-third});
				sol(third, {start.X, start.Y+third+third}, {end.X-third-third, end.Y});
				
				sol(third, {start.X+third, start.Y}, {end.X-third, end.Y-third-third});
				sol(third, {start.X+third, start.Y+third}, {end.X-third, end.Y-third});
				sol(third, {start.X+third, start.Y+third+third}, {end.X-third, end.Y});
				
				sol(third, {start.X+third+third, start.Y}, {end.X, end.Y-third-third});
				sol(third, {start.X+third+third, start.Y+third}, {end.X, end.Y-third});
				sol(third, {start.X+third+third, start.Y+third+third}, end);
				return;
			}
		}
	}
	
	if (num == 1) one++;
	if (num == 0) zero++;
	if (num == -1) minus_one++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	
	sol(n, {0, 0}, {n-1, n-1});
	cout << minus_one << '\n' << zero << '\n' << one;
}
