#include <iostream>
using namespace std;

int a[3][100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) a[2][i] = i;
            else a[1][i] = i;
        }

        for (int i = n+1; i <= 2*n-2; i++) {
            if (i % 2 != 0) a[2][i-n+1] = i;
            else a[1][i-n+1] = i;
        }

        a[1][1] = 2*n;
        a[2][n] = 2*n-1;

        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
}