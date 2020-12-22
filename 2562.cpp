#include <iostream>

int max = 0;
int num;
int arr[9];

int main(void) {
	for (int i = 0; i < 9; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) max = arr[i];
	}
	for (int i = 0; i < 9; i++) {
		if (max == arr[i]) num = i+1;
	}
	std::cout << max << '\n' << num << '\n';
}
