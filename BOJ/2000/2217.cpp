#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> rope[i];
	sort(rope+1, rope+n+1, comp);

	int ans = -1;
	for (int i = 1; i <= n; i++) ans = max(ans, rope[i]*i);
	cout << ans;
}
