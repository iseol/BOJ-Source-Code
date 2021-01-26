#include <iostream>
using namespace std;

int d[11];

int solve(int n) {
	if (n < 0) return 0;
	if (n <= 1) return 1;
	if (d[n] > 0) return d[n];
	d[n] = solve(n - 3) + solve(n - 2) + solve(n - 1);
	return d[n];
} 

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}
