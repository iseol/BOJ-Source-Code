#include <iostream>
#define MAX 1000000
using namespace std;

typedef long long ll;

int prime[MAX];
int pn;
bool isprime[MAX+1];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fill(isprime+2, isprime+MAX, true);

	for (ll i = 2; i <= MAX; i++) {
		if (isprime[i]) {
			prime[pn++] = i; // 인덱스 0부터 값이 담겨짐
			for (ll j = i*i; j <= MAX; j += i) // i의 배수 모두 삭제 
				isprime[j] = false;
		}
	}
	
	int n;
	int tc;
	int res = 0;

	cin >> tc;
	while (tc--) { 
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < pn; i++) {
			if (n - prime[i] >= 2 && prime[i] <= n - prime[i]) {
				if (isprime[n - prime[i]]) res++;
			}
			else break;
		}

		cout << res << '\n';
		res = 0;
	}
}
