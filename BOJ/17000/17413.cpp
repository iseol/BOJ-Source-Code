#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<char> &s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main(void) {
	string str;
	getline(cin, str);
	
	bool tag = false;
	stack<char> s;
	for (char c: str) {
		if (c == '<') { // <
			print(s);
			tag = true;
			cout << c;
		}
		else if (c == '>') { // >
			tag = false;
			cout << c;
		}
		else if (tag) { // �±� �� 
			cout << c;
		}
		else {
			if (c == ' ') { // �±� ��, ���� 
				print(s);
				cout << c;
			}
			else { // �±� ��, ���� 
				s.push(c);
			}
		}
	}
	print(s);
	cout << '\n';
}
