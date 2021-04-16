#include <iostream>
using namespace std;

int a[501][501], d[501][501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
		
	d[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) d[i][j] = d[i-1][j] + a[i][j];
			else if (j == i) d[i][j] = d[i-1][j-1] + a[i][j];
			else d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
		}
	}
	
	int ans = -1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, d[n][i]);
	
	cout << ans << '\n';
}
