#include <iostream>

using namespace std;

int a, b;
int testcases;

int main() {
	cin >> testcases;
	
	while (testcases) {
		cin >> a;
		cin.ignore(1, ',');
		cin >> b;
		
		cout << a+b << '\n';
		testcases--;
	}
}
