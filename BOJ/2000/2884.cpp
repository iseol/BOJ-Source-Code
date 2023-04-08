#include <iostream>

using namespace std;

int h, m;

int main(void) {
	cin >> h >> m;
	
	if (m >= 45) {
		cout << h << ' ' << m - 45 << '\n';
	} else if (h == 0) {
		cout << 23 << ' ' << m + 15 << '\n';
	} else {
		cout << h-1 << ' ' << m + 15 << '\n';
	}
}
