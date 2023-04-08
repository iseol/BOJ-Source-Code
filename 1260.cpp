#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adj[1005];
bool dvis[1005], bvis[1005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, start;
    cin >> n >> m >> start;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int cur = s.top(); s.pop();
        if (dvis[cur]) continue;
        dvis[cur] = true;
        cout << cur << ' ';
        for (int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][adj[cur].size()-1-i];
            if (dvis[nxt]) continue;
            s.push(nxt);
        }
    }
    cout << '\n';

    queue<int> q;
    bvis[start] = true;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (bvis[nxt]) continue;
            bvis[nxt] = true;
            q.push(nxt);
        }
    }
}