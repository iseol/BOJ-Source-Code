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
	
	int m = 0; // ���ÿ� �� ������ �� 
	
	int x;
	while (n--) {
		cin >> x;
		if (x > m) {
			while (x > m) { // m < ������ �ϴ� �� 
				s.push(++m);
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else {
			bool found = false;
			if (!s.empty()) { // m == ������ �ϴ� ��
				int top = s.top();
				s.pop();
				ans += '-';
				if (x == top) { 
					found = true;
				}
			}
			if (!found) { // m > ������ �ϴ� �� 
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	
	for (char c: ans) {
		cout << c << '\n';
	}
}
