#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int temp;
	int y = 0;
	int m = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		y += ((temp / 30) * 10) + 10;
		m += ((temp / 60) * 15) + 15;
	}
	
	if (m < y) {
		cout << 'M' << ' ' << m << '\n';
	}
	else if (y < m) {
		cout << 'Y' << ' ' << y << '\n';
	}
	else {
		cout << "Y M " << y << '\n';
	}
}
