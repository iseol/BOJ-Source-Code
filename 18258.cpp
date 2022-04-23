#include <iostream>
#include <queue> 
using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (s == "pop") {
			if (q.empty()) cout << -1 << '\n';
				else {
					cout << q.front() << '\n';
					q.pop();
				}
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}	
	}
}
