#include <iostream>
#include <vector>
using namespace std;

int t, na, nb;
vector<int> a;
vector<int> b;

int main(void) {
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		cin >> na >> nb;
		a.push_back(na);
		b.push_back(nb);
	}
	for (int i = 0; i < t; ++i) {
		cout << a[i]+b[i] << "\n";
	}
	return 0;	
}
