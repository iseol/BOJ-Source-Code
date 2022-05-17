#include <iostream>
#include <algorithm>
using namespace std;

char arr[15];

bool isvowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	else return false;
}

int main() {
	int l, c;
	cin >> l >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+c);
	
	int a[15];
	fill(a, a+c, 1);
	fill(a, a+l, 0);
	
	string pass = "";
	do {
		for (int i = 0; i < c; i++) {
			if (a[i] == 0) {
				if (i == 0) {
					pass += arr[i];
					continue;
				}
				pass += arr[i];
			}
		}
		
		int vow = 0;
		int con = 0;
		for (int i = 0; i < l; i++) {
			if (isvowel(pass[i])) vow++;
			else con++;
		}
		if (vow >= 1 && con >= 2) cout << pass << '\n';
		pass = "";
	} while (next_permutation(a, a+c));
}
