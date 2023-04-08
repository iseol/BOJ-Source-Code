#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> arr;
	int x;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		arr.push_back(x % 42);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	
	cout << arr.size() << '\n';
	return 0;
}
