#include <iostream>
using namespace std;

int MIN = 1000001, MAX;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	int temp;
	while (t--) {
		cin >> temp;
		if (temp < MIN) MIN = temp;
		if (temp > MAX) MAX = temp;
	}
	
	cout << MIN*MAX << '\n';
}
