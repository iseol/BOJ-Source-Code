#include <iostream>
using namespace std;

bool IsPrime(int n) {
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	int n;
	int cnt = 0;
	cin >> n;
	
	int num;
	while (n--) {
		cin >> num;
		if (IsPrime(num)) cnt++;
	}
	
	cout << cnt << '\n';
}
