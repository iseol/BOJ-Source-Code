#include <iostream>
using namespace std;

int d[101][10001], v[101], c[101];

int main() {
    int n, m;
    cin >> n >> m;

    int k = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        k += c[i];
    }

    int res = 987654321;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (c[i] <= j) d[i][j] = max(d[i-1][j], d[i-1][j-c[i]]+v[i]);
            else d[i][j] = d[i-1][j];
            if (d[i][j] >= m) res = min(res, j);
        }
    }

    cout << res;
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }*/
}