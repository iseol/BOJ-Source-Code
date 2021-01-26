#include <iostream>
#include <algorithm>
using namespace std;

int d[1001], p[10001];

int solve(int n) {
	if (n == 0) return 0;
	if (d[n] > 0) return d[n];
	
	// i는 카드팩에 있는 카드의 개수
	 
	for (int i = 1; i <= n; i++)
		d[n] = max(d[n], solve(n-i) + p[i]);
	return d[n];
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
		
	cout << solve(n) << '\n';
}
