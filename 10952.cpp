#include <iostream>
#include <vector>

using namespace std;

int a, b;
vector<int> arr;

int main(void) {
	do {
		cin >> a >> b;
		arr.push_back(a + b);
	} while ((a + b) != 0);
	for (int i = 0; i < arr.size() - 1; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
