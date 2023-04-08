#include <iostream>
using namespace std;

int a[301], d[301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int s;
	cin >> s;
	for (int i = 1; i <= s; i++) cin >> a[i];

	d[1] = a[1];
	d[2] = a[1] + a[2];
	d[3] = a[3] + max(a[1], a[2]);
	
	for (int i = 4; i <= s; i++) d[i] = a[i] + max(d[i-3] + a[i-1], d[i-2]);
	
	cout << d[s];
}
