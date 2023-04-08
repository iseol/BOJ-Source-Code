#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[20002];
bool finished[20002];
int d[20002], sn[20002];
int id = 0, sid = 0;
stack<int> s;

int oppo(int x) { return x&1 ? x+1 : x-1; }

int dfs(int cur) {
    d[cur] = ++id;
    s.push(cur);

    int parent = d[cur];
    for (int nxt : adj[cur]) {
        if (!d[nxt]) parent = min(parent, dfs(nxt));
        else if (!finished[nxt]) parent = min(parent, d[nxt]);
    } 

    if (d[cur] == parent) {
        ++sid;
        while (1) {
            int t = s.top(); s.pop();
            finished[t] = true;
            sn[t] = sid;
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
        int a, b;
        cin >> a >> b;

        if (a > 0) a *= 2;
        else a = (-a)*2-1;
        if (b > 0) b *= 2;
        else b = (-b)*2-1;

        adj[oppo(a)].push_back(b);
        adj[oppo(b)].push_back(a);
    }

    for (int i = 1; i <= 2*n; i++) {
        if (!finished[i]) dfs(i);
    }
    for (int i = 2; i <= 2*n; i+=2) {
        if (sn[i] != 0 && sn[i-1] != 0 && sn[i] == sn[i-1]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}