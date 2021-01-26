#include <iostream>
using namespace std;

long long d[100001][4];
const int mod = 1e9 + 9;
const int maxn = 100000;

void solve(void) {
	for (int i = 1; i <= maxn; i++) {
		if (i-1 >= 0) {
			d[i][1] = (d[i-1][2] + d[i-1][3]) % mod;
			if (i == 1) d[i][1] = 1;
		}
		if (i-2 >= 0) {
			d[i][2] = (d[i-2][1] + d[i-2][3]) % mod;
			if (i == 2) d[i][2] = 1;
		}
		if (i-3 >= 0) {
			d[i][3] = (d[i-3][1] + d[i-3][2]) % mod;
			if (i == 3) d[i][3] = 1;
		}
	}
}
int main(void) {
	solve();
	
	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
	}
	return 0;
}
