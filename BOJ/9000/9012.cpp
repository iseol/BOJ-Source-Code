#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;

bool IsVPS(string s) {
	stack<char> parenthesis;
	bool flag = true;
	
	for (int i = 0; i < s.length(); i++) {
		char letter = s[i];
		
		if (letter == '(') {
			parenthesis.push(letter);
		}
		
		else {
			if (!parenthesis.empty() && letter == ')') {
				parenthesis.pop();
			}
			else if (parenthesis.empty() && letter == ')') {
				flag = false;
				break;
			}
		}
	}
	if (parenthesis.empty() && flag) return true;
	else return false;
	
}

int main(void) {
	cin >> n;
	string s;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (IsVPS(s)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
