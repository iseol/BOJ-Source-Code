#include <iostream>
#include <string>
using namespace std;

int freq[9];

int main() {
	string s;
	cin >> s;
	
	int temp;
	for (char c: s) {
		temp = c - '0';
		if (temp == 9) freq[6]++;
		else freq[temp]++;
	}
	
	if ((freq[6] % 2) == 0) freq[6] = freq[6] / 2;
	else freq[6] = (freq[6] / 2) + 1;
	
	int MAX = -1;
	int idx;
	for (int i = 0; i < 9; i++) {
		if (freq[i] > MAX) MAX = freq[i];
	}
	
	cout << MAX << '\n';
}
