#include <iostream>

using namespace std;

int n;

int main(void) {
	cin >> n;
	
	for (int i = n; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			cout << '*';
		}
		cout << '\n';
	}
}
