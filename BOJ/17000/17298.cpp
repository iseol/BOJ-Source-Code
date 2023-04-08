#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	int seq[n]; // ���� 
	vector<int> ans(n); // ��ū�� 
	
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	stack<int> s;
	s.push(0); // ���� (�ε����� �� ��) 
	
	for (int i = 1; i < n; i++) {
		if (s.empty()) s.push(i);
		
		while (!s.empty() && seq[s.top()] < seq[i]) { // ���ÿ� �ִ� ������ ��ū�� ã�� 
			ans[s.top()] = seq[i];
			s.pop();
		}
		s.push(i); // �� ���ÿ� �ֱ�
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << '\n';
}
