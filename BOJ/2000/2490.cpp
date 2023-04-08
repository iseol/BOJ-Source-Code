#include <iostream>
using namespace std;

int main() {
	int arr[4];
	for (int k = 1; k <= 3; k++) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			cin >> arr[i];
			if (arr[i] == 0) {
				cnt++;
			}
		}
		if (cnt == 0) {
			cout << 'E' << '\n';
		}
		else {
			cout << static_cast<char>(cnt+64) << '\n';
		}	
	}
}
