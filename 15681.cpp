#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int c[100001];

void sol(int cur, int p) {
    c[cur] = 1;
    for (int nxt : adj[cur]) {
        if (nxt == p) continue;
        sol(nxt, cur);
        c[cur] += c[nxt];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    int u, v;
    for (int i = 1; i <= n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sol(r, 0);

    int query;
    for (int i = 1; i <= q; i++) {
        cin >> query;
        cout << c[query] << '\n';
    }
}