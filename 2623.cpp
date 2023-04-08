#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
int deg[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int s, temp1, temp2;
        cin >> s >> temp1;
        s--;
        while (s--) {
            cin >> temp2;
            adj[temp1].push_back(temp2);
            deg[temp2]++;
            temp1 = temp2;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        res.push_back(cur);

        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }

    if (res.size() != n) cout << 0;
    else {
        for (int x : res) cout << x << '\n';
    }
}