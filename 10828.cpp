#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> s; // ���� 
string command;
int n, temp; // ��� ����, push�� �ӽú���

int main(void) {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> command;
		
		if (command == "push") {
			cin >> temp;
			s.push(temp);
		}
		else if (command == "pop") {
			
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "size") {
			
			cout << s.size() << endl;
		}
		else if (command == "empty") {
			
			cout << s.empty() << endl;
		}
		else if (command == "top") {
		
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
