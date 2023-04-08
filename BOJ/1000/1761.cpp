#include <iostream>
#include <vector>
#define node first 
#define cost second
using namespace std;

vector<pair<int, int>> adj[40001];
int depth[40001];
int parent[40001][17];

int dist[40001];

void treedfs(int cur) {
    for (auto nxt : adj[cur]) {
        if (depth[nxt.node] != -1) continue;
        parent[nxt.node][0] = cur;
        depth[nxt.node] = depth[cur] + 1;
        dist[nxt.node] = dist[cur] + nxt.cost;
        treedfs(nxt.node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    fill(depth, depth+n+1, -1);
    for (int i = 0; i <= n; i++) fill(parent[i], parent[i]+17, -1);
    depth[1] = 0;

    for (int i = 0; i < n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    treedfs(1);

    for (int j = 0; j < 16; j++) {
        for (int i = 2; i <= n; i++) {
            if (parent[i][j] != -1) parent[i][j+1] = parent[parent[i][j]][j]; 
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        int uu, vv;
        cin >> u >> v;
        uu = u; vv = v;
        
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int j = 0; diff; j++) {
            if (diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if (u != v) {
            for (int j = 16; j >= 0; j--) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        int lca = u;
        cout << (dist[uu] - dist[lca]) + (dist[vv] - dist[lca]) << '\n';
    }
}