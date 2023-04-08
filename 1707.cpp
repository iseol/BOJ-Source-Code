#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[20001];
int vis[20001];
int v, e;
bool bvis[20001];

void dfs(int cur, int prevc) {
    if (vis[cur] != 0) return;

    int curc;
    if (prevc == 1) curc = 2;
    else curc = 1;

    vis[cur] = curc;

    for (int nxt : adj[cur]) dfs(nxt, curc);
}

bool bg() {
    for (int i = 1; i <= v; i++) {
        int sz = adj[i].size();
        for (int nxt : adj[i]) {
            if (vis[i] == vis[nxt]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    while (k--) {
        cin >> v >> e;

        while (e--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= v; i++) {
            if (vis[i] == 0) {
                dfs(i, 2);
            }
        }

        if (bg()) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        for (int i = 1; i <= v; i++) adj[i].erase(adj[i].begin(), adj[i].end());
        fill(vis, vis+v+1, 0);
        fill(bvis, bvis+v+1, false);
    }
}