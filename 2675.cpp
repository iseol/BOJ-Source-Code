#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	string s;
	int n;
	while (t--) {
		cin >> n >> s;
		for (char c: s) {
			for (int i = 0; i < n; i++) cout << c;
		}
		cout << '\n';
	}
}
