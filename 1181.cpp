#include <iostream>
#include <algorithm>

using namespace std;

string str[20000];
int n;

bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	} else if (a.length() > b.length()) {
		return 0;
	}
	// 사전순
	else {
		return a < b;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str+n, compare);
	
	for (int i = 0; i < n; i++) {
		if (i > 0 && str[i] == str[i-1]) { // 같은 단어 pass 
			continue;
		}
		else {
			cout << str[i] << '\n';
		}
	}
	return 0;
	
}
