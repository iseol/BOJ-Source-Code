#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> adj[100005];
int vis[100005];
int id = 0;

void dfs(int cur) {
    vis[cur] = ++id;

    for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

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

    dfs(r);

    for (int i = 1; i <= n; i++) cout << vis[i] << '\n';
}