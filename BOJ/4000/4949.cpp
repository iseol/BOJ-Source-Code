#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	while (1) {
		string str;
		string brakets = "";
		stack<char> stk;
		bool wrongflag = false;
		
		getline(cin, str);
		if (str == ".") return 0; 
		for (char c: str) {
			if ((c == '(' || c == ')') || (c == '[' || c == ']')) brakets += c;
		}
		for (char c: brakets) {
			if (c == '(' || c == '[') stk.push(c);
			else if (c == ')') {
				if (stk.empty()) wrongflag = true;
				else if (stk.top() == '[') wrongflag = true;
				else if (stk.top() == '(') stk.pop();
			}
			else if (c == ']') {
				if (stk.empty()) wrongflag = true;
				else if (stk.top() == '(') wrongflag = true;
				else if (stk.top() == '[') stk.pop();
			}
		}
		if (!stk.empty()) wrongflag = true;
		if (wrongflag) cout << "no" << '\n';
		else cout << "yes" << '\n';
	}
}
