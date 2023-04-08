#include <iostream>
using namespace std;

int main(void) {
	int x;
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		ans += x*x;
	}
	cout << ans%10 << '\n';
	return 0;
}
