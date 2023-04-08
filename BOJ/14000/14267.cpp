#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
int compliment[100001];
int w;

void dfs(int cur) {
    compliment[cur] += w;
    for (int nxt : adj[cur]) {
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int boss;
        cin >> boss;
        if (i == 1) continue;
        adj[boss].push_back(i);
    }

    while (m--) {
        int i;
        cin >> i >> w;
        dfs(i);
    }

    for (int i = 1; i <= n; i++) cout << compliment[i] << ' ';
}