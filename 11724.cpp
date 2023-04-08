#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            ans++;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int v: adj[cur]) {
                    if (vis[v]) continue;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    cout << ans;
}