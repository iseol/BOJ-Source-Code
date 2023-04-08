#include <iostream>

using namespace std;

int n;

int main(void) {
	cin >> n;
	
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= n-i; j++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
}
