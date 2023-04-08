#include <iostream>

using namespace std;

int n;

int fact(int n) {
	if (n <= 1) return 1;
	
	if (n < 2)
		return n;
	else 
		return n * fact(n - 1);
}

int main(void) {
	cin >> n;
	
	cout << fact(n) << endl;
}
