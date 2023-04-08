#include <iostream>
using namespace std;

int a[1000], d[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + a[i]) {
				d[i] = d[j] + a[i];
			}
		}
	}
	
	int ans = -1;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	
	cout << ans << '\n';
}
