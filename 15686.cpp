#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#define X first
#define Y second
using namespace std;

int board[50][50];
int n, m;

int main() {
	cin >> n >> m;
	
	vector<pair<int, int> > chicken;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) chicken.push_back({i, j});
		}
	}
	
	int sz = chicken.size();
	vector<int> a;
	for (int i = 0; i < m; i++) a.push_back(0);
	for (int i = 0; i < sz-m; i++) a.push_back(1);
	
	int res = 0x7f7f7f7f;
	do {
		int dist = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				int dis = 0x7f7f7f7f;
				if (board[x][y] == 1) {
					for (int i = 0; i < sz; i++) { // m개의 치킨집 선택 (i -> idx)
						if (a[i] == 0) {
							int tmp = abs(chicken[i].X - x) + abs(chicken[i].Y - y);
							dis = min(tmp, dis);
							// chicken[i] -> 폐업당하지 않은 치킨집 좌표(pair) 
						}
					}
					dist += dis;
				}
				
			}
		}
		
		res = min(dist, res);
	} while (next_permutation(a.begin(), a.end()));
	
	
	cout << res;
	//next per뭐시기로 구한다음 집마다 치킨거리 구하고 총 치킨거리 구해서 또 최소 치킨거리 구하셈 
} 
