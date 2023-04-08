#include <iostream>
#include <math.h>
using namespace std;

int freq1[123]; // 97~122
int freq2[123]; // 97~122

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	if (s1 == s2) {
		cout << 0 << '\n';
		return 0;
	}
	
	for (char c: s1) freq1[c]++;
	for (char c: s2) freq2[c]++;
	
	
	int ans = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		ans += abs(freq1[c]-freq2[c]);
	}

	
	cout << ans << '\n';
}
