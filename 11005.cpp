#include <iostream>
#include <stack>
using namespace std;

stack<int> ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, b; // 나누어질 수, 진법 
	cin >> n >> b;
	
	int x;
	while (true) {
		if (n == 0) break;
		ans.push(n%b);
		n /= b;
	}
	while (!ans.empty()) {
		ans.top() < 10 ? cout << ans.top() : cout << static_cast<char>(ans.top() + 55);
		ans.pop();
	}
	cout << '\n';
}
