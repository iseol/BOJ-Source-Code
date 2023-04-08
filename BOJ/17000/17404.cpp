#include <iostream>
using namespace std;

int a[1001][3], d[1001][3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 2; j++)
			cin >> a[i][j];
	
	int ans = 1000*1000 + 1;
	for (int k = 0; k <= 2; k++) { // first house's color
		for (int i = 0; i <= 2; i++) {
			if (i == k) d[1][i] = a[1][i];
			else d[1][i] = 1000*1000 + 1;
		}
		for (int i = 2; i <= n; i++) {
			d[i][0] = min(d[i-1][1], d[i-1][2]) + a[i][0];
			d[i][1] = min(d[i-1][0], d[i-1][2]) + a[i][1];
			d[i][2] = min(d[i-1][0], d[i-1][1]) + a[i][2];
		}
		for (int i = 0; i <= 2; i++)
			if (i != k) ans = min(ans, d[n][i]); // first house's color can't be equal to last house's color
	}
	cout << ans << '\n';
}
