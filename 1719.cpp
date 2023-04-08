#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 987654321;
int d[201][201];
int nxt[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fill(d[i], d[i]+n+1, INF);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
        nxt[a][b] = b;
        nxt[b][a] = a;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k]+d[k][j]) {
                    d[i][j] = d[i][k]+d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << nxt[i][j] << ' ';
        }
        cout << '\n';
    }
}