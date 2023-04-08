#include <iostream>
using namespace std;

int a[10005], d[10005];

int main() {
	int n;
	cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
	d[1] = a[1];
	d[2] = a[1] + a[2];
	
	for (int i = 3; i <= n; i++) {
		d[i] = a[i] + max(d[i-3] + a[i-1], d[i-2]);
        d[i] = max(d[i-1], d[i]);
	}
	
	cout << d[n];
}