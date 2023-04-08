#include <iostream>
#include <queue>
using namespace std;

int gears[5][9]; // 1 based
int rotating[5]; // 1 based

int main() {
	for (int i = 1; i <= 4; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			gears[i][j+1] = temp[j]-'0';
		}
	}
	
	int k;
	cin >> k;
	while (k--) {
		int gear, dir;
		cin >> gear >> dir;
		
		queue<pair<int, int> > q;
		q.push({gear, dir});
		
		while (!q.empty()) {
			int cur, gear_dir;
			cur = q.front().first;
			gear_dir = q.front().second;
			
			q.pop();
			
			rotating[cur] = gear_dir;
			if (cur != 1 && rotating[cur-1] == 0) {
				if (gears[cur-1][3] != gears[cur][7]) {
					if (rotating[cur] == 1) q.push({cur-1, -1});
					else q.push({cur-1, 1});
				}
			}
			if (cur != 4 && rotating[cur+1] == 0) {
				if (gears[cur][3] != gears[cur+1][7]) {
					if (rotating[cur] == 1) q.push({cur+1, -1});
					else q.push({cur+1, 1});
				}
			}
		}
		for (int i = 1; i <= 4; i++) {
			if (rotating[i] == 1) {
				int temp[9];
				for (int j = 1; j <= 8; j++) {
					temp[j] = gears[i][j];
				}
				temp[0] = gears[i][8];
				for (int j = 1; j <= 8; j++) {
					gears[i][j] = temp[j-1];
				}
			}
			else if (rotating[i] == -1) {
				int temp[10];
				for (int j = 1; j <= 8; j++) {
					temp[j] = gears[i][j];
				}
				temp[9] = gears[i][1];
				for (int j = 1; j <= 8; j++) {
					gears[i][j] = temp[j+1];
				}
			}
		}
		fill(rotating, rotating+5, 0);
	}
	
	int res = 0;
	for (int i = 1; i <= 4; i++) {
		if (gears[i][1]) res += (1<<(i-1));
	}
	cout << res;
}
