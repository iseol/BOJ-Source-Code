#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int dis[200002];
	fill(dis, dis+200002, -1);
	
	int n, k;
	cin >> n >> k;
	queue<int> q;
	
	q.push(n);
	dis[n] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		if (cur-1 >= 0 && dis[cur-1] < 0) {
			dis[cur-1] = dis[cur] + 1;
			q.push(cur-1);
		}
		if (cur+1 <= 100000 && dis[cur+1] < 0) {
			dis[cur+1] = dis[cur] + 1;
			q.push(cur+1);
		}
		if (cur*2 <= 100000 && dis[cur*2] < 0) {
			dis[cur*2] = dis[cur] + 1;
			q.push(cur*2);
		}
	}
	
	cout << dis[k] << '\n';
	
}
