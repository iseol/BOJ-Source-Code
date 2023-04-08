#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    deque<int> dq;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    while (m--) {
    	int t;
    	cin >> t;
    	int idx = find(dq.begin(), dq.end(), t) - dq.begin();
    	
    	while (dq.front() != t) {
    		if (idx < dq.size() - idx) {
    			dq.push_back(dq.front());
    			dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans++;
		}
		dq.pop_front();
	}
	cout << ans << '\n';
}
