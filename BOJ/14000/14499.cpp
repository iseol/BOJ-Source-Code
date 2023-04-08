#include <iostream>
#define X first
#define Y second
using namespace std;

int n, m;
int dice[6];
pair<int, int> dice_c;

int board[20][20];

void roll(int dir) {
	switch (dir) {
		case 1: {
			if (dice_c.Y + 1 >= m) return;
			int tempdice[6];
			for (int i = 0; i < 6; i++) tempdice[i] = dice[i];
			dice[0] = tempdice[1];
			dice[1] = tempdice[5];
			dice[2] = tempdice[0];
			dice[5] = tempdice[2];
			
			if (board[dice_c.X][dice_c.Y+1] == 0) board[dice_c.X][dice_c.Y+1] = dice[5];
			else {
				dice[5] = board[dice_c.X][dice_c.Y+1];
				board[dice_c.X][dice_c.Y+1] = 0;
			}
			
			dice_c.Y++;
			cout << dice[0] << '\n';
			break;
		}
		case 2: {
			if (dice_c.Y - 1 < 0) return;
			int tempdice[6];
			for (int i = 0; i < 6; i++) tempdice[i] = dice[i];
			dice[0] = tempdice[2];
			dice[1] = tempdice[0];
			dice[2] = tempdice[5];
			dice[5] = tempdice[1];
			
			if (board[dice_c.X][dice_c.Y-1] == 0) board[dice_c.X][dice_c.Y-1] = dice[5];
			else {
				dice[5] = board[dice_c.X][dice_c.Y-1];
				board[dice_c.X][dice_c.Y-1] = 0;
			}
			
			dice_c.Y--;
			cout << dice[0] << '\n';
			break;
		}
		case 3: {
			if (dice_c.X - 1 < 0) return;
			int tempdice[6];
			for (int i = 0; i < 6; i++) tempdice[i] = dice[i];
			dice[0] = tempdice[3];
			dice[3] = tempdice[5];
			dice[4] = tempdice[0];
			dice[5] = tempdice[4];
			
			if (board[dice_c.X-1][dice_c.Y] == 0) board[dice_c.X-1][dice_c.Y] = dice[5];
			else {
				dice[5] = board[dice_c.X-1][dice_c.Y];
				board[dice_c.X-1][dice_c.Y] = 0;
			}
			
			dice_c.X--;
			cout << dice[0] << '\n';
			break;
		}
		case 4: {
			if (dice_c.X + 1 >= n) return;
			int tempdice[6];
			for (int i = 0; i < 6; i++) tempdice[i] = dice[i];
			dice[0] = tempdice[4];
			dice[3] = tempdice[0];
			dice[4] = tempdice[5];
			dice[5] = tempdice[3];
			
			if (board[dice_c.X+1][dice_c.Y] == 0) board[dice_c.X+1][dice_c.Y] = dice[5];
			else {
				dice[5] = board[dice_c.X+1][dice_c.Y];
				board[dice_c.X+1][dice_c.Y] = 0;
			}
			
			dice_c.X++;
			cout << dice[0] << '\n';
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x, y, k;
	cin >> n >> m >> x >> y >> k;
	dice_c = {x, y};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	while (k--) {
		int dir;
		cin >> dir;
		
		roll(dir); // roll and output
	} 
}
