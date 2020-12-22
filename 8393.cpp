#include <iostream>

using namespace std;

int n, result;

int main(void) {
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		result += i;
	}
	cout << result << endl;
	return 0;
}
