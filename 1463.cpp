#include <iostream>
using namespace std;

int dp[1000001];

int min(int a, int b) { return a > b ? b : a; }

int func(int n) {
	if (n == 1) return 0;
	if (dp[n] > 0) return dp[n];
	
	dp[n] = func(n-1) + 1;
	if (n % 2 == 0) {
		dp[n] = min(dp[n], func(n/2) + 1);
	}
	if (n % 3 == 0) {
		dp[n] = min(dp[n], func(n/3) + 1);
	}
	return dp[n];
}

int main(void) {
	int n;
	cin >> n;
	
	cout << func(n) << '\n';
}
