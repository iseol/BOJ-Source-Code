#include <iostream>
#include <queue>
using namespace std;

int path[101], dist[101];

int main() {
    fill(dist, dist+101, -1);
    dist[1] = 0;

    int n, m;
    cin >> n >> m;
    while (n--) {
        int u, v;
        cin >> u >> v;
        path[u] = v;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        path[u] = v;
    }

    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 1; i <= 6; i++) {
            if (cur+1 <= 100) {
                if (path[cur+i] != 0) {
                    if (dist[path[cur+i]] == -1) {
                        dist[path[cur+i]] = dist[cur] + 1;
                        q.push(path[cur+i]);
                    }
                }
                else if (dist[cur+i] == -1) {
                    dist[cur+i] = dist[cur] + 1;
                    q.push(cur+i);
                }
            }
        }
    }

    cout << dist[100];
}