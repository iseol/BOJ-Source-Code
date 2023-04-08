#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[501];
bool vis[501];

bool dfs(int cur, int prev) {
    vis[cur] = true;

    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;
        if (vis[nxt] || !dfs(nxt, cur)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 0;
    
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            adj[i].erase(adj[i].begin(), adj[i].end());
        }
        fill(vis, vis+n+1, false);

        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dfs(i, 0)) ans++;
        }

        cout << "Case " << ++tc << ": ";
        if (ans >= 2) cout << "A forest of " << ans << " trees.\n";
        else if (ans == 1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
    }
}