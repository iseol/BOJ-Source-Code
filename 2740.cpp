#include <iostream>
using namespace std;

int a[100][100], b[100][100], ab[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    cin >> m >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> b[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int x = 0; x < m; x++) {
                ab[i][j] += a[i][x] * b[x][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << ab[i][j] << ' ';
        }
        cout << '\n';
    }
}