#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string ans;
stack<int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	
	int m = 0; // 스택에 들어간 마지막 수 
	
	int x;
	while (n--) {
		cin >> x;
		if (x > m) {
			while (x > m) { // m < 만들어야 하는 수 
				s.push(++m);
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else {
			bool found = false;
			if (!s.empty()) { // m == 만들어야 하는 수
				int top = s.top();
				s.pop();
				ans += '-';
				if (x == top) { 
					found = true;
				}
			}
			if (!found) { // m > 만들어야 하는 수 
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	
	for (char c: ans) {
		cout << c << '\n';
	}
}
