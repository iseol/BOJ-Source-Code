#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	cout << sum/5 << '\n';
	
	sort(arr, arr+5);
	cout << arr[2] << '\n';
}

