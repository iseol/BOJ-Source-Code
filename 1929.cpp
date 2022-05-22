#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> m >> n;
	
	vector<bool> isprime(n+1, true);
	isprime[1] = false; 
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			for (long long j = (long long)i*(long long)i; j <= n; j += i) isprime[j] = false;
		}
	}
	
	for (int i = m; i <= n; i++) {
		if (isprime[i]) cout << i << '\n';
	}
}
