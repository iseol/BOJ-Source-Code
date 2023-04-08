#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[501];
bool vis[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis[1] = true;
    for (int f : adj[1]) {
        vis[f] = true;
        for (int ff : adj[f]) {
            vis[ff] = true;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res += vis[i];
    cout << res-1;
}