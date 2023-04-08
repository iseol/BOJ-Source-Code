#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	 
	long long int a, b;
	cin >> a >> b;
	
	if (a < b) {
		cout << abs(b - a) - 1 << '\n';
		for (long long int i = a+1; i < b; i++) {
			cout << i << ' ';
		}
	}
	else if (a > b) {
		cout << abs(b - a) - 1 << '\n';
		for (long long int i = b+1; i < a; i++) {
			cout << i << ' ';
		}
	}
	else {
		cout << 0 << '\n';
	}
}
