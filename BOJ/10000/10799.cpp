#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<char> idxstack;
stack<char> s;
int cnt;
int idx;

int main(void) {
	idxstack.reserve(1000);
	string str;
	cin >> str;
	
	for (char c: str) {
		if (c == '(') {
			s.push(c);
			idxstack.push_back(c);
			idx++;
		}
		else if (idxstack[idx-1] != '(' && c == ')') {
			s.pop();
			idxstack.push_back(c);
			cnt++;
			idx++;
		}
		else if (s.top() == '(' && c == ')') {
			s.pop();
			idxstack.push_back(c);
			cnt += s.size();
			idx++;
		}
	}
	
	cout << cnt << '\n';
}
