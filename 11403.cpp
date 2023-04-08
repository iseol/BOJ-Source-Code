#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101];
bool vis[101][101];

void dfs(int cur, int st) {
    if (vis[st][cur]) return;
    vis[st][cur] = true;
    for (int nxt : adj[cur]) dfs(nxt, st);
}

int main() {
    int n;
    cin >> n;

    bool temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            if (temp) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int nxt : adj[i]) dfs(nxt, i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
}