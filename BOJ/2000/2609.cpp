#include <iostream>
using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;
	int LCM = a * b;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	int GCD = a;
	
	LCM /= GCD;
	
	cout << GCD << '\n' << LCM << '\n';
}
