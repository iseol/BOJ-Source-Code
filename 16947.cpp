#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[3001];
int p[3001];
bool vis[3001];

bool iscycle[3001];

void dfs(int cur, int prev) {
    vis[cur] = true;
    p[cur] = prev;

    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;

        if (vis[nxt]) {
            int en = cur;
            while (1) {
                iscycle[en] = true;
                en = p[en];
                if (nxt == en) break;
            }
            iscycle[nxt] = true;
            
        } 
        dfs(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        int dist[n+1];
        fill(dist, dist+n+1, -1);

        queue<int> q;
        q.push(i);
        dist[i] = 0;
        if (iscycle[i]) {
            cout << 0 << ' ';
            break;
        }
        [&] () {
            while (!q.empty()) {
                int cur = q.front(); q.pop();

                for (int nxt : adj[cur]) {
                    if (dist[nxt] != -1) continue;
                    dist[nxt] = dist[cur] + 1;

                    if (iscycle[nxt]) {
                        cout << dist[nxt] << ' ';
                        return;
                    }
                    q.push(nxt);
                }
            }
        } ();
    }
}