#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 987654321;

string chess[50];

string white_chess[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string black_chess[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int WhiteCnt(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++)
    	for (int j = x; j < x + 8; j++)
            if (chess[i][j] != white_chess[i - y][j - x]) cnt++;
	return cnt;
}

int BlackCnt(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++)
        for (int j = x; j < x + 8; j++)
            if (chess[i][j] != black_chess[i - y][j - x]) cnt++;
    return cnt;
}

int main(void) {
	int n, m; // 세로, 가로 
	cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> chess[i];

    int res = INF;
    for (int i = 0; i + 7 < n; i++)
    	for (int j = 0; j + 7 < m; j++)
            res = min({res, WhiteCnt(i, j), BlackCnt(i, j)});

    cout << res << endl;
}
