#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> q; // 큐우우우우우 
string command; // 명령어 
int n, temp; // 명령어 개수, push용 임시 변수 

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		
		if (command == "push") {
			cin >> temp;
			q.push(temp);
		}
		else if (command == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			cout << q.empty() << endl;
		}
		else if (command == "front") {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "back") {
			if (!q.empty()) {
				cout << q.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	} 
}
