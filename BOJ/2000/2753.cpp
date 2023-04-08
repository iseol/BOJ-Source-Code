#include <iostream>

using namespace std;

int year;

int main(void) {
	cin >> year;
	
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		cout << true;
	}
	else {
		cout << false;
	}
}
