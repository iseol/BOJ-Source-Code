#include <iostream>
using namespace std;

int d[11];

int main(void) {
	d[0] = 1;
	for (int i = 1; i <= 10; i++) {
		if (i-1 >= 0) d[i] += d[i-1];
		if (i-2 >= 0) d[i] += d[i-2];
		if (i-3 >= 0) d[i] += d[i-3];
	}
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	int n;
	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}
	return 0;
}
