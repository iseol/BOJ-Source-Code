#include <iostream>
#include <stack>
using namespace std;

int ans[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	int tower[n+1];

	
	for (int i = 1; i <= n; i++) {
		cin >> tower[i];
	}
	
	stack<int> s;
	s.push(n);
	
	for (int i = n; i > 0; i--) {
		while (!s.empty() && tower[s.top()] < tower[i]) {
			ans[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
