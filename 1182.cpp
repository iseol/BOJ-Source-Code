#include <iostream>
using namespace std;

int arr[20];
int cnt = 0;
int n, s;

void sol(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}
	sol(cur+1, tot+arr[cur]);
	sol(cur+1, tot);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sol(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}
