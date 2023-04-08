#include <iostream>
#include <algorithm>
using namespace std;

int a[100001] = {-1001};
int d[100001] = {-1001};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = d[0];
	for (int i = 1; i <= n; i++) {
		d[i] = max(a[i], a[i] + d[i-1]);
		ans = max(ans, d[i]);
	}
	
	cout << ans;
}
