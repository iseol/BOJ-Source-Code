#include <iostream>
#include <vector>
#include <queue>
#define node first
#define cost second
using namespace std;

vector<pair<int, int>> adj[1001];
bool vis[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int u, v, c;
    for (int i = 1; i <= n-1; i++) {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    while (m--) {
        queue<pair<int, int>> q;
        cin >> u >> v;
        q.push({u, 0});
        vis[u] = true;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.node == v) {
                cout << cur.cost << '\n';
                break;
            }
            
            for (auto nxt : adj[cur.node]) {
                if (vis[nxt.node]) continue;
                vis[nxt.node] = true;
                q.push({nxt.node, cur.cost+nxt.cost});
            }
        }
        fill(vis, vis+n+1, false);
    }
}