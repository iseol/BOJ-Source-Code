#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

vector<int> adj[500001];
int cash[500001];

int scc[500001];
bool finished[500001];
int d[500001];
stack<int> s;

int id, sid;

set<int> sadj[500001];
int scash[500001];
bool srest[500001];

int deg[500001];

int dfs(int cur) {
    d[cur] = ++id;
    s.push(cur);

    int parent = d[cur];
    for (int nxt : adj[cur]) {
        if (!d[nxt]) parent = min(parent, dfs(nxt));
        else if (!finished[nxt]) parent = min(parent, d[nxt]);
    }

    if (d[cur] == parent) {
        sid++;
        while (1) {
            int t = s.top(); s.pop();
            scc[t] = sid;
            finished[t] = true;
            if (t == cur) break;
        }
    }

    return parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        cash[i] = c;
    }

    int st, p;
    cin >> st >> p;
    dfs(st);

    while (p--) {
        int x;
        cin >> x;
        srest[scc[x]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (scc[i] != 0) scash[scc[i]] += cash[i];
    }

    for (int cur = 1; cur <= n; cur++) {
        for (int nxt : adj[cur]) {
            if (scc[cur] != scc[nxt] && scc[cur] != 0 && scc[nxt] != 0) sadj[scc[cur]].insert(scc[nxt]);
        }
    }

    for (int i = 1; i <= sid; i++) {
        for (int nxt : sadj[i]) deg[nxt]++;        
    }
    //for (int i = 1; i <= sid; i++) cout << deg[i] << ' ';
    //cout << '\n';

    queue<int> q;
    st = scc[st];
    q.push(st);

    int dp[sid+1];
    fill(dp, dp+sid+1, 0);
    dp[st] = scash[st];
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : sadj[cur]) {
            dp[nxt] = max(dp[nxt], dp[cur] + scash[nxt]);
            if (--deg[nxt] == 0) q.push(nxt);
        }
    }

    int ans = -1;
    for (int i = 1; i <= sid; i++) {
        if (srest[i]) ans = max(ans, dp[i]);
    }
    cout << ans;

    /*for (int i = 1; i <= n; i++) cout << scc[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= sid; i++) cout << scash[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= sid; i++) cout << dp[i] << ' ';
    cout << '\n';*/
}