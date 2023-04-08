#include <iostream>
using namespace std;

int arr[8];
int isused[9];
int n, m;

void sol(int k) { // arr[k]에 수를 넣는 함수
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	} 
	
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			if (k == 0) {
				isused[i] = true;
				arr[k] = i;
				sol(k+1);
				isused[i] = false;
			}
			else if (i > arr[k-1]) {
				isused[i] = true;
				arr[k] = i;
				sol(k+1);
				isused[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	sol(0);
}
