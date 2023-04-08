#include <iostream>
using namespace std;

int arr[100];
long long int ans;

int gcd(int a, int b) {
	if (b == 0) return a;
	int r = a % b;
	return gcd(b, r);
}

int main(void) {
	int tc, n;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
			
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				ans += gcd(arr[i], arr[j]);
		cout << ans << '\n';
	}
}
