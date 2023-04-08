#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int id;
vector<int> adj[10001];
bool finished[10001];
int d[10001];

vector<vector<int>> scc;
stack<int> s;

bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int dfs(int cur) {
    d[cur] = ++id;
    s.push(cur);

    int parent = d[cur];
    for (int nxt : adj[cur]) {
        if (!d[nxt]) parent = min(parent, dfs(nxt));
        else if (!finished[nxt]) parent = min(parent, d[nxt]);
    }

    if (d[cur] == parent) {
        vector<int> sscc;
        while (1) {
            int t = s.top(); s.pop();
            sscc.push_back(t);
            finished[t] = true;
            if (t == cur) break;
        }
        sort(sscc.begin(), sscc.end());
        scc.push_back(sscc);
    }
    return parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= v; i++) {
        if (!finished[i]) dfs(i);
    }

    sort(scc.begin(), scc.end(), compare);
    cout << scc.size() << '\n';
    for (vector<int> sscc : scc) {
        for (int x : sscc) cout << x << ' ';
        cout << -1 << '\n';
    }
}