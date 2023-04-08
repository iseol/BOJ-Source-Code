#include <iostream>
#include <vector>
#include <queue>
#define cost first
#define node second
using namespace std;

constexpr int INF = 987654321;

vector<pair<int, int>> adj[1001], radj[1001];
int d[1001], rd[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({t, v});
        radj[v].push_back({t, u});
    }

    fill(d, d+n+1, INF);
    fill(rd, rd+n+1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[x] = 0;
    pq.push({d[x], x});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.node] != cur.cost) continue;

        for (auto nxt : adj[cur.node]) {
            if (d[nxt.node] <= nxt.cost + d[cur.node]) continue;
            d[nxt.node] = d[cur.node] + nxt.cost;
            pq.push({d[nxt.node], nxt.node});
        }
    }

    rd[x] = 0;
    pq.push({rd[x], x});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (rd[cur.node] != cur.cost) continue;

        for (auto nxt : radj[cur.node]) {
            if (rd[nxt.node] <= nxt.cost + rd[cur.node]) continue;
            rd[nxt.node] = rd[cur.node] + nxt.cost;
            pq.push({rd[nxt.node], nxt.node});
        }
    }


    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, d[i]+rd[i]);
    }
    cout << mx;
}