#include <iostream>
using namespace std;

int d[1000002];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= 1000001; i++)
		d[i] = (d[i-1] + d[i-2])%15746;
	
	int n;
	cin >> n;
	cout << d[n+1] << '\n';
	return 0;
}
