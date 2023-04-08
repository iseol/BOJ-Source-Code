#include <iostream>
using namespace std;

int a[100];
int d[10001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	d[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= a[i]) d[j] += d[j-a[i]];
		}
	}
	
	cout << d[k];
}
