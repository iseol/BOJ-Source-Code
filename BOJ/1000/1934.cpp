#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	int r = a % b;
	return gcd(b, r);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	int a, b;
	while (t--) {
		cin >> a >> b;
		cout << (a*b) / gcd(a, b) << '\n';
	}
}
