#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	
	int mn = 10001;
	int temp;
	
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		mn = min(mn, temp);
	}
	cout << (long long)mn * (long long)n; 
}
