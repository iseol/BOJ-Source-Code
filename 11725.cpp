#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100001];
int p[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int u, v;
    for (int i = 1; i <= n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }

    for (int i = 2; i <= n; i++) cout << p[i] << '\n';
}