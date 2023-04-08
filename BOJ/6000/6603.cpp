#include <iostream>
using namespace std;

int n;
int arr[12];
int res[12];
bool isused[12];

void sol(int k) {
	if (k == 6) {
		for (int i = 0; i < 6; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			if (k == 0) {
				isused[i] = true; // arr[i]°¡ »ç¿ëµÊ
				res[k] = arr[i];		 
				sol(k+1);
				isused[i] = false;
			}
			else if (arr[i] > res[k-1]) {
				isused[i] = true; // arr[i]°¡ »ç¿ëµÊ
				res[k] = arr[i];		 
				sol(k+1);
				isused[i] = false;
			}
		}
	}
}

int main() {
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sol(0);
		fill(isused, isused+12, false);
		cout << '\n';
	}
}
