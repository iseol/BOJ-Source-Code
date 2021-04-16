#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	vector<int> d1(n+1);
	for (int i = 1; i <= n; i++) {
		d1[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i] && d1[i] < d1[j]+1) {
				d1[i] = d1[j]+1;
			}
		}
	}
	
	vector<int> d2(n+1);
	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int j = i+1; j <= n; j++) {
			if (a[j] < a[i] && d2[i] < d2[j]+1) {
				d2[i] = d2[j]+1;
			}
		}
	}
	
	int ans = -1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, d1[i]+d2[i]-1);
	
	cout << ans << '\n';
	
}
