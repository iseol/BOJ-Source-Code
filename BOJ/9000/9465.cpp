#include <iostream>
#include <algorithm>
using namespace std;

int a[100001][2];
int d[100001][3];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][0];
		for (int i = 1; i <= n; i++) cin >> a[i][1];
		
		for (int i = 1; i <= n; i++) {
			d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
			d[i][1] = max(d[i-1][0], d[i-1][2]) + a[i][0];
			d[i][2] = max(d[i-1][0], d[i-1][1]) + a[i][1];
		}
		int ans = max({d[n][0], d[n][1], d[n][2]});
		cout << ans << '\n';
	}
}
