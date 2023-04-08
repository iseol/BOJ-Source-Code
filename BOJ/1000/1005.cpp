#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[1001], d[1001], deg[1001];
vector<int> adj[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) cin >> a[i];
        while (k--) {
            int u, v;
            cin >> u >> v;
            deg[v]++;
            adj[u].push_back(v);
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.push(i);
            d[i] = a[i];
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                d[nxt] = max(d[cur] + a[nxt], d[nxt]);
                if (--deg[nxt] == 0) q.push(nxt);
            }
        }

        int w;
        cin >> w;
        cout << d[w] << '\n';

        for (int i = 1; i <= n; i++) adj[i].erase(adj[i].begin(), adj[i].end());
    }
}