#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int stairs;
	cin >> stairs;
	vector<int> a(stairs+1);
	vector<int> d(stairs+1);
	for (int i = 1; i <= stairs; i++) cin >> a[i];
	d[1] = a[1];
	d[2] = a[1] + a[2];
	d[3] = a[3] + max(a[1], a[2]);
	
	for (int i = 4; i <= stairs; i++) {
		d[i] = a[i] + max(d[i-3] + a[i-1], d[i-2]);
	}
	
	cout << d[stairs] << '\n';
}
