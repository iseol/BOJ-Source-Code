#include <iostream>

using namespace std;
int n;

int main(void) {
	cin >> n;
	char star = '*';
	
	for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < n - i; j++) {
			 cout << ' ';
		}
		for (int k = 0; k < i; k++) {
			cout << star;
		}
		cout <<  '\n';
	}
}
