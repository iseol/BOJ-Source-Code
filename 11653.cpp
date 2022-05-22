#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	for (long long i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			cout << i << '\n';
		}
	}
	
	if (n != 1) cout << n << '\n';
}
