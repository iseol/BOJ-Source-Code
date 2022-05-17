#include <iostream>
using namespace std;

int n;
char board[2187][2187];

void sol(int n, int r, int c) {
	if (n == 3) {
		for (int i = r; i < r+n; i++) {
			for (int j = c; j < c+n; j++) {
				if (i-r == 1 && j-c == 1) board[i][j] = ' ';
				else {
					board[i][j] = '*';
				}
			}
		}
		return;
	}
	
	int third = n/3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				for (int k = r+third; k < r+third+third; k++) {
					for (int l = c+third; l < c+third+third; l++) {
						board[k][l] = ' ';
					}
				}
			}
			else {
				sol(n/3, r+third*i, c+third*j);	
			}	
		}
	}
	
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	sol(n, 0, 0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}
