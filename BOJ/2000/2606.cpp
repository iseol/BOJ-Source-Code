#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101];
bool vis[101];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = true;
    for (int nxt : adj[cur]) dfs(nxt);
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    int res = 0;
    for (int i = 1; i <= n; i++) res += vis[i];
    cout << res-1;
}