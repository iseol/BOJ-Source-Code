#include <iostream>
using namespace std;

typedef long long ll;
bool isprime[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> m >> n;

	fill(isprime, isprime+n+1, true);
	isprime[1] = false; // erathos
	for (ll i = 2; i <= n; i++) {
		if (isprime[i]) {
			for (ll j = i*i; j <= n; j += i) isprime[j] = false;
		}
	}
	
	for (int i = m; i <= n; i++) {
		if (isprime[i]) cout << i << '\n';
	}
}