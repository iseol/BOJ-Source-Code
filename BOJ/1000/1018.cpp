#include <iostream>
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

int white_count(int x, int y) {
    int cnt = 0;
    for (int i = x; i < x + 8; i++)
    	for (int j = y; j < y + 8; j++)
            if (chess[i][j] != white_chess[i - x][j - y]) cnt++;
	return cnt;
}

int black_count(int x, int y) {
    int cnt = 0;
    for (int i = x; i < x + 8; i++)
        for (int j = y; j < y + 8; j++)
            if (chess[i][j] != black_chess[i - x][j - y]) cnt++;
    return cnt;
}

int main() {
	int n, m; 
	cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> chess[i];

    int res = INF;
    for (int i = 0; i + 7 < n; i++)
    	for (int j = 0; j + 7 < m; j++)
            res = min({res, white_count(i, j), black_count(i, j)});

    cout << res;
}
