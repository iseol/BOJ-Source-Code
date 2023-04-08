#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	int n;
	cin >> n;
	
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 0) s.pop();
		else s.push(temp);
	}
	
	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	
	cout << ans << '\n';
}
