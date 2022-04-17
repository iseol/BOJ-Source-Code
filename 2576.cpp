#include <iostream>
using namespace std;

int main() {
	int tmp;
	int MIN = 101;
	int total = 0;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if ((tmp % 2) == 1) {
			if (tmp < MIN) {
				MIN = tmp;
			}
			total += tmp;
		}
	}
	if (total == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << total << '\n' << MIN << '\n';
	}
}
