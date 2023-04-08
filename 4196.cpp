#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[100001];
int d[100001];
bool finished[100001];
stack<int> s;
int id = 0, sid = 0;

int sn[100001];
int deg[100001];

vector<vector<int>> scc;

int dfs(int cur) {
    d[cur] = ++id;
    s.push(cur);

    int parent = d[cur];
    for (int nxt : adj[cur]) {
        if (!d[nxt]) parent = min(parent, dfs(nxt));
        else if (!finished[nxt]) parent = min(parent, d[nxt]);
    }

    if (d[cur] == parent) {
        vector<int> temp;
        ++sid;
        while (1) {
            int t = s.top(); s.pop();
            temp.push_back(t);
            finished[t] = true;
            sn[t] = sid;
            if (cur == t) break;
        }
        scc.push_back(temp);
    }
    return parent;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            if (!finished[i]) dfs(i);
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j : adj[i]) {
                if (sn[i] != sn[j]) deg[sn[j]]++;
            }   
        }

        int ans = 0;
        for (int i = 1; i <= sid; i++) {
            if (deg[i] == 0) ans++;
        }
        cout << ans << '\n';

        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < sid; i++) scc[i].clear();
        fill(d, d+n+1, 0);
        fill(finished, finished+n+1, false);
        fill(sn, sn+sid+1, 0);
        fill(deg, deg+sid+1, 0);
        id = 0;
        sid = 0;
    }
}