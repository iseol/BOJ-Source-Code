#include <iostream>

using namespace std;

int a, b;

int main(void) {
	cin >> a >> b;
	
	if (a > b) {
		cout << ">";
	} else if (a < b) {
		cout << "<";
	} else {
		cout << "==";
	}
}
