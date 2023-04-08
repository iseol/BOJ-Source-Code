#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;

bool comp(int a, int b) {
	return a > b;
}

int main(void) {
	
	int a[50], b[50];
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
		
	sort(a, a + n);
	
	sort(b, b + n, comp);
	
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
	cout << ans << endl;
}
