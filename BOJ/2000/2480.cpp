#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	if ((arr[0] == arr[1]) && (arr[1] == arr[2])) {
		cout << 10000+(arr[0]*1000) << '\n';
	}
	else if (arr[0] == arr[1]) {
		cout << 1000+(arr[0]*100) << '\n';
	}
	else if (arr[1] == arr[2]) {
		cout << 1000+(arr[1]*100) << '\n';
	}
	else if (arr[2] == arr[0]) {
		cout << 1000+(arr[2]*100) << '\n';
	}
	else {
		cout << (*max_element(arr, arr+3))*100 << '\n';
	}
}
