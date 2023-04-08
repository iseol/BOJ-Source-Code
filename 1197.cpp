#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<pair<int, int>> adj[10001];
bool check[10001];

int main() {
    int v, e;
    cin >> v >> e;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 1; i <= e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    for (auto nxt : adj[1]) pq.push({nxt.first, 1, nxt.second});
    check[1] = true;
    int cnt = 0;
    int res = 0;
    while (cnt < v-1) {
        int a, b, cost;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (check[b]) continue;
        check[b] = true;
        res += cost;
        cnt++;
        for (auto nxt : adj[b]) {
            if (!check[nxt.second]) pq.push({nxt.first, b, nxt.second});
        }
    }
    cout << res;
}