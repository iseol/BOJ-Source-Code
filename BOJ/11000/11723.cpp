#include <iostream>
using namespace std;

int arr[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m;
	cin >> m;
	
	string op;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> op;
		if (op == "add") {
			cin >> x;
			arr[x] = 1;
		}
		if (op == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		if (op == "check") {
			cin >> x;
			cout << arr[x] << '\n';
		}
		if (op == "toggle") {
			cin >> x;
			if (arr[x] == 1) arr[x] = 0;
			else arr[x] = 1;
		}
		if (op == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		if (op == "empty") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
	}
}
