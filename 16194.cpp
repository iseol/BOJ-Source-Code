#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int d[1001], p[10001];

int solve(int n) {
	if (n == 0) return 0;
	if (d[n] != INF) return d[n];
	for (int i = 1; i <= n; i++)
		d[n] = min(d[n], solve(n-i) + p[i]);
			
	return d[n];
}

int main(void) {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		cin >> p[i];
	}
	cout << solve(n) << '\n';
	return 0;
}
