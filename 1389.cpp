#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[101];
int dist[101], ans[101];

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

    for (int i = 1; i <= n; i++) {
        fill(dist, dist+n+1, -1);
        dist[i] = 0;
        
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            ans[i] += dist[j];
        }
    }

    int mn = *min_element(ans+1, ans+n+1);
    for (int i = 1; i <= n; i++) {
        if (ans[i] == mn) {
            cout << i;
            return 0;
        }
    }
}