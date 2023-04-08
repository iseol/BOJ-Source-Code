#include <iostream>
using namespace std;

int a[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % 4 == 0 || i % 4 == 3) {
                    if (j % 4 == 0 || j % 4 == 3) a[i][j] = 1;
                    else a[i][j] = 0;
                }
                else {
                    if (j % 4 == 0 || j % 4 == 3) a[i][j] = 0;
                    else a[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " \n"[j == m-1];
            }
        }
    }
}