#include <iostream>

using namespace std;

char str[101];

int main() {
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i];
		if ((i+1) % 10 == 0) cout << '\n';
	}
}
