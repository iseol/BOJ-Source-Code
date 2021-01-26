#include <iostream>
#include <string>
using namespace std;

int cnt[91]; // cnt[65] ~ cnt[90]까지 활용 

int main(void) {
	string s;
	cin >> s;
	
	for (char c: s) {
		if ('a' <= c) c -= 32;
		cnt[c]++;
	}
	int MAX = -1;
	char c = '?';
	for (int letter = 'A'; letter <= 'Z'; letter++) {
		if (cnt[letter] > MAX) {
			MAX = cnt[letter];
			c = letter;
		}
		else if (cnt[letter] == MAX) {
			c = '?';
		}
	}
	cout << c << '\n';
	return 0;
}
