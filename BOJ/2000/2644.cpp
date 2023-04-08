#include <iostream>
#include <vector>
using namespace std;

int dist[101][101];
vector<int> adj[101];

void dfs(int cur, int st) {
    for (int nxt : adj[cur]) {
        if (dist[st][nxt] != -1) continue;
        dist[st][nxt] = dist[st][cur] + 1;
        dfs(nxt, st);
    }
}

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;
    
    for (int i = 1; i <= n; i++) fill(dist[i], dist[i]+n+1, -1);

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        dfs(i, i);
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << dist[i][j] << ' ';
        cout << '\n';
    }*/
    cout << dist[a][b];
}