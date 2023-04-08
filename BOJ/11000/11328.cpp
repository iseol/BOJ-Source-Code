#include <iostream>
#include <algorithm>
using namespace std;

int freq1[123]; // freq1[97] ~ freq1[122]
int freq2[123]; // freq2[97] ~ freq2[122]

int main() {
	int t;
	cin >> t;
	
	
	string s1, s2;
	while (t--) {
		bool possible = true;
		cin >> s1 >> s2;
		for (char c: s1) freq1[c]++;
		for (char c: s2) freq2[c]++;
		for (char c = 'a'; c <= 'z'; c++) {
			if (freq1[c] != freq2[c]) {
				possible = false;
				break;
			}
		} 
		
		if (possible) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
		fill(freq1+97, freq1+123, 0);
		fill(freq2+97, freq2+123, 0);
	}
}
