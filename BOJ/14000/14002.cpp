#include <iostream>
#include <algorithm>
using namespace std;

int A[1001], d[1001], v[1001];

void yee(int p) {
	if (p == 0) return;
	yee(v[p]);
	cout << A[p] << ' ';
}

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	fill(d, d+1000, 1);
	
	for (int i = 1; i <= N; i++) {
		for (int j = i-1; j >= 1; j--) {
			if (A[i] > A[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			} 
		}
	}
	int ans = -1;
	int p = 0;
	for (int i = 1; i <= N; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i; // 역추적을 시작하는 인덱스(ans의 인덱스) 
		}
	}
	cout << ans << '\n';
	yee(p);
	cout << '\n';
}
