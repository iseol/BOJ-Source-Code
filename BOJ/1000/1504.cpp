#include <iostream>
#include <vector>
#include <queue>
#define cost first
#define node second
using namespace std;

constexpr int INF = 687654321;
vector<pair<int, int>> adj[801];
int d[801], dv1[801], dv2[801];
// 1, v1, v2번 정점을 시작으로 최단 경로

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> e;
    fill(d, d+n+1, INF);
    fill(dv1, dv1+n+1, INF);
    fill(dv2, dv2+n+1, INF);
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int v1, v2;
    cin >> v1 >> v2;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[1] = 0;
    pq.push({d[1], 1});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.node] != cur.cost) continue;

        for (auto nxt : adj[cur.node]) {
            if (d[nxt.node] <= nxt.cost + d[cur.node]) continue;
            d[nxt.node] = d[cur.node] + nxt.cost;
            pq.push({d[nxt.node], nxt.node});
        }
    }
    dv1[v1] = 0;
    pq.push({dv1[v1], v1});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dv1[cur.node] != cur.cost) continue;

        for (auto nxt : adj[cur.node]) {
            if (dv1[nxt.node] <= nxt.cost + dv1[cur.node]) continue;
            dv1[nxt.node] = dv1[cur.node] + nxt.cost;
            pq.push({dv1[nxt.node], nxt.node});
        }
    }
    dv2[v2] = 0;
    pq.push({dv2[v2], v2});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dv2[cur.node] != cur.cost) continue;

        for (auto nxt : adj[cur.node]) {
            if (dv2[nxt.node] <= nxt.cost + dv2[cur.node]) continue;
            dv2[nxt.node] = dv2[cur.node] + nxt.cost;
            pq.push({dv2[nxt.node], nxt.node});
        }
    }

    // 1 -> v1 -> v2 -> n
    // 1 -> v2 -> v1 -> n
    bool flag1 = true, flag2 = true;

    if (d[v1] == INF || dv1[v2] == INF || dv2[n] == INF) flag1 = false;
    if (d[v2] == INF || dv2[v1] == INF || dv1[n] == INF) flag2 = false;

    int ans;
    if (!flag1 && !flag2) ans = -1;
    else ans = min(d[v1]+dv1[v2]+dv2[n], d[v2]+dv2[v1]+dv1[n]);
    cout << ans;
}