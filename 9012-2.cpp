// 스택을 사용하지 않는 방법 
#include <iostream>
#include <string>
using namespace std;

int t;
string ps;
string Valid(string s) {
	int cnt = 0;
	for (char c: s) {
		if (c == '(') cnt++;
		else cnt--;
		
		if (cnt < 0) return "NO";
	}
	
	if (cnt == 0) return "YES";
	else return "NO";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> ps;
		cout << Valid(ps) << '\n';
	}
}
