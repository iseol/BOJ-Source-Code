#include <iostream>
#include <string>
#include <stack>
using namespace std;

int m;
string s;
stack<char> left_stack, right_stack;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> s;
	for (char c: s) left_stack.push(c);
	
	cin >> m;
	char what;
	char letter;
	while (m--) {
		cin >> what;
		switch (what) {
			case 'L':
				if (!left_stack.empty()) {
					right_stack.push(left_stack.top());
					left_stack.pop();
				}
				break;
			case 'D':
				if (!right_stack.empty()) {
					left_stack.push(right_stack.top());
					right_stack.pop();
				}
				break;
			case 'B':
				if (!left_stack.empty()) {
					left_stack.pop();
				}
				break;
			case 'P':
				cin >> letter;
				left_stack.push(letter);
				break;
		}
	}
	while (!left_stack.empty()) {
		right_stack.push(left_stack.top());
		left_stack.pop();
	}
	while (!right_stack.empty()) {
		cout << right_stack.top();
		right_stack.pop();
	}
}
