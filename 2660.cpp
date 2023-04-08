#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[55];
int dist[55][55]; //dist[i][j]i번째 정점부터(시작해) j번째 정점까지의 거리

int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) fill(dist[i], dist[i]+n+1, -1); //idx?
    while (1) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (dist[i][nxt] != -1) continue;
                dist[i][nxt] = dist[i][cur] + 1;
                q.push(nxt);
            }
        }
    }

    int arr[55]; // 점수
    int temp = -2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp = max(temp, dist[i][j]);
        }
        arr[i] = temp;
        temp = -2;
    }

    int mn = 987654321;
    int res = 0;
    for (int i = 1; i <= n; i++) mn = min(mn, arr[i]);
    for (int i = 1; i <= n; i++) {
        if (arr[i] == mn) res++;
    }

    cout << mn << ' ' << res << '\n';
    for (int i = 1; i <= n; i++) {
        if (arr[i] == mn) cout << i << ' ';
    }

}