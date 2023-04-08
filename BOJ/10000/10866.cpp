#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

deque<int> dq;
char command[11];
int n, temp;

void PrintNegativeOne() {
	cout << -1 << endl;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;

		if (!strcmp(command, "push_front")) {
			cin >> temp;
			dq.push_front(temp);
		}
		else if (!strcmp(command, "push_back")) {
			cin >> temp;
			dq.push_back(temp);
		}
		else if (!strcmp(command, "pop_front")) {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else PrintNegativeOne();
		}
		else if (!strcmp(command, "pop_back")) {
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else PrintNegativeOne();
		}
		else if (!strcmp(command, "size")) {
			cout << dq.size() << endl;
		}
		else if (!strcmp(command, "empty")) {
			cout << dq.empty() << endl;
		}
		else if (!strcmp(command, "front")) {
			if (!dq.empty()) {
				cout << dq.front() << endl;
			}
			else PrintNegativeOne();
		}
		else if (!strcmp(command, "back")) {
			if (!dq.empty()) {
				cout << dq.back() << endl;
			}
			else PrintNegativeOne();
		}
	}
}
