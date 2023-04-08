#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dist[200001];

int main() {
	fill(dist, dist+200001, -1);
	
	int n, k;
	cin >> n >> k;
	
	queue<int> q;
	q.push(n);
	
	dist[n] = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur*2 >= 0 && cur*2 <= 200000 && dist[cur*2] == -1) {
			dist[cur*2] = dist[cur];
			q.push(cur*2);
		}
		if (cur-1 >= 0 && cur-1 <= 200000 && dist[cur-1] == -1) {
			dist[cur-1] = dist[cur] + 1;
			q.push(cur-1);
		}
		if (cur+1 >= 0 && cur+1 <= 200000 && dist[cur+1] == -1) {
			dist[cur+1] = dist[cur] + 1;
			q.push(cur+1);
		}
	}
	cout << dist[k];
}
