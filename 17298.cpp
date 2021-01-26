#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	int seq[n]; // 수열 
	vector<int> ans(n); // 오큰수 
	
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	stack<int> s;
	s.push(0); // 예외 (인덱스로 들어갈 수) 
	
	for (int i = 1; i < n; i++) {
		if (s.empty()) s.push(i);
		
		while (!s.empty() && seq[s.top()] < seq[i]) { // 스택에 있는 수들의 오큰수 찾기 
			ans[s.top()] = seq[i];
			s.pop();
		}
		s.push(i); // 수 스택에 넣기
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << '\n';
}
