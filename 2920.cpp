#include <iostream>
using namespace std;

int arr[9];

int main(void) {
	for (int i = 1; i <= 8; i++) cin >> arr[i];
	
	bool ascending_flag = true;
	for (int i = 1; i <= 8; i++) {
		if (arr[i] != i) {
			ascending_flag = false;
			break;
		}
	}
	if (ascending_flag) {
		cout << "ascending" << '\n';
		return 0;
	}
	bool descending_flag = true;
	int index = 1;
	for (int i = 8; i >= 1; i--) {
		if (arr[index] != i) {
			descending_flag = false;
			break;
		}
		index++;
	}
	if (descending_flag) {
		cout << "descending" << '\n';
		return 0;
	}
	cout << "mixed" << '\n';
	return 0;
}
