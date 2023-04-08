#include <iostream>
#include <string>
using namespace std;

string eight[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

int main(void) {
	string str;
	cin >> str;
	
	bool start = true;
	if (str.length() == 1 && str[0]-'0' == 0) cout << "0";
	
	int x = str.length();
	for (int i = 0; i < x; i++) {
		int n = str[i] - '0'; // 8진수 각 자리
		if (start && n < 4) {
			if (n == 0) continue;
			else if (n == 1) cout << "1";
			else if (n == 2) cout << "10";
			else if (n == 3) cout << "11";
			start = false;
		}
		else {
			cout << eight[n];
			start = false;
		}
	}
}
