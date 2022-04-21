#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if ((k != i) && (k != j)) {
					sum += arr[k];
				}
			}
			if (sum == 100) {
				arr[i] = 0;
				arr[j] = 0;
				sort(arr, arr + 9);
				
				for (int c = 2; c < 9; c++) {
					cout << arr[c] << '\n';
				}
				return 0;
			}
		}
	}
}
