#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define cost first
#define node second
using namespace std;

constexpr int INF = 987654321;

int d[1001];
int pre[1001];
vector<pair<int, int>> adj[1001]; // cost, vertex

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;
    fill(d, d+v+1, INF);
    fill(pre, pre+v+1, INF);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    
    int st, en;
    cin >> st >> en;
    d[st] = 0;
    pre[st] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.node] != cur.cost) continue;
        for (auto nxt : adj[cur.node]) {
            if (nxt.cost + cur.cost < d[nxt.node]) {
                d[nxt.node] = nxt.cost + cur.cost;
                pre[nxt.node] = cur.node;
                pq.push({nxt.cost + cur.cost, nxt.node});
            }
        }
    }

    cout << d[en] << '\n';
    vector<int> res;
    res.push_back(en);
    while (true) {
        if (pre[en] == 0) break;
        res.push_back(pre[en]);
        en = pre[en];
    }
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';

    for (int x : res) cout << x << ' ';
}