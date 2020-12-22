#include <iostream>
using namespace std;
int n, b, x;

int main(void) {
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		cin >> b;
		
		if (b < x) {
			cout << b << ' ';
		}
	}
	cout << '\n';
}
