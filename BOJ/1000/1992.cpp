#include <iostream>
using namespace std;

int n;
string str = "";
string board[64];

void sol(int n, int r, int c) {
	char color = board[r][c];
	if (n == 1) {
		str += color;
		return;
	}
	
	for (int i = r; i < r+n; i++) {
		for (int j = c; j < c+n; j++) {
			if (board[i][j] != color) {
				str += '(';
				sol(n/2, r, c);
				sol(n/2, r, c+n/2);
				sol(n/2, r+n/2, c);
				sol(n/2, r+n/2, c+n/2);
				str += ')';
				return;
			}
		}
	}
	str += color;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	sol(n, 0, 0);
	cout << str;
}
