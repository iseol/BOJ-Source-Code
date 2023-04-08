#include <iostream>
#include <vector>
using namespace std;

vector<int> adj1[100], adj2[100];
bool vis1[100], vis2[100];
int k, res;
int n, m;

void dfs1(int cur) {
    vis1[cur] = true;
    
    for (int nxt : adj1[cur]) {
        if (!vis1[nxt]) {
            k++;
            dfs1(nxt);
        }
    }
}

void dfs2(int cur) {
    vis2[cur] = true;

    for (int nxt : adj2[cur]) {
        if (!vis2[nxt]) {
            k++;
            dfs2(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v); // lighter
        adj2[v].push_back(u); // heavier
    }

    for (int i = 1; i <= n; i++) {
        dfs1(i);

        fill(vis1, vis1+n+1, false);
        if (k >= (n+1)/2) res++;
        k = 0;
    }
    for (int i = 1; i <= n; i++) {
        dfs2(i);

        fill(vis2, vis2+n+1, false);
        if (k >= (n+1)/2) res++;
        k = 0;
    }

    cout << res;
}