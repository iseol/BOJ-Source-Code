#include <iostream>
using namespace std;

void sol(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	sol(a, 6-a-b, n-1);
	cout << a << ' ' << b << '\n';
	sol(6-a-b, b, n-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	cout << (1<<n) - 1 << '\n';
	sol(1, 3, n);
}
