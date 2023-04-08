#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void sol(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			sol(k+1);
			isused[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	sol(0);
}
