#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool flag = true;
int n, _max(0);
int x;
stack<int> s;
vector<char> ans;


int main(void) {
	ans.reserve(250001);
	
	cin >> n;
	while (n--) {
		cin >> x;
		
		if (x > _max) {
			for (int i = _max+1; i <= x; i++) {
				s.push(i);
				ans.push_back('+');
			}
		}
		else {
			if (x != s.top()) {
				flag = false;
				continue;
			}
		}
		s.pop();
		ans.push_back('-');
		if (x > _max) _max = x;
	}
	
	if (flag) {
		for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
		}
	}
	else cout << "NO" << endl;
}
