#include <iostream>
#define MAX 1000000
using namespace std;

int prime[MAX];
int pn;
bool check[MAX+1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[pn++] = i; // 인덱스 0부터 값이 담겨짐 
			for (int j = i+i; j <= MAX; j += i) // i의 배수 모두 삭제 
				check[j] = true;
		}
	}
	
	int n, t = 0;
	int res = 0;
	cin >> t;
	while (t--) { 
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < pn; i++) {
			if (n - prime[i] >= 2 && prime[i] <= n - prime[i]) {
				if (!check[n - prime[i]]) res++;
			}
			else break;
		}
		cout << res << '\n';
		res = 0;
	}
}
