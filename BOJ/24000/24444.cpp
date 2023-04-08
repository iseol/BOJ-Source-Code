#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[100005];
int vis[100005];
int id = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    while (m--) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), [&] (int a, int b) {return a > b;});

    queue<int> q;
    q.push(r); vis[r] = ++id;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = ++id;
                q.push(nxt);
            }
            
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << vis[i] << '\n';
    }
}