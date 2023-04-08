#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 987654321;
int d[101][101];
int items[101]; // 1 based

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) fill(d[i], d[i]+n+1, INF);
    for (int i = 1; i <= n; i++) cin >> items[i];
    while (r--) {
        int a, b, l;
        cin >> a >> b >> l;
        d[a][b] = min(d[a][b], l);
        d[b][a] = min(d[b][a], l);
    }

    for (int i = 1; i <= n; i++) d[i][i] = 0;
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k]+d[k][j]) d[i][j] = d[i][k]+d[k][j];
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (d[i][j] > m) continue;
            tmp += items[j];
        }
        res = max(res, tmp);
    }
    cout << res;
}