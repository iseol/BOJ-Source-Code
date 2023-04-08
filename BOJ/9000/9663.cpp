#include <iostream>
using namespace std;

int n;
int cnt = 0;
int isused1[14]; // y
int isused2[27]; // x+y
int isused3[27]; // x-y+n-1

void sol(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!isused1[i] && !isused2[i+cur] && !isused3[i-cur+n-1]) {
			isused1[i] = true;
			isused2[i+cur] = true;
			isused3[i-cur+n-1] = true;
			sol(cur+1);
			isused1[i] = false;
			isused2[i+cur] = false;
			isused3[i-cur+n-1] = false;
		}
	}
	
}

int main() {
	cin >> n;
	sol(0);
	cout << cnt << '\n';
}
