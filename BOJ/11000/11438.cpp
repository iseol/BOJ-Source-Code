#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int depth[100001];
int parent[100001][18];

void treedfs(int cur) {
    for (int nxt : adj[cur]) {
        if (depth[nxt] != -1) continue;
        parent[nxt][0] = cur;
        depth[nxt] = depth[cur] + 1;
        treedfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    fill(depth, depth+n+1, -1);
    for (int i = 0; i <= n; i++) fill(parent[i], parent[i]+18, -1);
    depth[1] = 0;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    treedfs(1);

    for (int j = 0; j < 17; j++) {
        for (int i = 2; i <= n; i++) {
            if (parent[i][j] != -1) parent[i][j+1] = parent[parent[i][j]][j]; 
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int j = 0; diff; j++) {
            if (diff % 2) u = parent[u][j];
            diff /= 2;
        }

        if (u != v) {
            for (int j = 17; j >= 0; j--) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout << u << '\n';
    }
}