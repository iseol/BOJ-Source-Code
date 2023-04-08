#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dist[1000001];

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	
	fill(dist, dist+f+1, -1);
	
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	
	while (!q.empty()) {
		int cur = q.front(); q.pop(); 
		if (cur+u <= f && dist[cur+u] == -1) {
			dist[cur+u] = dist[cur] + 1;
			q.push(cur+u);
		}
		if (cur-d > 0 && dist[cur-d] == -1) {
			dist[cur-d] = dist[cur] + 1;
			q.push(cur-d);
		}
	}
	
	if (dist[g] == -1) cout << "use the stairs" << '\n';
	else cout << dist[g] << '\n';
}
