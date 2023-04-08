#include <iostream>
using namespace std;

constexpr int INF = 987654321;

int d[251][251];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(d[i], d[i]+n+1, INF);
    while (m--) {
        int u, v, b;
        cin >> u >> v >> b;
        if (b == 0) {
            d[u][v] = 0;
            d[v][u] = 1;
        }
        else {
            d[u][v] = 0;
            d[v][u] = 0;
        }
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k]+d[k][j] < d[i][j]) d[i][j] = d[i][k]+d[k][j];
            }
        }
    }
    

    int k;
    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}