#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> adj[32001];
int deg[32001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';

        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) pq.push(nxt);
        }
    }


}