#include <iostream>
#include <vector>
#include <queue>
#define cost first
#define node second
using namespace std;

constexpr int INF = 987654321;

int d[20001];
vector<pair<int, int>> adj[20001]; // cost, vertex

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;
    fill(d, d+v+1, INF);

    int st;
    cin >> st;
    d[st] = 0;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.node] != cur.cost) continue;
        for (auto nxt : adj[cur.node]) {
            if (nxt.cost + cur.cost < d[nxt.node]) {
                d[nxt.node] = nxt.cost + cur.cost;
                pq.push({nxt.cost + cur.cost, nxt.node});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}